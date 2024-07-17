
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
    char nome[25];
    char raca[25];
    float peso;
} Cao;

Cao registraCao();

int main(){

    char filename[20] = "caes.txt";
    FILE *f;
    Cao caes[10], c;
    int n = 0;

    // abrindo um arquivo binario em modo de leitura
    // caso queira abrir para leitura e escrita, use rb+, wb+ ou ab+, dependendo da necessidade
    // rb+ -> arquivo precisa ja existir
    // wb+ -> cria um novo arquivo, deleta o antigo
    // ab+ -> cria um arquivo se nao existir, escreve no final
    f = fopen(filename, "rb");
    if(f == NULL){
        printf("Problemas para abrir o arquivo");
        exit(1);
    }

    //lendo ate no maximo 10 caes do arquivo
    printf("Lendo caes do arquivo: \n\n");
    n = fread(caes, sizeof(Cao), 10, f); //fread retorna quantos elementos foram lidos
    for(int i = 0; i < n; i++){ // usamos o n para iterar no vetor ate quantos forem lidos
        printf("Id: %d\n", caes[i].id);
        printf("Nome: %s\n", caes[i].nome);
        printf("Raca: %s\n", caes[i].raca);
        printf("Peso: %f\n\n", caes[i].peso);
    }

    /* fseek move o ponteiro do arquivo para uma posicao relativa. recebe como parametros:
        - o ponteiro para o arquivo
        - o offset (em bytes) cujo ponteiro deve mover
        - a posicao de onde o offset deve ser aplicado
            - SEEK_SET: comeco do arquivo
            - SEEK_CUR: atual posicao do ponteiro no arquivo
            - SEEK_END: final do arquivo
        Nesse exemplo, estamos reposicionando o ponteiro no começo do arquivo: offset = 0, SEEK_SET
    */
    fseek(f, 0*sizeof(Cao), SEEK_SET);
    printf("Lendo novamente o arquivo, um recurso por vez: \n\n");
    while(fread(&c, sizeof(Cao), 1, f) == 1){ // enquanto fread conseguir ler um registro, continua
        printf("Id: %d\n", c.id);
        printf("Nome: %s\n", c.nome);
        printf("Raca: %s\n", c.raca);
        printf("Peso: %f\n\n", c.peso);
    }

    fclose(f);
}
