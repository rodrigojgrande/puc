#include <stdlib.h>

int main(void) {
    // Declaração de variaveis locais
    int numero = 0;
    unsigned short int resto;

    printf("\nPrograma para identificar numero par!:");

    while(1){
        printf("\nInforme um numero inteiro: ");
        scanf("%d", &numero);   // & endereco de memoria chamado numero
        getchar();              // para descartar o valor da tecla ENTER

        resto = numero % 2;

        if(resto) {
            printf("\nO número %d eh impar!", numero);
        }

        if(!resto) { // if (resto == 0)
            printf("\nO número %d eh par!", numero);
        }
    }
    return 0;
}
