#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

#include <GL/freeglut.h>
#include<math.h>

GLfloat escala = 1;

float anguloRotacao = 0;

// Definir variaveis para trabalhar com scale
GLfloat escalax = 1;
GLfloat escalay = 1;

// Definicao de variaveis para translado
GLfloat tx = 0; // Inicia com 0 para fazer noo movimentar de inicio
GLfloat ty = 0; // Inicia com 0 para fazer nao movimentar de inicio

// F1
void desenhaLetras() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Redimensionamento
    glMatrixMode(GL_PROJECTION); // Define o modo da matriz de transformaaoo da camera (projecao)
    glLoadIdentity(); // Seta a matriz identidade na matriz de projecao da camera

    // Configura a projecao ortogra fica
    gluOrtho2D(0, 800, 0, 600);
    glMatrixMode(GL_MODELVIEW); // Define o modo da matriz de transformaaoo dos elementos graficos que vao se inseridos na cena
    glLoadIdentity();

    glScalef(escalax, escalay, 0);// Faz o controle da escala no zoom

    // Faz o controle do translado
    glTranslatef(tx, ty, 0); // Parametros Float

    glRotatef(anguloRotacao, 0, 1, 0);


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


    // Desenha a letra "D"
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

    // Desenha a letra "I"
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,0); // Define a cor da linha
    glVertex2f(780, 100);
    glColor3f(1,0,0); // Define a cor da linha
    glVertex2f(780, 300);

    glEnd();

    /*
    // Letra G
    glBegin(GL_LINE_STRIP);
    glVertex2f(150, 190);
    glVertex2f(200, 190);
    glVertex2f(200, 125);
    glVertex2f(200, 125);
    glVertex2f(100, 125);
    glVertex2f(100, 275);
    glVertex2f(200, 275);
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
    */


    glFlush();
}

// F2
void listeningKey(unsigned char tecla, GLint x, GLint y){
    switch(tecla) {
        // Escalamento
        // Equerda | Direita
        // F3
        case '+': escalax = escalax + 0.5;
            break;
        // F4
        case '-': if (escalax <= 0.5){
            // Bloqueia a diminuicao da escalax
        } else {
            escalax = escalax - 0.5;
        }
            break;

        // F5
        case 'q':
          // Rotaciona o cubo 5 graus no sentido anti-horário
          anguloRotacao -= 20;
          break;
        case 'e':
          // Rotaciona o cubo 5 graus no sentido horário
          anguloRotacao += 20;
          break;
        // Cima | Baixo
        case '2': escalay = escalay + 0.1;
            break;
        case '1': escalay = escalay - 0.1;
            break;

        // F6
        // Translacao
        // Equerda | Direita
        case 'a': tx = tx - 0.5;
            break;
        case 'd': tx = tx + 0.5;
            break;
        // Cima | Baixo
        case 'w': ty = ty + 0.5;
            break;
        case 's': ty = ty - 0.5;
            break;

        }
    desenhaLetras();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(300, 100);
    glClearColor (0, 0, 0, 0);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Desenhando Letras");
    glutKeyboardFunc(listeningKey);
    glutDisplayFunc(desenhaLetras);
    glutMainLoop();
    return 0;
}
