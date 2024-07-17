#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
    Escrita e leitura formatada de arquivos texto usando as funcoes
    - fprintf()
    - fscanf()
*/

typedef struct {
    int id;
    char cor;
    float coordX;
    float coordY;
} Ponto;

Ponto registraPonto();
int escrevePonto(FILE *f);
int lePonto(FILE *f, Ponto *p);

int main(){

    char filename[20] = "pontos.txt";
    FILE *f;
    Ponto p;
    int n;

    // abrindo em modo de leitura e escrita, inserindo novos elementos no final do arquivo
    // caso queira sobrescrever o arquivo, use w+
    f = fopen(filename, "a+");
    if(f == NULL){
        printf("Problemas para abrir o arquivo");
        exit(1);
    }

    printf("Pontos existentes no arquivo:\n\n");

    //processo se repete ate a leitura do arquivo retornar -1 (ou seja, nao consegui ler mais nada)
    while(lePonto(f, &p) > 0)
        printf("%d %c %f %f\n", p.id, p.cor, p.coordX, p.coordY);

    printf("\n\n------ Registrando novos pontos -------\n\n");
    printf("Quantos pontos vc deseja registrar?\n");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        escrevePonto(f);
    }

    fclose(f);
}


Ponto registraPonto(){
    Ponto p;

    printf("Digite as informacoes do novo ponto:\n");
    printf("Id: ");
    scanf("%d", &p.id);
    getchar();
    printf("Cor: ");
    scanf("%c", &p.cor);
    printf("Coordenada X do ponto: ");
    scanf("%f", &p.coordX);
    printf("Coordenada Y do ponto: ");
    scanf("%f", &p.coordY);

    return p;
}

int escrevePonto(FILE *f){

    Ponto p = registraPonto(); // a leitura do ponto do teclado eh delegada para essa funcao

    //fprintf escreve formatado no arquivo. caso nao tenha sucesso, retorna um valor negativo
    return fprintf(f, "%d %c %f %f\n", p.id, p.cor, p.coordX, p.coordY);
}

int lePonto(FILE *f, Ponto *p){

    //fscanf le formatado de um arquivo. o retorno eh o numero de valores lido
    // retorna -1 caso atinge fim de arquivo (nao consegue ler mais nada)
    return fscanf(f, "%d %c %f %f", &p->id, &p->cor, &p->coordX, &p->coordY);
}
