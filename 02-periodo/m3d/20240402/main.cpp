
#ifdef __APPLE__
#include <GLUT/freeglut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>

float alpha = 0;
float beta = 0;
float delta = 0.5f;

typedef struct { // Armazenar ponto central da esfera
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
} ponto;

ponto bola;
float deslocabolax = 0.01f;
float deslocabolay = 0.001f;
float deslocabolaz = 0.0f;

GLfloat limx = 4;

void init() {
     glClearColor(0, 0, 0, 0);
     glEnable(GL_DEPTH_TEST);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glOrtho(-4, 4, -4, 4, -4, 4);
 }

void display() {
     glClearColor(0.0, 0.0, 0.0, 0.0);
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     glRotatef(beta, 0, 1, 0);
     glRotatef(alpha, 1, 0, 0);
     glScalef(delta, delta, delta);
     glColor3f(1, 1, 0);

     glPushMatrix(); // Empilhar a transformação
     glTranslated(bola.x, bola.y, bola.z);
     glutWireSphere(1.0f, 40, 20);
     glPopMatrix(); // Desempilhar a transformação



     // <!--Teste de movimentação da bola-->
     // glTranslatef(deslocabolax, deslocabolay, deslocabolaz);
     // glTranslatef(1.0f, 0, 0);
     // glutWireSphere(1.0f, 40, 20);
     // glLoadIdentity();
      // <!--/Teste de movimentação da bola-->


     glTranslatef(0, -1, 0);
     glScalef(4, 0.1f, 4);
     glColor3f(0, 1, 0);
     //glLoadIdentity();
     glutSolidCube(1.0f);

     // glFlush();
     glutSwapBuffers(); // Declaração de frame buffer duplo
 }

 void MoveBola(int value)
{
    bola.x = bola.x + deslocabolax; // Movimento da bola
    bola.y = bola.y + deslocabolay; // Movimento da bola

    if (bola.x > limx) { // Verificar se saiu da tela
        bola.x=0;
        bola.y=0;
    }

    printf("%f\n", bola.x);

    glutPostRedisplay();
    glutTimerFunc(5,MoveBola, 0);
}

void keyboard(unsigned char key, int x, int y)
{
     if(key == 'q')
        delta = delta * 1.1f;
     if(key == 'w')
        delta = delta * 0.9f;
     glutPostRedisplay();
 }

 void  listeningSpKey (GLint tecla,
                    GLint x, GLint y) {
	switch(tecla) {
		case GLUT_KEY_UP:
		        alpha = alpha - 1;
				break;
		case GLUT_KEY_DOWN:
		        alpha = alpha + 1;
				break;
		case GLUT_KEY_LEFT:
		        beta = beta + 1;
				break;
		case GLUT_KEY_RIGHT:
		        beta = beta - 1;
				break;
	}
	glutPostRedisplay();
}

int main(int argc, char **argv)
 {
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
     glutInitWindowPosition(100, 100);
     glutInitWindowSize(400, 400);
     glutCreateWindow("Exemplo Esfera 3D Transformação");
     gluOrtho2D(0.0, 400, 0.0, 600);
     init();
     glutKeyboardFunc(keyboard);
     glutSpecialFunc(listeningSpKey);
     glutDisplayFunc(display);
     glutTimerFunc(5, MoveBola, 0);
     glutMainLoop();
 }
