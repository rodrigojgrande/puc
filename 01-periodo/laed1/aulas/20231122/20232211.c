/*Nome: */
#include <stdio.h>
#include <stdlib.h> // Para usar exit()

int main() {
    int c; //EOF eh um valor inteiro (-1)
    FILE *entrada;

    //entrada = fopen("dados.txt", "r"); // Ler o Arquivo
    entrada = fopen("texto.txt", "w"); // Criar eo Arquivo
    if (entrada == NULL)
        exit(EXIT_FAILURE);

    do {
        // c = getc(stdin); // Le da entrada padrao (teclado)
        c = getc(entrada); // Le do arquivo

        if (c != EOF){
            putc(c, stdout);
        }

    } while(c != EOF);

    printf("\n");

    fclose(entrada);

    return EXIT_SUCCESS;
}
