#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>
#include <stdlib.h>

void desenha(void) {
    glClear ( GL_COLOR_BUFFER_BIT );

    gluOrtho2D(-3, 3, -3, 3);

    glBegin (GL_LINES);
        glVertex2f(-2,0);
        glVertex2f(2,0);

        glVertex2f(0,-2);
        glVertex2f(0,2);
        glEnd();

    glFlush();
}

int main (int argc, char* argv[] ){
    // printf("%d\n", argc);
    // printf("%s\n", argv[0]);
    glutInit (&argc, argv); //Inicia o Glut
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); //Configura o modo de exibi��o da tela
    // Cena manipulavel atrav�s de um frame buffer �nico = Glut_Single
    // Frame Buffer = Mem�ria de V�deo
    // Glut_Double = Frame Buffer Duplo (Anima��o)
    // Glub RGB = Define a manipula��o de Color

    glutInitWindowSize(800, 600); // Define as dimen�es da tela (Linha X Coluna)
    glutInitWindowPosition(300, 100); // Define a posi��o da janela
    glutCreateWindow("Ola Glut"); // Define o t�tulo da janela
    glutDisplayFunc(desenha); // V�o estar dentro da fun��o Desenha
    glClearColor (0, 0, 1, 0); // Define a cor da janela (RGBA)
    glutMainLoop(); // Mant�m o c�digo em loop
    return 0;
}
