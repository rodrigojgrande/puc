#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>
#include <stdlib.h>

void desenha(void) {
    glClear ( GL_COLOR_BUFFER_BIT ); //Limpa o Buffer

    gluOrtho2D(-3, 3, -3, 3); // Qual a area de enquadramento do espa�o

    // glBegin (GL_LINE_STRIP); // Faz a liga��o dos vertices de 2 em 2
    // glBegin (GL_LINE_LOOP); // Conecta o �ltimo vertice com o primeiro
    // glBegin (GL_TRIANGLES); // Gera um tri�ngulo de 3 em 3 vertices
    // glBegin (GL_TRIANGLES_STRIP); // Cria uma malha com os v�rtices do triangulo
    // glBegin (GL_TRIANGLES_PAN); // Conecta o �ltimo vertice com o primeiro
    //  glBegin (GL_QUADS); // Gera um quadrado de 4 em 4 vertices
    // glBegin (GL_QUADS_STRIP); // Cria uma malha com os v�rtices do quadrado
        glVertex2f(-2,0);
        glVertex2f(2,0);

        glVertex2f(0,-2);
        glVertex2f(0,2);
        glEnd();

    glFlush(); //Atualizar a jenala com os valores do framebuffer
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

    glutInitWindowSize(800, 600); // Define as dimen�es da janela (Coluna X Linha)
    glutInitWindowPosition(300, 100); // Define a posi��o da janela (Coluna X Linha)
    glutCreateWindow("Ola Glut"); // Define o t�tulo da janela e efetivamente cria
    glutDisplayFunc(desenha); // V�o estar dentro da fun��o Desenha
    glClearColor (0, 0, 1, 0); // Define a cor do fundo da cena (RGBA)
    glutMainLoop(); // Mant�m o c�digo em loop
    return 0;
}
