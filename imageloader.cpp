#include "imageloader.h"
#include <iostream>

Image::Image(char* ps, int w, int h) : pixels(ps), width(w), height(h) {
}

Image::~Image() {
    delete[] pixels;
}

namespace {
    int toInt(const char* bytes) {
        return (int)((unsigned char)bytes[3] << 24 |
                     (unsigned char)bytes[2] << 16 |
                     (unsigned char)bytes[1] << 8 |
                     (unsigned char)bytes[0]);
    }

    short toShort(const char* bytes) {
        return (short)((unsigned char)bytes[1] << 8 | (unsigned char)bytes[0]);
    }

    int readInt(ifstream &input) {
        char buffer[4];
        input.read(buffer, 4);
        return toInt(buffer);
    }

    short readShort(ifstream &input) {
        char buffer[2];
        input.read(buffer, 2);
        return toShort(buffer);
    }

    template<class T>
    class auto_array {
    private:
        T* array;
        mutable bool isReleased;
    public:
        explicit auto_array(T* array_ = NULL) :
            array(array_), isReleased(false) {
        }

        auto_array(const auto_array<T> &aarray) {
            array = aarray.array;
            isReleased = aarray.isReleased;
            aarray.isReleased = true;
        }

        ~auto_array() {
            if (!isReleased && array != NULL) {
                delete[] array;
            }
        }

        T* get() const {
            return array;
        }

        T &operator*() const {
            return *array;
        }

        void operator=(const auto_array<T> &aarray) {
            if (!isReleased && array != NULL) {
                delete[] array;
            }
            array = aarray.array;
            isReleased = aarray.isReleased;
            aarray.isReleased = true;
        }

        T* operator->() const {
            return array;
        }

        T* release() {
            isReleased = true;
            return array;
        }

        void reset(T* array_ = NULL) {
            if (!isReleased && array != NULL) {
                delete[] array;
            }
            array = array_;
        }

        T* operator+(int i) {
            return array + i;
        }

        T &operator[](int i) {
            return array[i];
        }
    };
}

Image* loadBMP(const char* filename) {
    ifstream input;
    input.open(filename, ifstream::binary);
    if (input.fail()) {
        cout << "File not found: " << filename << endl;
        return NULL;
    }

    char buffer[2];
    input.read(buffer, 2);
    if (buffer[0] != 'B' || buffer[1] != 'M') {
        cout << "Not a BMP file: " << filename << endl;
        return NULL;
    }

    input.ignore(8);
    int dataOffset = readInt(input);

    int headerSize = readInt(input);
    int width;
    int height;
    switch (headerSize) {
    case 40:
        width = readInt(input);
        height = readInt(input);
        input.ignore(2);
        if (readShort(input) != 24) {
            cout << "Not a 24-bit BMP file: " << filename << endl;
            return NULL;
        }
        if (readShort(input) != 0) {
            cout << "Compressed BMP file: " << filename << endl;
            return NULL;
        }
        break;
    default:
        cout << "Unsupported BMP format: " << filename << endl;
        return NULL;
    }

    int bytesPerRow = ((24 * width + 31) / 32) * 4;
    int size = bytesPerRow * height;
    auto_array<char> pixels(new char[size]);
    input.seekg(dataOffset, ios_base::beg);
    input.read(pixels.get(), size);

    auto_array<char> pixels2(new char[width * height * 3]);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < 3; c++) {
                pixels2[3 * (width * y + x) + c] =
                    pixels[bytesPerRow * y + 3 * x + (2 - c)];
            }
        }
    }

    input.close();
    return new Image(pixels2.release(), width, height);
}
