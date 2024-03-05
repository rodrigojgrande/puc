        /*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

#include<GL/freeglut.h>
#include<iostream>
void desenha(void) {
glClear( GL_COLOR_BUFFER_BIT );
glFlush();
}
int main(int argc, char* argv[]) {
glutInit(&argc, argv);
glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
glutInitWindowSize(800,600);
glutCreateWindow("Ola Glut");
glutDisplayFunc(desenha);
glClearColor( 0, 0, 1, 0);
glutMainLoop();
return 0;
}
