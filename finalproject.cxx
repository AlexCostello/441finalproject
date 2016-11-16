#include "GL/glut.h"
#include "GL/gl.h"
#include <stdlib.h>

int delay = 10;
double y = 1;
int counter = 0;
int idCounter = 0;

class Square
{
    public:
        double X[4];
        double Y[4];
        double Z[4];

        bool initialized;
        int squareID;
        int squareType;

        Square();
       // void generateSquare();
};

Square::Square(void){
    initialized = true;
    squareID = idCounter;
    idCounter++;
    squareType = rand() % 4 + 1;
 //   generateSquare();
}

void initializeWindow()
{
    glEnable(GL_COLOR_MATERIAL);
    glMatrixMode(GL_MODELVIEW);
}

void squareDrop(int n)
{
    n++;
    glutPostRedisplay();
    if(n < 100){
        glutTimerFunc(delay, squareDrop, n);
    }
}
/*
void generateSquare(int n)
{
    n++;
    glutPostRedisplay();
    if(n < 1000)
*/
void squareA()
{
    glBegin(GL_QUADS);
        glColor3f(0, 1, 0);
        glVertex3f(-.9, 1, .5);
        glVertex3f(-.6, 1, .5);
        glVertex3f(-.6, .7, .5);
        glVertex3f(-.9, .7, .5);
    glEnd();
}

void squareW()
{
    glBegin(GL_QUADS);
        glColor3f(1, 0, 0);
        glVertex3f(-.4, 1, .5);
        glVertex3f(-.1, 1, .5);
        glVertex3f(-.1, .7, .5);
        glVertex3f(-.4, .7, .5);
    glEnd();
}

void squareS()
{
    glBegin(GL_QUADS);
        glColor3f(0, 0, 1);
        glVertex3f(.1, 1, .5);
        glVertex3f(.4, 1, .5);
        glVertex3f(.4, .7, .5);
        glVertex3f(.1, .7, .5);
   glEnd();
}

void squareD()
{
    glBegin(GL_QUADS);
        glColor3f(0, 1, 1);
        glVertex3f(.6, 1, .5);
        glVertex3f(.9, 1, .5);
        glVertex3f(.9, .7, .5);
        glVertex3f(.6, .7, .5);
    glEnd();
} 

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    squareA();
    squareW();
    squareS();
    squareD();
    glTranslatef(0, -.01, 0);
    counter++;
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(80, 80);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Squares");
    initializeWindow();
    glutDisplayFunc(display);
    glutTimerFunc(delay, squareDrop, 0);
    

    glutMainLoop();
}
