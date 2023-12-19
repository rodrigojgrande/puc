// O tabuleiro entra com o primeiro colchetes vazio
void iniciarTabuleiro(int tabuleiro[][5]){
    int linha, coluna;

    printf("\n");
    printf("\n");
    printf("D E B U G   T A B U L E I R O\n");

    for(linha = 0 ; linha < 5 ; linha++ ) {
        for(coluna=0 ; coluna < 5 ; coluna++ ) {
            tabuleiro[linha][coluna] = -1;
            printf("\t%d", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }
}


void debugMatriz(int tabuleiro[][5]){
    printf("\n");
    printf("\n");
    printf("D E B U G   M A T R I Z\n");
    printf("\t1 \t2 \t3 \t4 \t5");
    printf("\n");
    for (int i = 0; i < 5; i++) {
        printf("%d",i + 1);
        for (int j = 0; j < 5; j++) {
            printf("\t%d", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
}


int main() {
    int tabuleiro[5][5];
    int linha, coluna;

    iniciarTabuleiro(tabuleiro);
    debugMatriz(tabuleiro);

    printf("\n");
    printf("\n");
    printf("D E B U G   M A I N\n");

    for(linha = 0 ; linha < 5 ; linha++ ) {
        for(coluna=0 ; coluna < 5 ; coluna++ ) {
            tabuleiro[linha][coluna] = -1;
            printf("\t%d", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }
}
