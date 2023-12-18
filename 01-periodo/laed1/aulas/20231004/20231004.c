// 1 - Escreva um coigo em C para ler um conjunto de caracteres qualquer, com até 16 elementos
// Apresente a string no terminal de texto
// 3.141532
// float pi = 3.141532;
// printf("\n PI =%.3f", pi);
// .3 = Modificador de Máscara

/*
Expressão regular
[] = Vetor, conjunto
^ = Inicio da linha
\n = Fim da linha
e
Buscar um determinado caractere dentro dos valores digitados
*/

#include <stdio.h>
#define TAM     16

    int main (void){
    char palavra[TAM];
    int i;
    char caractere;

        printf("Digite uma cadeia de caracteres: ");

        scanf("%16[^\n]s", palavra);

        printf("Informe um caractere a buscar: ");
        caractere = getchar();

        for (i = 0; palavra[i] != '\0'; i++) {
            printf("%c", palavra[i]);
            printf("\n");
        }

        printf("Tamanaho da String: %d\n", i);
        printf("\n");

        for (i = 0; palavra[i] != caractere; i++) {
            if (palavra[i] == caractere){
                printf("O caractere se encontra na posição: %d\n", i);
            }
        }



        return 0;
}
