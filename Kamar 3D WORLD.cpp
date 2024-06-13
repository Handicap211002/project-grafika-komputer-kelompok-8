#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include "imageloader.h"


float angleX = 0.0f;
float angleY = 0.0f;
float mouseSensitivity = -0.1f; 
int lastX = -1;
int lastY = -1;
int windowWidth = 500;
int windowHeight = 500;
bool isFirstMouse = true;
bool lightOn = true;

GLuint tekstur;

#pragma pack(push, 1)
typedef struct {
    unsigned char signature[2];
    unsigned int fileSize;
    unsigned int reserved;
    unsigned int dataOffset;
} BMPFileHeader;

typedef struct {
    unsigned int size;
    int width;
    int height;
    unsigned short planes;
    unsigned short bitCount;
    unsigned int compression;
    unsigned int imageSize;
    int xPixelsPerMeter;
    int yPixelsPerMeter;
    unsigned int colorsUsed;
    unsigned int importantColors;
} BMPInfoHeader;
#pragma pack(pop)

GLuint MuatTekstur(const char *filename) {
    GLuint tekstur;
    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;
    unsigned char *data;
    FILE *file;

    // Membaca file BMP
    file = fopen(filename, "rb");
    if (file == NULL) return 0;

    // Membaca header file BMP
    fread(&fileHeader, sizeof(BMPFileHeader), 1, file);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, file);

    // Mendapatkan ukuran gambar
    int lebar = infoHeader.width;
    int tinggi = infoHeader.height;

    // Membaca data gambar
    data = (unsigned char *)malloc(lebar * tinggi * 3);
    fseek(file, fileHeader.dataOffset, SEEK_SET);
    fread(data, lebar * tinggi * 3, 1, file);
    fclose(file);

    // Membuat tekstur baru
    glGenTextures(1, &tekstur);
    glBindTexture(GL_TEXTURE_2D, tekstur);

    // Set parameter tekstur
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, lebar, tinggi, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);
    
    free(data);

    return tekstur;
}
GLuint loadTexture(Image* image) {
    GLuint textureId;
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    return textureId;
}
GLuint MuatTekstur(const char* filename);
GLuint teksturLantai;
GLuint teksturLantaii;
GLuint teksturDinding;
GLuint teksturDindingg;
GLuint alasmeja;
GLuint selimut;
GLuint selimutt;
GLuint kayu;
GLuint marmerp;
GLuint marmerh;

// Fungsi untuk menangani pergerakan mouse
void mouseMotion(int x, int y) {
    if (isFirstMouse) {
        lastX = x;
        lastY = y;
        isFirstMouse = false;
    }

    int deltaX = x - lastX;
    int deltaY = y - lastY;

    angleY += deltaX * mouseSensitivity;
    angleX += deltaY * mouseSensitivity;

    // Batasi pitch untuk mencegah "over-rotation"
    if (angleX > 89.0f)
        angleX = 89.0f;
    if (angleX < -89.0f)
        angleX = -89.0f;

    lastX = x;
    lastY = y;
    glutWarpPointer(windowWidth / 2, windowHeight / 2);

    glutPostRedisplay();
}

    //deklarasi fungsi
    void display();
    void init();
    void reshape(int, int);
    void keyboard(unsigned char, int, int); //+1
    //main program
    int main (int argc, char** argv){
    //inisialisasi
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); //+2 GLUT_DEPTH : mengalokasikan sumbu z
    glutInitWindowPosition(200, 100); //atur sumbu x dan y
    glutInitWindowSize(500, 500); //atur lebar dan tinggi jendela
    glutCreateWindow("Kelompok 8");
    glutDisplayFunc(display); //memanggil fungsi display
    glutReshapeFunc(reshape); //memanggil fungsi reshape
    glutKeyboardFunc(keyboard); // +3 memanggil fungsi keyboard
    glutMotionFunc(mouseMotion);
    glutPassiveMotionFunc(mouseMotion);
    glutWarpPointer(windowWidth / 2, windowHeight / 2);
    init();
    glutMainLoop(); //looping program utama
    }

    void init() {
    glEnable(GL_TEXTURE_2D);
    // Muat dan ikat tekstur 
    teksturLantai = MuatTekstur("lantai.bmp");
    teksturLantaii = MuatTekstur("lantaii.bmp");
    teksturDindingg = MuatTekstur("dindingg.bmp");
    teksturDinding = MuatTekstur("dinding.bmp");
    alasmeja = MuatTekstur("alasmeja.bmp");
    selimut = MuatTekstur("selimut.bmp");
    selimutt = MuatTekstur("selimutt.bmp");
    kayu = MuatTekstur("kayu.bmp");
    marmerp = MuatTekstur("marmerputih.bmp");
    marmerh = MuatTekstur("marmerhitam.bmp");

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL); // Mengaktifkan pelacakan warna material

    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE); // Mengatur properti material untuk mengikuti nilai glColor

    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Inisialisasi cahaya ambient
    GLfloat ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

    // Inisialisasi sumber cahaya
    GLfloat diffuseLight[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Warna cahaya difus 
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);

    GLfloat specularLight[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Warna cahaya spekular 
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);

    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.5f); // Pengaturan atenuasi untuk membuat cahaya lebih terang
}
    void display(){
//reset
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //+5

    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);

    GLfloat lightPos[] = { -16.0f, 10.0f, 15.0f, 1.0f }; // Posisi cahaya sesuai koordinat yang diberikan
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    glPushMatrix();
    glTranslatef(-16.0f, 10.0f, 15.0f); // Posisikan bola di tempat yang sama dengan sumber cahaya
    glColor3f(1.0f, 1.0f, 0.0f); // Warna bola kuning
    glutSolidSphere(0.5, 20, 20); // Gambar bola yang lebih besar
    glPopMatrix();
    
 //alas
    //depan
    glBegin(GL_QUADS); //+8
    glColor3ub(184, 178, 178);
    glVertex3f(-15.0, -5.0, 13.0);
    glVertex3f(-15.0, -6.0, 13.0);
    glVertex3f(15.0, -6.0, 13.0);
    glVertex3f(15.0, -5.0, 13.0);
    glEnd();
    //belakang
    glBegin(GL_QUADS); //+8
    glColor3ub(204, 196, 196);
    glVertex3f(-15.0, -5.0, -10.0);
    glVertex3f(-15.0, -6.0, -10.0);
    glVertex3f(15.0, -6.0, -10.0);
    glVertex3f(15.0, -5.0, -10.0);
    glEnd();
    //atas

    glBindTexture(GL_TEXTURE_2D, teksturLantaii);
    glBegin(GL_QUADS);  
    glColor3f(1.0f, 1.0f, 1.0f);
    // Definisikan koordinat tekstur dan vertex
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-15.0, -5.0, -10.0);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-15.0, -5.0, 13.0);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(15.0, -5.0, 13.0);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(15.0, -5.0, -10.0);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    
    //bawah
    glBegin(GL_QUADS); //+8
    glColor3ub(204, 196, 196);
    glVertex3f(-15.0, -6.0, -10.0);
    glVertex3f(-15.0, -6.0, 13.0);
    glVertex3f(15.0, -6.0, 13.0);
    glVertex3f(15.0, -6.0, -10.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS); //+8
    glColor3ub(204, 196, 196);
    glVertex3f(15.0, -5.0, 13.0);
    glVertex3f(15.0, -6.0, 13.0);
    glVertex3f(15.0, -6.0, -10.0);
    glVertex3f(15.0, -5.0, -10.0);
    glEnd();

//tembok panjang
    //depan
    glBindTexture(GL_TEXTURE_2D, teksturLantai);
    glBegin(GL_QUADS); 
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS); //+8
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-15.0, 8.0, -10.0);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-15.0, -6.0, -10.0);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(15.0, -6.0, -10.0);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(15.0, 8.0, -10.0);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    //belakang
    glBegin(GL_QUADS); //+8
    glColor3ub(197, 198, 198);
    glVertex3f(-15.0, 8.0, -11.0);
    glVertex3f(-15.0, -6.0, -11.0);
    glVertex3f(15.0, -6.0, -11.0);
    glVertex3f(15.0, 8.0, -11.0);
    glEnd();
    //atas
    glBegin(GL_QUADS); //+8
    glColor3ub(197, 198, 198);
    glVertex3f(-15.0, 8.0, -11.0);
    glVertex3f(-15.0, 8.0, -10.0);
    glVertex3f(15.0, 8.0, -10.0);
    glVertex3f(15.0, 8.0, -11.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS); //+8
    glColor3ub(197, 198, 198);
    glVertex3f(15.0, 8.0, -10.0);
    glVertex3f(15.0, -6.0, -10.0);
    glVertex3f(15.0, -6.0, -11.0);
    glVertex3f(15.0, 8.0, -11.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS); //+8
    glColor3ub(197, 198, 198);
    glVertex3f(-15.0, 8.0, -11.0);
    glVertex3f(-15.0, -6.0, -11.0);
    glVertex3f(-15.0, -6.0, -10.0);
    glVertex3f(-15.0, 8.0, -10.0);
    glEnd();

//tembok kiri

    glBindTexture(GL_TEXTURE_2D, teksturLantai);
    glBegin(GL_QUADS);  
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS); //+8
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-15.0, 8.0, -11.0);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-15.0, -6.0, -11.0);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-15.0, -6.0, 13.0);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-15.0, 8.0, 13.0);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);

    //belakang
    glBegin(GL_QUADS); //+8
    glColor3ub(197, 198, 198);
    glVertex3f(-16.0, 8.0, -11.0);
    glVertex3f(-16.0, -6.0, -11.0);
    glVertex3f(-16.0, -6.0, 13.0);
    glVertex3f(-16.0, 8.0, 13.0);
    glEnd();
    //atas
    glBegin(GL_QUADS); //+8
    glColor3ub(197, 198, 198);
    glVertex3f(-16.0, 8.0, -11.0);
    glVertex3f(-15.0, 8.0, -11.0);
    glVertex3f(-15.0, 8.0, 13.0);
    glVertex3f(-16.0, 8.0, 13.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS); //+8
    glColor3ub(220, 211, 211);
    glVertex3f(-15.0, 8.0, -11.0);
    glVertex3f(-15.0, -6.0, -11.0);
    glVertex3f(-16.0, -6.0, -11.0);
    glVertex3f(-16.0, 8.0, -11.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS); //+8
    glColor3ub(220, 211, 211);
    glVertex3f(-15.0, 8.0, 13.0);
    glVertex3f(-15.0, -6.0, 13.0);
    glVertex3f(-16.0, -6.0, 13.0);
    glVertex3f(-16.0, 8.0, 13.0);
    glEnd();
    

//tempat tidur
    //kayu1
    //depan
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(-15.0, 2.0, -1.7); 
    glVertex3f(-15.0, -5.0, -1.7);
    glVertex3f(-13.5, -5.0, -1.7);
    glVertex3f(-13.5, 2.0, -1.7);
    glEnd();
    //belakang
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(-15.0, 2.0, -3.2); 
    glVertex3f(-15.0, -5.0, -3.2);
    glVertex3f(-13.5, -5.0, -3.2);
    glVertex3f(-13.5, 2.0, -3.2);
    glEnd();
    //atas
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(-15.0, 2.0, -1.7); 
    glVertex3f(-15.0, 2.0, -3.2);
    glVertex3f(-13.5, 2.0, -3.2);
    glVertex3f(-13.5, 2.0, -1.7);
    glEnd();
    //kanan
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(-13.5, 2.0, -1.7); 
    glVertex3f(-13.5, -5.0, -1.7);
    glVertex3f(-13.5, -5.0, -3.2);
    glVertex3f(-13.5, 2.0, -3.2);
    glEnd();
    //penyambung
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(-13.5, -1.5, -1.7); 
    glVertex3f(-13.5, -3.5, -1.7);
    glVertex3f(1.0, -3.5, -1.7);
    glVertex3f(1.0, -1.5, -1.7);
    glEnd();

//kayu2
    //depan
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(1.0, 2.0, -1.7); 
    glVertex3f(1.0, -5.0, -1.7);
    glVertex3f(2.5, -5.0, -1.7);
    glVertex3f(2.5, 2.0, -1.7);
    glEnd();
    //belakang
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(1.0, 2.0, -3.2); 
    glVertex3f(1.0, -5.0, -3.2);
    glVertex3f(2.5, -5.0, -3.2);
    glVertex3f(2.5, 2.0, -3.2);
    glEnd();
    //atas
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(1.0, 2.0, -1.7);
    glVertex3f(1.0, 2.0, -3.2);
    glVertex3f(2.5, 2.0, -3.2);
    glVertex3f(2.5, 2.0, -1.7);
    glEnd();
    //kanan
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(2.5, 2.0, -1.7); 
    glVertex3f(2.5, -5.0, -1.7);
    glVertex3f(2.5, -5.0, -3.2);
    glVertex3f(2.5, 2.0, -3.2);
    glEnd();
    //kiri
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(1.0, 2.0, -1.7); 
    glVertex3f(1.0, -5.0, -1.7);
    glVertex3f(1.0, -5.0, -3.2);
    glVertex3f(1.0, 2.0, -3.2);
    glEnd();
    //penyambung
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(2.5, 1.0, -3.2); 
    glVertex3f(2.5, -3.5, -3.2);
    glVertex3f(2.5, -3.5, -7.7);
    glVertex3f(2.5, 1.0, -7.7);
    glEnd();

//kayu3
    //depan
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(1.0, 2.0, -7.7); 
    glVertex3f(1.0, -5.0, -7.7);
    glVertex3f(2.5, -5.0, -7.7);
    glVertex3f(2.5, 2.0, -7.7);
    glEnd();
    //belakang
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(1.0, 2.0, -9.2); 
    glVertex3f(1.0, -5.0, -9.2);
    glVertex3f(2.5, -5.0, -9.2);
    glVertex3f(2.5, 2.0, -9.2);
    glEnd();
    //atas
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(1.0, 2.0, -7.7); 
    glVertex3f(1.0, 2.0, -9.2);
    glVertex3f(2.5, 2.0, -9.2);
    glVertex3f(2.5, 2.0, -7.7);
    glEnd();
    //kanan
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(2.5, 2.0, -7.7); 
    glVertex3f(2.5, -5.0, -7.7);
    glVertex3f(2.5, -5.0, -9.2);
    glVertex3f(2.5, 2.0, -9.2);
    glEnd();
    //kiri
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(1.0, 2.0, -7.7); 
    glVertex3f(1.0, -5.0, -7.7);
    glVertex3f(1.0, -5.0, -9.2);
    glVertex3f(1.0, 2.0, -9.2);
    glEnd();
    //penyambung
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(-13.5, -1.5, -9.2); 
    glVertex3f(-13.5, -3.5, -9.2);
    glVertex3f(1.0, -3.5, -9.2);
    glVertex3f(1.0, -1.5, -9.2);
    glEnd();

//kayu4
    //depan
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(-15.0, 2.0, -7.7);  
    glVertex3f(-15.0, -5.0, -7.7);
    glVertex3f(-13.5, -5.0, -7.7);
    glVertex3f(-13.5, 2.0, -7.7);
    glEnd();
    //belakang
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(-15.0, 2.0, -9.2);  
    glVertex3f(-15.0, -5.0, -9.2);
    glVertex3f(-13.5, -5.0, -9.2);
    glVertex3f(-13.5, 2.0, -9.2);
    glEnd();
    //atas
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(-15.0, 2.0, -7.7);  
    glVertex3f(-15.0, 2.0, -9.2);
    glVertex3f(-13.5, 2.0, -9.2);
    glVertex3f(-13.5, 2.0, -7.7);
    glEnd();
    //kanan
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(-13.5, 2.0, -7.7);  
    glVertex3f(-13.5, -5.0, -7.7);
    glVertex3f(-13.5, -5.0, -9.2);
    glVertex3f(-13.5, 2.0, -9.2);
    glEnd();
    //penyambung
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(-14.5, 1.0, -2.5);  
    glVertex3f(-14.5, -3.5, -2.5);
    glVertex3f(-14.5, -3.5, -7.7);
    glVertex3f(-14.5, 1.0, -7.7);
    glEnd();

//kasur
    //belakang
    //selimut
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 1);
    glVertex3f(-10.0, 0.0, -9.2); 
    glVertex3f(-10.0, -1.5, -9.2);
    glVertex3f(1.0, -1.5, -9.2);
    glVertex3f(1.0, 0.0, -9.2);
    glEnd();
    //depan

    glBindTexture(GL_TEXTURE_2D, selimut);
    glBegin(GL_QUADS);  
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS); //+8
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, -1.7);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, -1.5, -1.7);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0, -1.5, -1.7);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0, 0.0, -1.7);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);

    //atas
    glBindTexture(GL_TEXTURE_2D, selimut);
    glBegin(GL_QUADS);  
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS); //+8
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, -9.2);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 0.0, -1.7);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0, 0.0, -1.7);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0, 0.0, -9.2);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    
    //bantal
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(-14.5, 0.0, -9.2); 
    glVertex3f(-14.5, -1.5, -9.2);
    glVertex3f(-10.0, -1.5, -9.2);
    glVertex3f(-10.0, 0.0, -9.2);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(-14.5, 0.0, -1.7); 
    glVertex3f(-14.5, -1.5, -1.7);
    glVertex3f(-10.0, -1.5, -1.7);
    glVertex3f(-10.0, 0.0, -1.7);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(-14.5, 0.0, -9.2); 
    glVertex3f(-14.5, 0.0, -1.7);
    glVertex3f(-10.0, 0.0, -1.7);
    glVertex3f(-10.0, 0.0, -9.2);
    glEnd();
//meja (lemari)
    //depan

    glBindTexture(GL_TEXTURE_2D, alasmeja);
    glBegin(GL_QUADS);  
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS); //+8
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-15.0, 0.5, 3.0);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-15.0, -5.0, 3.0);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-11.5, -5.0, 3.0);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-11.5, 0.5, 3.0);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);

//belakang

    glBindTexture(GL_TEXTURE_2D, alasmeja);
    glBegin(GL_QUADS);  
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS); //+8
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-15.0, 0.5, -0.5);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-15.0, -5.0, -0.5);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-11.5, -5.0, -0.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-11.5, 0.5, -0.5);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);

    //atas
    glBegin(GL_QUADS); //+8
    glColor3ub(255, 229, 204);
    glVertex3f(-15.0, 0.5, 3.0);
    glVertex3f(-15.0, 0.5, -0.5);
    glVertex3f(-11.5, 0.5, -0.5);
    glVertex3f(-11.5, 0.5, 3.0);
    glEnd();
    //kanan

    glBindTexture(GL_TEXTURE_2D, alasmeja);
    glBegin(GL_QUADS);  
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS); //+8
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-11.5, 0.5, 3.0);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-11.5, -5.0, 3.0);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-11.5, -5.0, -0.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-11.5, 0.5, -0.5);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);

//meja tiang sendiri
    //depan

    glBindTexture(GL_TEXTURE_2D, alasmeja);

    glBegin(GL_QUADS);  
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS); //+8
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-15.0, 0.5, 7.5);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-15.0, -5.0, 7.5);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-11.5, -5.0, 7.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-11.5, 0.5, 7.5);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);

    //belakang
    glBegin(GL_QUADS); //+8
    glColor3ub(255, 229, 204);
    glVertex3f(-15.0, 0.5, 7.0);
    glVertex3f(-15.0, -5.0, 7.0);
    glVertex3f(-11.5, -5.0, 7.0);
    glVertex3f(-11.5, 0.5, 7.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS); //+8
    glColor3ub(0, 0, 0);
    glVertex3f(-11.5, 0.5, 7.5);
    glVertex3f(-11.5, -5.0, 7.5);
    glVertex3f(-11.5, -5.0, 7.0);
    glVertex3f(-11.5, 0.5, 7.0);
    glEnd();

//alas meja
    //atas

    glBindTexture(GL_TEXTURE_2D, alasmeja);
    glBegin(GL_QUADS);  // alas meja
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS); //+8
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-15.0, 1.0, 7.5);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-15.0, 1.0, -0.5);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-11.5, 1.0, -0.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-11.5, 1.0, 7.5);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    
    //bawah
        glBegin(GL_QUADS); //+8
    glColor3ub(255, 229, 204);
    glVertex3f(-15.0, 0.5, 7.5);
    glVertex3f(-15.0, 0.5, -0.5);
    glVertex3f(-11.5, 0.5, -0.5);
    glVertex3f(-11.5, 0.5, 7.5);
    glEnd();
    //depan
    glBegin(GL_QUADS); //+8
    glColor3ub(0, 0, 0);
    glVertex3f(-15.0, 1.0, 7.5);
    glVertex3f(-15.0, 0.5, 7.5);
    glVertex3f(-11.5, 0.5, 7.5);
    glVertex3f(-11.5, 1.0, 7.5);
    glEnd();

    //belakang
    glBegin(GL_QUADS); //+8
    glColor3ub(0, 0, 0);
    glVertex3f(-15.0, 1.0, -0.5);
    glVertex3f(-15.0, 0.5, -0.5);
    glVertex3f(-11.5, 0.5, -0.5);
    glVertex3f(-11.5, 1.0, -0.5);
    glEnd();
    //kanan
    glBegin(GL_QUADS); //+8
    glColor3ub(0, 0, 0);
    glVertex3f(-11.5, 1.0, 7.5);
    glVertex3f(-11.5, 0.5, 7.5);
    glVertex3f(-11.5, 0.5, -0.5);
    glVertex3f(-11.5, 1.0, -0.5);
    glEnd();

//kursi
    //kaki 1
     //depan
    glBegin(GL_QUADS); //+8
    glColor3ub(102, 51, 0);
    glVertex3f(-13.20, -2.5, 6.2);
    glVertex3f(-13.20, -5.0, 6.2);
    glVertex3f(-12.80, -5.0, 6.2);
    glVertex3f(-12.80, -2.5, 6.2);
    glEnd();
     //belakang
    glBegin(GL_QUADS); //+8
    glColor3ub(102, 51, 0);
    glVertex3f(-13.20, -2.5, 5.7);
    glVertex3f(-13.20, -5.0, 5.7);
    glVertex3f(-12.80, -5.0, 5.7);
    glVertex3f(-12.80, -2.5, 5.7);
    glEnd();
     //kanan
    glBegin(GL_QUADS); //+8
    glColor3ub(102, 51, 0);
    glVertex3f(-12.80, -2.5, 6.2);
    glVertex3f(-12.80, -5.0, 6.2);
    glVertex3f(-12.80, -5.0, 5.7);
    glVertex3f(-12.80, -2.5, 5.7);
    glEnd();
    //kiri
    glBegin(GL_QUADS); //+8
    glColor3ub(102, 51, 0);
    glVertex3f(-13.20, -2.5, 6.2);
    glVertex3f(-13.20, -5.0, 6.2);
    glVertex3f(-13.20, -5.0, 5.7);
    glVertex3f(-13.20, -2.5, 5.7);
    glEnd();
    //kaki 2
     //depan
    glBegin(GL_QUADS); //+8
    glColor3ub(102, 51, 0);
    glVertex3f(-13.20, -2.5, 4.7);
    glVertex3f(-13.20, -5.0, 4.7);
    glVertex3f(-12.80, -5.0, 4.7);
    glVertex3f(-12.80, -2.5, 4.7);
    glEnd();
    //belakang
    glBegin(GL_QUADS); //+8
    glColor3ub(102, 51, 0);
    glVertex3f(-13.20, -2.5, 4.2);
    glVertex3f(-13.20, -5.0, 4.2);
    glVertex3f(-12.80, -5.0, 4.2);
    glVertex3f(-12.80, -2.5, 4.2);
    glEnd();
    //kanan
    glBegin(GL_QUADS); //+8
    glColor3ub(102, 51, 0);
    glVertex3f(-12.80, -2.5, 4.7);
    glVertex3f(-12.80, -5.0, 4.7);
    glVertex3f(-12.80, -5.0, 4.2);
    glVertex3f(-12.80, -2.5, 4.2);
    glEnd();
    //kiri
    glBegin(GL_QUADS); //+8
    glColor3ub(102, 51, 0);
    glVertex3f(-13.20, -2.5, 4.7);
    glVertex3f(-13.20, -5.0, 4.7);
    glVertex3f(-13.20, -5.0, 4.2);
    glVertex3f(-13.20, -2.5, 4.2);
    glEnd();
    //kaki 3
     //depan
    glBegin(GL_QUADS); //+8
    glColor3ub(102, 51, 0);
    glVertex3f(-9.80, 3.0, 6.2);
    glVertex3f(-9.80, -5.0, 6.2);
    glVertex3f(-9.30, -5.0, 6.2);
    glVertex3f(-9.30, 3.0, 6.2);
    glEnd();
    //belakang
    glBegin(GL_QUADS); //+8
    glColor3ub(102, 51, 0);
    glVertex3f(-9.80, 3.0, 5.7);
    glVertex3f(-9.80, -5.0, 5.7);
    glVertex3f(-9.30, -5.0, 5.7);
    glVertex3f(-9.30, 3.0, 5.7);
    glEnd();
     //kanan
    glBegin(GL_QUADS); //+8
    glColor3ub(102, 51, 0);
    glVertex3f(-9.30, 3.0, 6.2);
    glVertex3f(-9.30, -5.0, 6.2);
    glVertex3f(-9.30, -5.0, 5.7);
    glVertex3f(-9.30, 3.0, 5.7);
    glEnd();
    //kiri
    glBegin(GL_QUADS); //+8
    glColor3ub(102, 51, 0);
    glVertex3f(-9.80, 3.0, 6.2);
    glVertex3f(-9.80, -5.0, 6.2);
    glVertex3f(-9.80, -5.0, 5.7);
    glVertex3f(-9.80, 3.0, 5.7);
    glEnd();
    //atas
    glBegin(GL_QUADS); //+8
    glColor3ub(0, 0, 0);
    glVertex3f(-9.80, 3.0, 6.2);
    glVertex3f(-9.80, 3.0, 5.7);
    glVertex3f(-9.30, 3.0, 5.7);
    glVertex3f(-9.30, 3.0, 6.2);
    glEnd();
     
    //kaki 4
    //depan
    glBegin(GL_QUADS); //+8
    glColor3ub(102, 51, 0);
    glVertex3f(-9.80, 3.0, 4.7);
    glVertex3f(-9.80, -5.0, 4.7);
    glVertex3f(-9.30, -5.0, 4.7);
    glVertex3f(-9.30, 3.0, 4.7);
    glEnd();
    //belakang
    glBegin(GL_QUADS); //+8
    glColor3ub(102, 51, 0);
    glVertex3f(-9.80, 3.0, 4.2);
    glVertex3f(-9.80, -5.0, 4.2);
    glVertex3f(-9.30, -5.0, 4.2);
    glVertex3f(-9.30, 3.0, 4.2);
    glEnd();
     //kanan
    glBegin(GL_QUADS); //+8
    glColor3ub(102, 51, 0);
    glVertex3f(-9.30, 3.0, 4.7);
    glVertex3f(-9.30, -5.0, 4.7);
    glVertex3f(-9.30, -5.0, 4.2);
    glVertex3f(-9.30, 3.0, 4.2);
    glEnd();
    //kiri
    glBegin(GL_QUADS); //+8
    glColor3ub(102, 51, 0);
    glVertex3f(-9.80, 3.0, 4.7);
    glVertex3f(-9.80, -5.0, 4.7);
    glVertex3f(-9.80, -5.0, 4.2);
    glVertex3f(-9.80, 3.0, 4.2);
    glEnd();
    //atas
    glBegin(GL_QUADS); //+8
    glColor3ub(0, 0, 0);
    glVertex3f(-9.80, 3.0, 4.7);
    glVertex3f(-9.80, 3.0, 4.2);
    glVertex3f(-9.30, 3.0, 4.2);
    glVertex3f(-9.30, 3.0, 4.7);
    glEnd();
    //tulang depan bawah
    //tulang belakang bawah
    //tulang atas senderan
    //atas
    glBegin(GL_QUADS); //+8
    glColor3ub(102, 51, 0);
    glVertex3f(-9.80, 3.0, 6.2);
    glVertex3f(-9.80, 3.0, 4.2);
    glVertex3f(-9.30, 3.0, 4.2);
    glVertex3f(-9.30, 3.0, 6.2);
    glEnd();
    //bawah
        glBegin(GL_QUADS); //+8
    glColor3ub(102, 51, 0);
    glVertex3f(-9.80, -1.5, 6.2);
    glVertex3f(-9.80, -1.5, 4.2);
    glVertex3f(-9.30, -1.5, 4.2);
    glVertex3f(-9.30, -1.5, 6.2);
    glEnd();
    //kanan
    glBegin(GL_QUADS); //+8
    glColor3ub(102, 51, 0);
    glVertex3f(-9.30, 3.0, 6.2);
    glVertex3f(-9.30, -1.5, 6.2);
    glVertex3f(-9.30, -1.5, 4.2);
    glVertex3f(-9.30, 3.0, 4.2);
    glEnd();
    //kiri
    glBegin(GL_QUADS); //+8
    glColor3ub(102, 51, 0);
    glVertex3f(-9.80, 3.0, 6.2);
    glVertex3f(-9.80, -1.5, 6.2);
    glVertex3f(-9.80, -1.5, 4.2);
    glVertex3f(-9.80, 3.0, 4.2);
    glEnd();
//dudukan kuris(alas)
    //atas
    glBegin(GL_QUADS); //+8
    glColor3ub(102, 51, 0);
    glVertex3f(-13.20, -2.0, 6.2);
    glVertex3f(-13.20, -2.0, 4.2);
    glVertex3f(-9.30, -2.0, 4.2);
    glVertex3f(-9.30, -2.0, 6.2);
    glEnd();
    //bawah
        glBegin(GL_QUADS); //+8
    glColor3ub(102, 51, 0);
    glVertex3f(-13.20, -2.5, 6.2);
    glVertex3f(-13.20, -2.5, 4.2);
    glVertex3f(-9.30, -2.5, 4.2);
    glVertex3f(-9.30, -2.5, 6.2);
    glEnd();
    //depan
    glBegin(GL_QUADS); //+8
    glColor3ub(102, 51, 0);
    glVertex3f(-13.20, -2.5, 6.2);
    glVertex3f(-13.20, -2.0, 6.2);
    glVertex3f(-9.80, -2.0, 6.2);
    glVertex3f(-9.80, -2.5, 6.2);
    glEnd();

    //belakang
    glBegin(GL_QUADS); //+8
    glColor3ub(102, 51, 0);
    glVertex3f(-13.20, -2.5, 4.2);
    glVertex3f(-13.20, -2.0, 4.2);
    glVertex3f(-9.80, -2.0, 4.2);
    glVertex3f(-9.80, -2.5, 4.2);
    glEnd();
    //kanan
    glBegin(GL_QUADS); //+8
    glColor3ub(102, 51, 0);
    glVertex3f(-9.30, -2.5, 6.2);
    glVertex3f(-9.30, -2.0, 4.2);
    glVertex3f(-9.30, -2.0, 6.2);
    glVertex3f(-9.30, -2.5, 4.2);
    glEnd();
    

glFlush();
glutSwapBuffers();
}//fungsi untuk setting viewport
void reshape(int w, int h){
 glViewport(0,0, (GLsizei)w, (GLsizei)h); //membuat viewport sesuai ukuran jendela
 glMatrixMode(GL_PROJECTION); //merubah matrix mode menjadi gl_projection
 glLoadIdentity(); //reset transformasi misalnya rotasi pada display
 gluPerspective(30.0, w / h, 1.0, 100.0); //proyeksi perspektif
/* set initial position */
glTranslatef(0.0, -5.0, -100.0);
 glMatrixMode(GL_MODELVIEW); //merubah matrix mode menjadi gl_modelview

}

void keyboard(unsigned char key, int x, int y)
{

switch (key)
{
case 'a':
 case 'A':
 glTranslated(1.0, 0.0, 0.0);//geser kiri
 break;
 case 'd':
 case 'D':
 glTranslated(-1.0, 0.0, 0.0);//geser kanan
 break;
 case 's':
 case 'S':
 glTranslated(0.0, 0.0, -1.0);//dalam objek
 break;
 case 'w':
 case 'W':
 glTranslated(0.0, 0.0, 1.0);//keluar objek
 break;
     case 27: 
        exit(0); // keluar aplikasi
        break;
                case '1': // Menyalakan cahaya
            glEnable(GL_LIGHT0);
            lightOn = true;
            break;
        case '2': // Mematikan cahaya
            glDisable(GL_LIGHT0);
            lightOn = false;
            break;

}
display(); //memanggil fungsi display 
}