#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include<GL/freeglut.h>
#include<iostream>

typedef struct {
    int x;
    int y;
} Ponto;

float x,y;
bool check=true;
Ponto es, ei, ds, di;
int cliquefora = 0, cliquedentro = 0;

void mouse(int button, int state, int mousex, int mousey)
{
    if(button==GLUT_LEFT_BUTTON){
    //if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)

        check=true;
        x = mousex;
        y = 480-mousey;
        glutPostRedisplay();

   }
   else if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){//undo(clear)the drawing
        glClearColor(1, 1, 1, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        check = false;
   }
}

void verificaLocalClique(){
    if((x >= es.x) && (x <= ds.x) && (y >= ei.y) && (y <= es.y)){
        cliquedentro++;
    } else {
        cliquefora++;
    }
    printf("\nClique Dentro: %d\n", cliquedentro);
    printf("\nClique Fora: %d\n", cliquefora);
}

void display(void) {
    float r,g,b;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);

    glColor3f(1,0,0);

    glBegin(GL_POLYGON);
        glVertex2i(ei.x, ei.y);
        glVertex2i(es.x, es.y);
        glVertex2i(ds.x, ds.y);
        glVertex2i(di.x, di.y);
    glEnd();

    glPointSize(30);
    r=(rand()%10)/10.0;
    g=(rand()%10)/10.0;
    b=(rand()%10)/10.0;
    glColor3f(r,g,b);

    if(check){
       glBegin(GL_POINTS);
            glVertex2i(x,y);
       glEnd();
    }
    glFlush();
    verificaLocalClique();
}

int main(int argc, char** argv){
    ei.x=50; ei.y=50;
    es.x=50; es.y=430;
    ds.x=590; ds.y=430;
    di.x=590; di.y=50;

    srand(time(NULL));
	glutInit(&argc,argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Interacao via Mouse");
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}
