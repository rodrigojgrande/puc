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
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); //Configura o modo de exibição da tela
    // Cena manipulavel através de um frame buffer único = Glut_Single
    // Frame Buffer = Memória de Vídeo
    // Glut_Double = Frame Buffer Duplo (Animação)
    // Glub RGB = Define a manipulação de Color

    glutInitWindowSize(800, 600); // Define as dimenões da tela (Linha X Coluna)
    glutInitWindowPosition(300, 100); // Define a posição da janela
    glutCreateWindow("Ola Glut"); // Define o título da janela
    glutDisplayFunc(desenha); // Vão estar dentro da função Desenha
    glClearColor (0, 0, 1, 0); // Define a cor da janela (RGBA)
    glutMainLoop(); // Mantém o código em loop
    return 0;
}
