#include <GL/freeglut.h>
#include <math.h>
#include <windows.h>
#include <stdio.h>

// <!--CONSTRUÇÃO DO CAMPO-->
// Função para desenhar o campo de futebol
void drawField() {
    glClearColor(0.0f, 0.6f, 0.0f, 1.0f); // Cor do gramado
    glClear(GL_COLOR_BUFFER_BIT);

    // Desenhar gramado (retângulo verde escuro)
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.7f, -1.0f);
        glVertex2f(-0.7f, 1.0f);
        glVertex2f(0.7f, 1.0f);
        glVertex2f(0.7f, -1.0f);
    glEnd();

    // <!--GRAMADO CLARO-->
    // Primeiro claro verde direita
    glColor3f(0.0f, 0.7f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.0f, -1.0f);
        glVertex2f(-0.0f, 1.0f);
        glVertex2f(0.2f, 1.0f);
        glVertex2f(0.2f, -1.0f);
    glEnd();

    // Segundo claro verde direita
    glColor3f(0.0f, 0.7f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.4f, -1.0f);
        glVertex2f(0.4f, 1.0f);
        glVertex2f(0.6f, 1.0f);
        glVertex2f(0.6f, -1.0f);
    glEnd();

    // Segundo claro verde direita
    glColor3f(0.0f, 0.7f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.2f, -1.0f);
        glVertex2f(-0.2f, 1.0f);
        glVertex2f(-0.4f, 1.0f);
        glVertex2f(-0.4f, -1.0f);
    glEnd();

    // Segundo claro verde direita
    glColor3f(0.0f, 0.7f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.6f, -1.0f);
        glVertex2f(-0.6f, 1.0f);
        glVertex2f(-0.8f, 1.0f);
        glVertex2f(-0.8f, -1.0f);
    glEnd();
    // <!--/GRAMADO CLARO-->

    // Desenhar marcações do campo (linhas brancas)
    glColor3f(1.0f, 1.0f, 1.0f); // Cor da linha
    glLineWidth(3.0f); // Largura da linha

    // <!--LIMITES DO CAMPO-->
    // Linha superior
    glBegin(GL_LINES);
        glVertex2f(-0.6f, 0.8f);
        glVertex2f(0.6f, 0.8f);
    glEnd();

    // Linha inferior
    glBegin(GL_LINES);
        glVertex2f(-0.6f, -0.8f);
        glVertex2f(0.6f, -0.8f);
    glEnd();

    // Linha lateral esquerda
    glBegin(GL_LINES);
        glVertex2f(-0.6f, -0.8f);
        glVertex2f(-0.6f, 0.8f);
    glEnd();

    // Linha lateral direita
    glBegin(GL_LINES);
        glVertex2f(0.6f, -0.8f);
        glVertex2f(0.6f, 0.8f);
    glEnd();
    // <!--/LIMITES DO CAMPO-->


    // <!--MEIO DE CAMPO-->
    // Linha de meio de campo
    glBegin(GL_LINES);
        glVertex2f(0.0f, -0.8f);
        glVertex2f(0.0f, 0.8f);
    glEnd();

    // Marcação do círculo central
    float radius = 0.15f;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++) {
        float theta = i * 3.1415926 / 180.0;
        glVertex2f(0.0f + radius * cos(theta), 0.0f + radius * sin(theta));
    }
    glEnd();
    // <!--/MEIO DE CAMPO-->

     // <!-+ESCANTEIOS-->
    // Marcações dos cantos
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.6f, -0.8f);
        glVertex2f(-0.6f, -0.7f);
        glVertex2f(-0.5f, -0.8f);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.6f, 0.8f);
        glVertex2f(-0.6f, 0.7f);
        glVertex2f(-0.5f, 0.8f);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(0.6f, -0.8f);
        glVertex2f(0.6f, -0.7f);
        glVertex2f(0.5f, -0.8f);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(0.6f, 0.8f);
        glVertex2f(0.6f, 0.7f);
        glVertex2f(0.5f, 0.8f);
    glEnd();
    // <!--/ESCANTEIOS-->

    // <!--GOLS-->
    // Marcações do gol esquerdo
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.6f, -0.2f);
        glVertex2f(-0.6f, 0.2f);
        glVertex2f(-0.666f, 0.2f);
        glVertex2f(-0.666f, -0.2f);
    glEnd();

    // Marcações da area do gol esquerdo
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.6f, -0.4f);
        glVertex2f(-0.6f, 0.4f);
        glVertex2f(-0.5f, 0.4f);
        glVertex2f(-0.5f, -0.4f);
    glEnd();

    // Marcações do gol direito
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.6f, -0.2f);
        glVertex2f(0.6f, 0.2f);
        glVertex2f(0.666f, 0.2f);
        glVertex2f(0.666f, -0.2f);
    glEnd();

    // Marcações da area do gol direito
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.6f, -0.4f);
        glVertex2f(0.6f, 0.4f);
        glVertex2f(0.5f, 0.4f);
        glVertex2f(0.5f, -0.4f);
    glEnd();
    // <!--/GOLS-->

    glFlush();
}
// <!--/CONSTRUÇÃO DO CAMPO-->

// Função de inicialização
void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-0.7, 0.7, -1.0, 1.0); // Definindo o sistema de coordenadas
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Tarefa 02");
    init();
    glutDisplayFunc(drawField);
    glutMainLoop();
    return 0;
}
