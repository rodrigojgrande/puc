#include <stdio.h>
#include <stdlib.h>

void iniciaTabuleiro(int tabuleiro[][5])
{
    int linha, coluna;
        for(linha=0 ; linha < 5 ; linha++ )
            for(coluna=0 ; coluna < 5 ; coluna++ )
                tabuleiro[linha][coluna]=-1;
}
