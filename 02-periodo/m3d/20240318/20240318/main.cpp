#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

#include <GL/freeglut.h>
#include<math.h>

/*18/03
Transformações de Coordenas das Afins
Fatores de translação: Quanto você quer deslocar em relação ao eixo (T)
Z positivo se aproxima do observador
Z negativo se distância do obervador

                      ->
- Translação (M = I e T) = Deslocamento

                       2x 0  0
- Escalamento (M = E = 0  2x 0  ) = Aumentar e diminuir o tamanho
                       0  0  2x

- Rotação (Matrizes de Rotação)= Em volta do eixo ou no próprio eixo
- Espelhamento (Matrizes de Rotação com Ângulo Fixo) = Rotação 180°
- Cisalhamento (Matrizes de Cisalhamento)= Inclinar (Itálico)

Matriz Identidade = Matriz onde a diagonal é igual a 1 e os demais elementos igual a 0

             ->
P' = M . P + T


x'      a b c      x        tx
y'  =   d e t   x  y    +   ty
t'      g h i      z        tz

*/

// 4 Alterações para fazer controle de escala pelo teclado
// - ListeningKey
// - GLfloat escala = 1;
// - glScalef(escala, escala, 0);
// - glutDisplayFunc();


GLfloat escala = 1;

// Definir variáveis para trabalhar com scale
GLfloat escalax = 1;
GLfloat escalay = 1;

// Definição de variáveis para translado
GLfloat tx = 0; // Inicia com 0 para fazer não movimentar de inicio
GLfloat ty = 0; // Inicia com 0 para fazer não movimentar de inicio


void desenhaLetras() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Redimensionamento
    glMatrixMode(GL_PROJECTION); // Define o modo da matriz de transformação da câmera (projeção)
    glLoadIdentity(); // Seta a matriz identidade na matriz de projeção da câmera

    // Configura a projeção ortográfica
    gluOrtho2D(0, 800, 0, 600);
    glMatrixMode(GL_MODELVIEW); // Define o modo da matriz de transformação dos elementos gráficos que vão se inseridos na cena
    glLoadIdentity();

    glScalef(escalax, escalay, 0);// Faz o controle da escala no zoom

    // Faz o controle do translado
    // glTranslated(); // Parâmetros Inteiros
    glTranslatef(tx, ty, 0); // Parâmetros Float

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
        // Escalamento
        // Equerda | Direita
        case '+': escalax = escalax + 0.1;
            break;
        case '-': escalax = escalax - 0.1;
            break;
        // Cima | Baixo
        case '2': escalay = escalay + 0.1;
            break;
        case '1': escalay = escalay - 0.1;
            break;

        // Translação
        // Equerda | Direita
        case 'a': tx = tx - 0.1;
            break;
        case 'd': tx = tx + 0.1;
            break;
        // Cima | Baixo
        case 'w': ty = ty + 0.1;
            break;
        case 's': ty = ty - 0.1;
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
