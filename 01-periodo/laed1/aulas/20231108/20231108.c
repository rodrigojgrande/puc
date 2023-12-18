/*
Descricao:
Autor:
Data:
*/

#include <stdio.h>
// Exemplo de estrutura de dados

#define SZ 10

// struct = Registro
struct ficha {
    char nome[256];
    unsigned int ra;
    float media;
};

typedef struct ficha cadastro;
// typedef = Criar um apelido para chamada

main(void) {
    // struct ficha f:

    cadastro f[SZ]; // Define uma variável F como um vetor

    printf("\nInforme o nome Completo: ");
    scanf("%255[^\n]s", f[0].nome);
    //Le no maximo 254 caractere (-1 [/0])
    //Faz a interpretacao de espacos [^\n]
    // %*c = Descarta o caractere enter pressionado (ultimo caractere)


    printf("\nInforme o RA: ");
    scanf("%u", &f[0].ra);
    getchar();

    printf("\nInforme o Media: ");
    scanf("%f", &f[0].media);
    getchar();

    printf("\nDados Cadastrados\n");
    printf("Nome: %s\nRA: $u\nMedia: %2f\n");

}
