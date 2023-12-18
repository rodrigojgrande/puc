/*
Tarefa: Buscar um caractere em uma string

Integrantes:
Julia Romao
Rodrigo Grande
*/


#include <stdio.h>
#define TAM     16

int main(void) {
    char palavra[TAM];
    int i;
    char caractere; // Variavel para armazenar o caractere a ser procurado

    printf("Digite uma cadeia de caracteres: ");
    scanf("%16[^\n]s", palavra);

    printf("\n");

    printf("Informe um caractere a buscar: ");
    scanf(" %c", &caractere);  //O espaco antes do %c serve para consumir possiveis espacos em branco

    printf("\n");

    for (i = 0; palavra[i] != '\0'; i++) {
        printf("%c\n", palavra[i]);
    }

    printf("\n");

    printf("Tamanho da String: %d\n\n", i);

    // Logica da Tarefa: Buscar um caractere em uma string
    for (i = 0; palavra[i] != '\0'; i++) {
        if (palavra[i] == caractere) { // Se achar o caractere na palavra
            printf("O caractere '%c' se encontra na posicao: %d\n", caractere, i);
            break;  // Se encontrar, pare o loop
        }
    }

    if (palavra[i] == '\0') { // Se nao achar o caractere na palavra
        printf("O caractere '%c' nao foi encontrado na string.\n", caractere);
    }

    return 0;
}
