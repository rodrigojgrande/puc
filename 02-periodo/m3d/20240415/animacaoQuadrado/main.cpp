#include <windows.h>
#include <GL/freeglut.h>
#include <stdio.h>

GLfloat x1 = 100.0f;
GLfloat y1 = 150.0f;
GLsizei rsize = 50;

// Vetor de translacao
GLfloat xstep = 3.0f;
GLfloat ystep = 3.0f;

GLfloat windowWidth;
GLfloat windowHeight;

void Desenha(void)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(1.0f, 0.0f, 0.0f);
     glBegin(GL_QUADS);
               glVertex2i(x1,y1+rsize);
               glVertex2i(x1,y1);
               glColor3f(0.0f, 0.0f, 1.0f);
               glVertex2i(x1+rsize,y1);
               glVertex2i(x1+rsize,y1+rsize);
     glEnd();

     glutSwapBuffers(); // Para utilização de Buffer Duplo
}

void Timer(int value)
{
    // Muda a direção quando chega na borda esquerda ou direita
      if(x1 > windowWidth-rsize || x1 < 0) // Verifica Colisão
            xstep = -xstep;

    // Muda a direção quando chega na borda superior ou inferior
    if(y1 > windowHeight-rsize || y1 < 0) // Verifica Colisão
          ystep = -ystep;

    // Verificação de bordas.  Se a window for menor e o quadrado sair do volume de visualização
   if(x1 > windowWidth-rsize)
         x1 = windowWidth-rsize-1;

   if(y1 > windowHeight-rsize)
         y1 = windowHeight-rsize-1;

    x1 += xstep;
    y1 += ystep;

    glutPostRedisplay(); // Chama Redesnho
    glutTimerFunc(5,Timer, 0); // Chama a função em X tempo
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
     printf("\n w: %d      h: %d ", w, h);
     glViewport(0, 0, w, h);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
     windowWidth = w;
     windowHeight = h;
     gluOrtho2D(0.0f, windowWidth, 0.0f, windowHeight);
}

int main(int argc, char** argv)
{
     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Bufer Duplo para animação
     glutInitWindowSize(640,480);
     glutInitWindowPosition(10,10);
     glutCreateWindow("Animacao");
     glutDisplayFunc(Desenha);
     glutReshapeFunc(AlteraTamanhoJanela); // Sempre que o usuário alterar o tamanho da janela
     glutTimerFunc(5, Timer, 0); // Cria um timer para a chamada da função
     glutMainLoop();
}
