#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>
#include <stdlib.h>

void desenha(void) {
    glClear ( GL_COLOR_BUFFER_BIT ); //Limpa o Buffer

    gluOrtho2D(-3, 3, -3, 3); // Qual a area de enquadramento do espaço

    // glBegin (GL_LINE_STRIP); // Faz a ligação dos vertices de 2 em 2
    // glBegin (GL_LINE_LOOP); // Conecta o último vertice com o primeiro
    // glBegin (GL_TRIANGLES); // Gera um triângulo de 3 em 3 vertices
    // glBegin (GL_TRIANGLES_STRIP); // Cria uma malha com os vértices do triangulo
    // glBegin (GL_TRIANGLES_PAN); // Conecta o último vertice com o primeiro
    //  glBegin (GL_QUADS); // Gera um quadrado de 4 em 4 vertices
    // glBegin (GL_QUADS_STRIP); // Cria uma malha com os vértices do quadrado
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
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); //Configura o modo de exibição da tela
    // Cena manipulavel através de um frame buffer único = Glut_Single
    // Frame Buffer = Memória de Vídeo
    // Glut_Double = Frame Buffer Duplo (Animação)
    // Glub RGB = Define a manipulação de Color

    glutInitWindowSize(800, 600); // Define as dimenões da janela (Coluna X Linha)
    glutInitWindowPosition(300, 100); // Define a posição da janela (Coluna X Linha)
    glutCreateWindow("Ola Glut"); // Define o título da janela e efetivamente cria
    glutDisplayFunc(desenha); // Vão estar dentro da função Desenha
    glClearColor (0, 0, 1, 0); // Define a cor do fundo da cena (RGBA)
    glutMainLoop(); // Mantém o código em loop
    return 0;
}
