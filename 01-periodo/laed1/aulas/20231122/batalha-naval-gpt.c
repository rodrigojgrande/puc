#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define NUM_NAVIOS 3

void exibirTabuleiro(char tabuleiro[][SIZE], char tentativasTabuleiro[][SIZE], int mostrarNavios) {
    printf("\n  ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d|", i);
        for (int j = 0; j < SIZE; j++) {
            if (!mostrarNavios && tabuleiro[i][j] == 'N') {
                printf("~ "); // Oculta os navios para o usu�rio
            } else {
                printf("%c ", tentativasTabuleiro[i][j]);
            }
        }
        printf("\n");
    }
}

void inicializarTabuleiro(char tabuleiro[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tabuleiro[i][j] = '~'; // '~' representa �gua
        }
    }
}

void colocarNavios(char tabuleiro[][SIZE]) {
    srand(time(NULL));

    for (int i = 0; i < NUM_NAVIOS; i++) {
        int linha, coluna;
        do {
            linha = rand() % SIZE;
            coluna = rand() % SIZE;
        } while (tabuleiro[linha][coluna] == 'N'); // Garante que n�o h� sobreposi��o de navios

        tabuleiro[linha][coluna] = 'N'; // 'N' representa um navio
    }
}

int todosNaviosAfundados(char tabuleiro[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (tabuleiro[i][j] == 'N') {
                return 0; // Ainda h� pelo menos um navio n�o afundado
            }
        }
    }
    return 1; // Todos os navios foram afundados
}

int main() {
    char tabuleiro[SIZE][SIZE];
    char tentativasTabuleiro[SIZE][SIZE];
    int tentativas = 0;

    inicializarTabuleiro(tabuleiro);
    colocarNavios(tabuleiro);
    inicializarTabuleiro(tentativasTabuleiro);

    while (!todosNaviosAfundados(tabuleiro)) {
        exibirTabuleiro(tabuleiro, tentativasTabuleiro, 0); // N�o mostrar os navios

        int palpiteLinha, palpiteColuna;

        printf("Digite a linha do seu palpite: ");
        scanf("%d", &palpiteLinha);

        printf("Digite a coluna do seu palpite: ");
        scanf("%d", &palpiteColuna);

        if (palpiteLinha < 0 || palpiteLinha >= SIZE || palpiteColuna < 0 || palpiteColuna >= SIZE) {
            printf("Palpite inv�lido. Tente novamente.\n");
            continue;
        }

        tentativas++;

        if (tabuleiro[palpiteLinha][palpiteColuna] == 'N') {
            printf("Parab�ns! Voc� acertou um navio em %d tentativas.\n", tentativas);
            tentativasTabuleiro[palpiteLinha][palpiteColuna] = 'N'; // 'N' representa um navio atingido
        } else {
            printf("Tiro na �gua! Tente novamente.\n");
            tentativasTabuleiro[palpiteLinha][palpiteColuna] = 'X'; // 'X' representa um tiro na �gua
        }
    }

    exibirTabuleiro(tabuleiro, tentativasTabuleiro, 1); // Mostrar os navios ao final do jogo

    printf("Voc� afundou todos os navios em %d tentativas!\n", tentativas);

    return 0;
}
