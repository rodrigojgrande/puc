#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO	5

struct porcao {
   char prato[256];
   float valor;
   unsigned int meia;
};
typedef struct porcao porcao_t;

void inicializa_porcao(porcao_t principal[]);

int main(void) {
    porcao_t principal[TAMANHO] = {0};

    inicializa_porcao(principal);

    printf("pricipal[0].prato = %s\n", principal[0].prato);
    printf("principal[0].valor = %.2f\n", principal[0].valor);
    printf("principal[0].meia = %u\n\n", principal[0].meia);


    printf("pricipal[4].prato = %s\n", principal[4].prato);
    printf("principal[4].valor = %.2f\n", principal[4].valor);
    printf("principal[4].meia = %u\n\n", principal[4].meia);
    return 0;
}

void inicializa_porcao(porcao_t principal[]) {

      strncpy(principal[0].prato, "batata frita", 12);
      principal[0].valor = 12.5;
      principal[0].meia = 0;

      strncpy(principal[1].prato, "tilapia", 7);
      principal[1].valor = 10.5;
      principal[1].meia = 0;

      strncpy(principal[2].prato, "salada", 6);
      principal[2].valor = 8.25;
      principal[2].meia = 0;

      strncpy(principal[3].prato, "brocolis", 8);
      principal[3].valor = 150.85;
      principal[3].meia = 0;

      strncpy(principal[4].prato, "polenta", 7);
      principal[4].valor = 4.5;
      principal[4].meia = 0;

      return;
}

