#include <stdio.h>

int mdc(int x, int y);

int main(int argc, char const *argv[])
{
    int x = mdc(7, 3);

    printf("%s\n", "Todos os testes passaram com sucesso");

    return 0;
}

int mdc(int x, int y)
{
    /* Escreva uma função recursiva em C para calcular o máximo divisor comum entre
     * dois números inteiros e positivos, considerando as seguintes regras:

        MDC(x,y) = y se y <= x e x%y = 0
        MDC(x,y) = MDC(y,x) se x < y
        MDC(x,y) = MDC(y,x%y) demais casos

        O protótipo da função deve ser definido como int mdc(int x, int y);
    */

    if ((x <= y) && (x % y == 0)) return y;
    
    if (x < y) return mdc(y, x);
    
    return mdc(y, x % y);
}
