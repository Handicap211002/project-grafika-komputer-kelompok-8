#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

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
    init();
    glutMainLoop(); //looping program utama
    }void init(){
    glEnable(GL_DEPTH_TEST); //+4
    glClearColor(0.0, 0.0, 0.0, 1.0);
    }
    void display(){
 //reset
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //+5
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
    glBegin(GL_QUADS); //+8
    glColor3ub(252, 237, 237);
    glVertex3f(-15.0, -5.0, -10.0);
    glVertex3f(-15.0, -5.0, 13.0);
    glVertex3f(15.0, -5.0, 13.0);
    glVertex3f(15.0, -5.0, -10.0);
    glEnd();
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

//objek tengah patokan
    glBegin(GL_QUADS); //+8
    glColor3ub(255, 255, 0);
    glVertex3f(1.0, -1.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(-1.0, 1.0, 0.0);
    glVertex3f(-1.0, -1.0, 0.0);
    glEnd();
//tembok panjang
    //depan
    glBegin(GL_QUADS); //+8
    glColor3ub(197, 198, 198);
    glVertex3f(-15.0, 8.0, -10.0);
    glVertex3f(-15.0, -6.0, -10.0);
    glVertex3f(15.0, -6.0, -10.0);
    glVertex3f(15.0, 8.0, -10.0);
    glEnd();
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
    //depan
    glBegin(GL_QUADS); //+8
    glColor3ub(220, 211, 211);
    glVertex3f(-15.0, 8.0, -11.0);
    glVertex3f(-15.0, -6.0, -11.0);
    glVertex3f(-15.0, -6.0, 13.0);
    glVertex3f(-15.0, 8.0, 13.0);
    glEnd();
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
    glVertex3f(-15.0, 2.0, -1.7); // Ubah nilai z
    glVertex3f(-15.0, -5.0, -1.7);
    glVertex3f(-13.5, -5.0, -1.7);
    glVertex3f(-13.5, 2.0, -1.7);
    glEnd();
    //belakang
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(-15.0, 2.0, -3.2); // Ubah nilai z
    glVertex3f(-15.0, -5.0, -3.2);
    glVertex3f(-13.5, -5.0, -3.2);
    glVertex3f(-13.5, 2.0, -3.2);
    glEnd();
    //atas
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(-15.0, 2.0, -1.7); // Ubah nilai z
    glVertex3f(-15.0, 2.0, -3.2);
    glVertex3f(-13.5, 2.0, -3.2);
    glVertex3f(-13.5, 2.0, -1.7);
    glEnd();
    //kanan
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(-13.5, 2.0, -1.7); // Ubah nilai z
    glVertex3f(-13.5, -5.0, -1.7);
    glVertex3f(-13.5, -5.0, -3.2);
    glVertex3f(-13.5, 2.0, -3.2);
    glEnd();
    //penyambung
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(-13.5, -1.5, -1.7); // Ubah nilai z
    glVertex3f(-13.5, -3.5, -1.7);
    glVertex3f(1.0, -3.5, -1.7);
    glVertex3f(1.0, -1.5, -1.7);
    glEnd();

//kayu2
    //depan
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(1.0, 2.0, -1.7); // Ubah nilai z
    glVertex3f(1.0, -5.0, -1.7);
    glVertex3f(2.5, -5.0, -1.7);
    glVertex3f(2.5, 2.0, -1.7);
    glEnd();
    //belakang
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(1.0, 2.0, -3.2); // Ubah nilai z
    glVertex3f(1.0, -5.0, -3.2);
    glVertex3f(2.5, -5.0, -3.2);
    glVertex3f(2.5, 2.0, -3.2);
    glEnd();
    //atas
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(1.0, 2.0, -1.7); // Ubah nilai z
    glVertex3f(1.0, 2.0, -3.2);
    glVertex3f(2.5, 2.0, -3.2);
    glVertex3f(2.5, 2.0, -1.7);
    glEnd();
    //kanan
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(2.5, 2.0, -1.7); // Ubah nilai z
    glVertex3f(2.5, -5.0, -1.7);
    glVertex3f(2.5, -5.0, -3.2);
    glVertex3f(2.5, 2.0, -3.2);
    glEnd();
    //kiri
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(1.0, 2.0, -1.7); // Ubah nilai z
    glVertex3f(1.0, -5.0, -1.7);
    glVertex3f(1.0, -5.0, -3.2);
    glVertex3f(1.0, 2.0, -3.2);
    glEnd();
    //penyambung
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(2.5, 1.0, -3.2); // Ubah nilai z
    glVertex3f(2.5, -3.5, -3.2);
    glVertex3f(2.5, -3.5, -7.7);
    glVertex3f(2.5, 1.0, -7.7);
    glEnd();

//kayu3
    //depan
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(1.0, 2.0, -7.7); // Ubah nilai z
    glVertex3f(1.0, -5.0, -7.7);
    glVertex3f(2.5, -5.0, -7.7);
    glVertex3f(2.5, 2.0, -7.7);
    glEnd();
    //belakang
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(1.0, 2.0, -9.2); // Ubah nilai z
    glVertex3f(1.0, -5.0, -9.2);
    glVertex3f(2.5, -5.0, -9.2);
    glVertex3f(2.5, 2.0, -9.2);
    glEnd();
    //atas
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(1.0, 2.0, -7.7); // Ubah nilai z
    glVertex3f(1.0, 2.0, -9.2);
    glVertex3f(2.5, 2.0, -9.2);
    glVertex3f(2.5, 2.0, -7.7);
    glEnd();
    //kanan
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(2.5, 2.0, -7.7); // Ubah nilai z
    glVertex3f(2.5, -5.0, -7.7);
    glVertex3f(2.5, -5.0, -9.2);
    glVertex3f(2.5, 2.0, -9.2);
    glEnd();
    //kiri
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(1.0, 2.0, -7.7); // Ubah nilai z
    glVertex3f(1.0, -5.0, -7.7);
    glVertex3f(1.0, -5.0, -9.2);
    glVertex3f(1.0, 2.0, -9.2);
    glEnd();
    //penyambung
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(-13.5, -1.5, -9.2); // Ubah nilai z
    glVertex3f(-13.5, -3.5, -9.2);
    glVertex3f(1.0, -3.5, -9.2);
    glVertex3f(1.0, -1.5, -9.2);
    glEnd();

//kayu4
    //depan
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(-15.0, 2.0, -7.7);  // Ubah nilai z
    glVertex3f(-15.0, -5.0, -7.7);
    glVertex3f(-13.5, -5.0, -7.7);
    glVertex3f(-13.5, 2.0, -7.7);
    glEnd();
    //belakang
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(-15.0, 2.0, -9.2);  // Ubah nilai z
    glVertex3f(-15.0, -5.0, -9.2);
    glVertex3f(-13.5, -5.0, -9.2);
    glVertex3f(-13.5, 2.0, -9.2);
    glEnd();
    //atas
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(-15.0, 2.0, -7.7);  // Ubah nilai z
    glVertex3f(-15.0, 2.0, -9.2);
    glVertex3f(-13.5, 2.0, -9.2);
    glVertex3f(-13.5, 2.0, -7.7);
    glEnd();
    //kanan
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(-13.5, 2.0, -7.7);  // Ubah nilai z
    glVertex3f(-13.5, -5.0, -7.7);
    glVertex3f(-13.5, -5.0, -9.2);
    glVertex3f(-13.5, 2.0, -9.2);
    glEnd();
    //penyambung
    glBegin(GL_QUADS); //+8
    glColor3ub(160, 82, 45);
    glVertex3f(-14.5, 1.0, -2.5);  // Ubah nilai z
    glVertex3f(-14.5, -3.5, -2.5);
    glVertex3f(-14.5, -3.5, -7.7);
    glVertex3f(-14.5, 1.0, -7.7);
    glEnd();

//kasur
    //belakang
    //selimut
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 1);
    glVertex3f(-10.0, 0.0, -9.2); // Ubah nilai z
    glVertex3f(-10.0, -1.5, -9.2);
    glVertex3f(1.0, -1.5, -9.2);
    glVertex3f(1.0, 0.0, -9.2);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 1);
    glVertex3f(-10.0, 0.0, -1.7); // Ubah nilai z
    glVertex3f(-10.0, -1.5, -1.7);
    glVertex3f(1.0, -1.5, -1.7);
    glVertex3f(1.0, 0.0, -1.7);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 1);
    glVertex3f(-10.0, 0.0, -9.2); // Ubah nilai z
    glVertex3f(-10.0, 0.0, -1.7);
    glVertex3f(1.0, 0.0, -1.7);
    glVertex3f(1.0, 0.0, -9.2);
    glEnd();
    //bantal
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(-14.5, 0.0, -9.2); // Ubah nilai z
    glVertex3f(-14.5, -1.5, -9.2);
    glVertex3f(-10.0, -1.5, -9.2);
    glVertex3f(-10.0, 0.0, -9.2);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(-14.5, 0.0, -1.7); // Ubah nilai z
    glVertex3f(-14.5, -1.5, -1.7);
    glVertex3f(-10.0, -1.5, -1.7);
    glVertex3f(-10.0, 0.0, -1.7);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f(-14.5, 0.0, -9.2); // Ubah nilai z
    glVertex3f(-14.5, 0.0, -1.7);
    glVertex3f(-10.0, 0.0, -1.7);
    glVertex3f(-10.0, 0.0, -9.2);
    glEnd();
//meja (lemari)
    //depan
    glBegin(GL_QUADS); //+8
    glColor3ub(255, 229, 204);
    glVertex3f(-15.0, 0.5, 3.0);
    glVertex3f(-15.0, -5.0, 3.0);
    glVertex3f(-11.5, -5.0, 3.0);
    glVertex3f(-11.5, 0.5, 3.0);
    glEnd();
//belakang
    glBegin(GL_QUADS); //+8
    glColor3ub(255, 229, 204);
    glVertex3f(-15.0, 0.5, -0.5);
    glVertex3f(-15.0, -5.0, -0.5);
    glVertex3f(-11.5, -5.0, -0.5);
    glVertex3f(-11.5, 0.5, -0.5);
    glEnd();
    //atas
    glBegin(GL_QUADS); //+8
    glColor3ub(255, 229, 204);
    glVertex3f(-15.0, 0.5, 3.0);
    glVertex3f(-15.0, 0.5, -0.5);
    glVertex3f(-11.5, 0.5, -0.5);
    glVertex3f(-11.5, 0.5, 3.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS); //+8
    glColor3ub(255, 229, 204);
    glVertex3f(-11.5, 0.5, 3.0);
    glVertex3f(-11.5, -5.0, 3.0);
    glVertex3f(-11.5, -5.0, -0.5);
    glVertex3f(-11.5, 0.5, -0.5);
    glEnd();

//meja tiang sendiri
    //depan
    glBegin(GL_QUADS); //+8
    glColor3ub(255, 229, 204);
    glVertex3f(-15.0, 0.5, 7.5);
    glVertex3f(-15.0, -5.0, 7.5);
    glVertex3f(-11.5, -5.0, 7.5);
    glVertex3f(-11.5, 0.5, 7.5);
    glEnd();
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
    glBegin(GL_QUADS); //+8
    glColor3ub(255, 229, 204);
    glVertex3f(-15.0, 1.0, 7.5);
    glVertex3f(-15.0, 1.0, -0.5);
    glVertex3f(-11.5, 1.0, -0.5);
    glVertex3f(-11.5, 1.0, 7.5);
    glEnd();
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
 //gluOrtho2D(-10, 10, -10, 10); //setting spesifikasi proyeksi yang diinginkan (2D)
 //glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0); //+6 proyeksi orthografik 3D
 gluPerspective(30.0, w / h, 1.0, 100.0); //proyeksi perspektif
/* set initial position */
glTranslatef(0.0, -5.0, -100.0);
 glMatrixMode(GL_MODELVIEW); //merubah matrix mode menjadi gl_modelview

}

void keyboard(unsigned char key, int x, int y)
{

switch (key)
{
case 'd':
 case 'D':
 glTranslated(-1.0, 0.0, 0.0);//geser kiri
 break;
 case 'a':
 case 'A':
 glTranslated(1.0, 0.0, 0.0);//geser kanan
 break;
 case 's':
 case 'S':
 glTranslated(0.0, 1.0, 0.0);//geser atas
 break;
 case 'w':
 case 'W':
 glTranslated(0.0, -1.0, 0.0);//geser bawah
 break;
 case 'q':
 case 'Q':
 glTranslated(0.0, 0.0, -1.0);//dalam objek
 break;
 case 'e':
 case 'E':
 glTranslated(0.0, 0.0, 1.0);//keluar objek
 break;
 case 'i':
 case 'I':
 glRotatef(2.0, 1.0, 0.0, 0.0);//rotate kanan
 break;
 case 'k':
 case 'K':
 glRotatef(2.0, -1.0, 0.0, 0.0);//rotate kanan
 break;
 case 'j':
 case 'J':
  glRotatef(2.0, 0.0, 1.0, 0.0);//rotate atas
 break;
 case 'l':
 case 'L':
  glRotatef(2.0, 0.0, -1.0, 0.0);//rotate atas
 break;
}
display(); //memanggil fungsi display atau bisa pakai glutPostRedisplay();
}