#include <stdio.h>
#include <stdlib.h>	// EXIT_SUCCESS
/* Comentarios */

#define SZ	32

void show(int, char []);

int main(void) {
    char linha[SZ] = {0};
    int n = 0;

    /* Limpar o terminal de texto */
    printf("\033c");
    printf("\033[H\033[J");

    while (1) {
        linha[n] = getchar();

        if ((linha[n] == '\n') || (n == (SZ - 1)))
            break;
        n++;		// n = n + 1;
    }

    show(n, linha);
    return(EXIT_SUCCESS);
}

void show(int n, char linha[]) {
    int i = 0;

    for (i = 0; i <= n; i += 1) {
        putchar(linha[i]);
    }
    return;
}
