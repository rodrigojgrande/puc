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
    Cao c[10];
    int n;

    // abrindo um arquivo binario em modo de escrita, criando ele se nao existe e sobreescrevendo se existe
    // caso queira inserir ao final, abra em modo "ab"
    f = fopen(filename, "wb");
    if(f == NULL){
        printf("Problemas para abrir o arquivo");
        exit(1);
    }

    printf("Quantos caes voce deseja cadastrar?\n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        c[i] = registraCao();
    }

    /*  opcao 1: escrever N elementos, otimo para quando se usa vetores e estruturas de tamanho fixo
        fwrite recebe como parametros:
            - um ponteiro para a o dado a ser guardado (nesse caso, c eh um ponteiro para o comeco de um vetor)
            - o tamanho do tipo do dado a ser guardado
            - a quantidade de dados a serem guardados
            - o ponteiro para o arquivo
    */
    fwrite(c, sizeof(Cao), n, f);

    //opcao 2: escrever um elemento por vez, otimo para quando se usa vetores e/ou estruturas dinamicas (listas, etc.)
    for(int i = n-1; i >=0; i--){
        // nesse caso, envio o endereco de cada posicao do vetor, e quantidade eh 1
        fwrite(&c[i], sizeof(Cao), 1, f);
    }

    fclose(f);
}

Cao registraCao(){

    Cao c;
    int tam;

    printf("Digite as informacoes do novo cachorro:\n");

    printf("Id: ");
    scanf("%d", &c.id);
    getchar();

    printf("Nome: ");
    fgets(c.nome, 25, stdin);
    tam = strlen(c.nome);
    if(tam > 0 && c.nome[tam-1] == '\n'){
        c.nome[tam-1] = '\0';
    }

    printf("Raca: ");
    fgets(c.raca, 25, stdin);
    tam = strlen(c.raca);
    if(tam > 0 && c.raca[tam-1] == '\n'){
        c.raca[tam-1] = '\0';
    }

    printf("Peso: ");
    scanf("%f", &c.peso);

    return c;
}
