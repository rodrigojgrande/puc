#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

#include <GL/freeglut.h>
#include<math.h>

// 4 Alterações para fazer controle de escala pelo teclado
// - ListeningKey
// - GLfloat escala = 1;
// - glScalef(escala, escala, 0);
// - glutDisplayFunc();


GLfloat escala = 1;

void desenhaLetras() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Redimensionamento
    glMatrixMode(GL_PROJECTION); // Define o modo da matriz de transformação da câmera (projeção)
    glLoadIdentity(); // Seta a matri identidade na matri de projeção da câmera

    // Configura a projeção ortográfica
    gluOrtho2D(0, 800, 0, 600);
    glMatrixMode(GL_MODELVIEW); // Define o modo da matriz de transformação dos elementos gráficos que vão se inseridos na cena
    glLoadIdentity();

    glScalef(escala, escala, 0);// Faz o controle da escala no zoom

    glLineWidth(15); // Define a largura da linha
    glColor3f(1,0,0); // Define a cor da linha

    // Desenha a letra "R"
    glBegin(GL_LINE_STRIP);
    glVertex2f(100, 100);
    glVertex2f(100, 300);

    glVertex2f(200, 300);
    glVertex2f(200, 225);

    glVertex2f(100, 225);
    glColor3f(1,1,0); // Define a cor da linha

    glVertex2f(200, 100);

    glEnd();


    // Letra O
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i += 10) {
        float radian = i * 3.14159 / 180.0;
        glColor3f(1,0,0); // Define a cor da linha
        float x = 350 + 75 * cos(radian);
        float y = 200 + 75 * sin(radian);
        glVertex2f(x, y);
        glColor3f(1,1,0); // Define a cor da linha

    }
    glEnd();


    // Desenha a letra "R"
    glBegin(GL_LINE_STRIP);
    glColor3f(1,0,0); // Define a cor da linha
    glVertex2f(475, 100);
    glVertex2f(475, 300);

    glVertex2f(575, 200);
    glColor3f(1,1,0); // Define a cor da linha
    glVertex2f(475, 100);

    glEnd();


    // Desenha a letra "R"
    glBegin(GL_LINE_STRIP);
    glColor3f(1,0,0); // Define a cor da linha
    glVertex2f(625, 100);
    glVertex2f(625, 300);

    glVertex2f(725, 300);
    glVertex2f(725, 225);

    glVertex2f(625, 225);
    glColor3f(1,1,0); // Define a cor da linha
    glVertex2f(725, 100);
    glEnd();

    glFlush();
}

void listeningKey(unsigned char tecla, GLint x, GLint y){
    switch(tecla) {
        case '+': escala++;
            break;
        case '-': escala--;
            break;
    }
    desenhaLetras();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Desenhando Letras");
    glutInitWindowSize(800, 600);
    glutKeyboardFunc(listeningKey);
    glutDisplayFunc(desenhaLetras);
    glutMainLoop();

    return 0;
}
