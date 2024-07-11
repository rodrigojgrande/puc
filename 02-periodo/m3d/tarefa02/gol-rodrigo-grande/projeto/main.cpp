#ifdef __APPLE__
#include <GLUT/freeglut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include<math.h>

// <!--Tarefa 01-->
GLfloat escala = 1;

float anguloRotacao = 0;

// Definir variaveis para trabalhar com scale
GLfloat escalax = 1;
GLfloat escalay = 1;

// Definicao de variaveis para translado
GLfloat tx = 0; // Inicia com 0 para fazer noo movimentar de inicio
GLfloat ty = 0; // Inicia com 0 para fazer nao movimentar de inicio

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
          // Rotaciona o cubo 5 graus no sentido anti-hor�rio
          anguloRotacao -= 20;
          break;
        case 'e':
          // Rotaciona o cubo 5 graus no sentido hor�rio
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
// <!--/Tarefa 01-->

float alpha = 0;
float beta = 0;
float delta = 0.5f;

typedef struct { // Armazenar ponto central da esfera
    float x;
    float y;
    float z;
} ponto;

ponto bola = {0.0f, 0.0f, 0.0f};
float deslocabolax = 0.01f;
float deslocabolay = 0.001f;
float deslocabolaz = 0.0f; // Atualize esta variável para movimentação no eixo z, se necessário

GLfloat limx = 10; // Limite Linha X
GLfloat limy = 9; // Limite Linha Y
GLfloat limz = 5; // Limite Linha Z

int gol = 0;
int chutar = 0;
int chuteErrado = 0;
char resultado[20] = "";

int abrir = 0;

void init() {
    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4, 4, -4, 4, -4, 4);
}

void renderText(float x, float y, void *font, const char *string) {
    glColor3f(1, 1, 1);
    glRasterPos2f(x, y);
    while (*string) {
        glutBitmapCharacter(font, *string);
        string++;
    }
}

void display() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Aplicar rotações e escala
    glRotatef(beta, 0, 1, 0);
    glRotatef(alpha, 1, 0, 0);
    glScalef(delta, delta, delta);

    // Desenhar trave
    glColor3f(1.0f, 1.0f, 1.0f); // Cor da linha
    glLineWidth(3.0f); // Largura da linha

    glBegin(GL_LINES); // Trave Esquerda
        glVertex3f(3.5f, -1.0f, 3.0f); // Ponto inferior
        glVertex3f(3.5f, 2.0f, 3.0f);  // Ponto superior
    glEnd();

    glBegin(GL_LINES); // Trave Direita
        glVertex3f(3.5f, -1.0f, -3.0f); // Ponto inferior
        glVertex3f(3.5f, 2.0f, -3.0f);  // Ponto superior
    glEnd();

    glBegin(GL_LINES); // Travessão
        glVertex3f(3.5f, 2.0, 3.0f); // Ponto superior esquerdo
        glVertex3f(3.5f, 2.0f, -3.0f);  // Ponto superior direito
    glEnd();

    // Desenhar esfera
    glColor3f(1, 1, 0);
    glPushMatrix(); // Empilhar a transformação
    glTranslated(bola.x, bola.y, bola.z);
    glutWireSphere(0.4f, 40, 20);
    glPopMatrix(); // Desempilhar a transformação

    // Desenhar campo
    glTranslatef(0, -1, 0);
    glScalef(15, 0.2f, 15);
    glColor3f(0, 1, 0);
    glutSolidCube(1.0f);

    // Desenhar marcações no campo
    glLineWidth(2.0f); // Definir a largura das linhas de marcação
    glColor3f(1.0f, 1.0f, 1.0f); // Cor branca para as linhas de marcação

    // Desenhar linhas de limite
    glBegin(GL_LINE_LOOP);
        glVertex3f(-0.5f, 0.51f, -0.5f);
        glVertex3f(-0.5f, 0.51f, 0.5f);
        glVertex3f(0.5f, 0.51f, 0.5f);
        glVertex3f(0.5f, 0.51f, -0.5f);
    glEnd();

    // Desenhar linha do meio
    glBegin(GL_LINES);
        glVertex3f(0.0f, 0.51f, -0.5f);
        glVertex3f(0.0f, 0.51f, 0.5f);
    glEnd();

    // Desenhar círculo central
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i += 10) {
        float radian = i * 3.14159 / 180.0;
        float x = 0.1 * cos(radian);
        float z = 0.1 * sin(radian);
        glVertex3f(x, 0.51f, z);
    }
    glEnd();

    // Placar
    char placarGols[50];
    sprintf(placarGols, "Gols = %d", gol);
    renderText(0, -15, GLUT_BITMAP_HELVETICA_18, placarGols);

    char placarChutesErrados[50];
    sprintf(placarChutesErrados, "Chutes para fora = %d", chuteErrado);
    renderText(0, -20, GLUT_BITMAP_HELVETICA_18, placarChutesErrados);

    //Arquivo Nome
    if (abrir == 1) {
        desenhaLetras();
    }

    glutSwapBuffers(); // Declaração de frame buffer duplo
}

void MoveBola(int value) {
    if (chutar) {
        bola.x += deslocabolax;
        bola.y += deslocabolay;
        bola.z += deslocabolaz;

        // Verifica se a bola atravessa a linha do gol (x >= 5)
        if (bola.x >= 5) {
            if (bola.z <= 3.0f && bola.z >= -3.0f && bola.y <= 2.0f && bola.y >= -1.0f) {
                gol++;
                strcpy(resultado, "Gol!!!");
                printf("Golllllll!!!!!!!!\n");
            } else {
                chuteErrado++;
                strcpy(resultado, "Errou!!!");
                printf("ERROUUUU!!!!\n");
            }
            bola.x = 0;
            bola.y = 0;
            bola.z = 0;
            chutar = 0;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(2, MoveBola, 0);
}

void keyboard(unsigned char key, int x, int y) {
    if (key == ' ') {
        chutar = 1;
        strcpy(resultado, ""); // Limpar o resultado quando um novo chute é iniciado
    }

    if (key == 'c') {
        abrir = 1;
    }

    if (key == 'r') {
        gol = 0;
        chuteErrado = 0;
    }

    if (key == 'q') {
        delta = delta * 1.1f;
    }

    if (key == 'w') {
        delta = delta * 0.9f;
    }

    glutPostRedisplay();

    if (key == 27) {
        exit(0);
    }
}

void listeningSpKey(GLint tecla, GLint x, GLint y) {
    switch (tecla) {
        // Controle da Câmera
        case GLUT_KEY_F1:
            alpha = alpha - 1;
            break;
        case GLUT_KEY_F2:
            alpha = alpha + 1;
            break;
        case GLUT_KEY_F3:
            beta = beta + 1;
            break;
        case GLUT_KEY_F4:
            beta = beta - 1;
            break;

        // Controle da Bola
        case GLUT_KEY_UP:
            bola.y++;
            break;
        case GLUT_KEY_DOWN:
            bola.y--;
            break;
        case GLUT_KEY_LEFT:
            bola.x--;
            break;
        case GLUT_KEY_RIGHT:
            bola.x++;
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(720, 480);
    glutCreateWindow("Futebol - Rodrigo Grande");
    gluOrtho2D(0.0, 400, 0.0, 600);
    init();
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(listeningSpKey);
    glutDisplayFunc(display);
    glutTimerFunc(5, MoveBola, 0);
    glutMainLoop();
}
