/*
1 - Escreva uma função recursiva em C para calcular o máximo divisor comum
entre 2 números inteiros e positivos considerando a seguinte regra:
mdc(x,y) = y se y<=x e x%y = 0
mdc(x,y) = mdc(y,x) se x < y
mdc(x,y) = mdc(y, x%y)
*/

#include<stdio.h>

int mdc(int x, int y);

int main(){
    int resultado = mdc(6, 8);

    printf("%d\n", resultado);

    return 0;

}

int mdc(int x, int y) {
    // int resultado = 0;

    if (y <= x && x%y == 0){
        return y;
    }

    else if (x < y) {
        return mdc(y, x);
    }

    return mdc(y, x%y);

}
