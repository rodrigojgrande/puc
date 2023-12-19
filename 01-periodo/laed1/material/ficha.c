#include <stdio.h>
// Exemplo de estrutura de dados

struct ficha {
    char         nome[256];
    unsigned int ra;
    float        media;
};
typedef struct ficha cadastro;

int main (void) {
    // struct ficha f;
    cadastro f[10];

    printf("\nInforme o nome completo: ");
    scanf("%255[^\n]s", f[0].nome);

    printf("\nInforme o RA: ");
    scanf("%u", &f[0].ra);
    getchar();

    printf("\nInforme a media: ");
    scanf("%f", &f[0].media);
    getchar();

    printf("\nDados cadastrados\n");
    printf("Nome: %s\nRA: %u\nMedia: %.2f\n", f[0].nome, f[0].ra, f[0].media);

     return(0);
}
