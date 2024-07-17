#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char cor;
    float coordX;
    float coordY;
} Ponto;

Ponto registraPonto();

int main(){
    // Ponto p = registraPonto();
    // printf("%d %c %f %f", p.id, p.cor, p.coordX, p.CoordY);

    char filename[50] = "pontos.groselha";
    int n;
    Ponto p;

    FILE *f;
    f = fopen(filename, "a+");
    if(f == NULL) {
        printf("Falha ao abrir o arquivo");
        exit(1);
    }

    printf("Pontos existentes no arquivo:\n");
    while(lePonto(f, &p) > 0){
        printf("%d %c %f %f\n", p.id, p.cor, p.coordX, p.coordY);
    }


    printf("\n\nDigite a quantidade de pontos que voce quer registrar: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        escrevePonto(f);
    }

    fclose(f);
}

Ponto registraPonto(){
    Ponto p;

    printf("Digite as informacoes do ponto!\n");
    printf("ID: ");
    scanf("%d", &p.id);
    getchar();
    printf("Cor:  ");
    scanf("%c", & p.cor);
    getchar();
    printf("Coordenada X: ");
    scanf("%f", & p.coordX);
    getchar();
    printf("Coordenada Y: ");
    scanf("%f", & p.coordY);
    getchar();

    return p;
}

int escrevePonto(FILE *f){
    Ponto p = registraPonto();
    fprintf(f, "%d %c %f %f\n", p.id, p.cor, p.coordX, p.coordY );
}

int lePonto(FILE *f, Ponto *p){
    return fscanf(f, "%d %c %f %f", &p->id, &p->cor, &p->coordX, &p->coordY); // Retorna a quantidade de pontos lidos
}
