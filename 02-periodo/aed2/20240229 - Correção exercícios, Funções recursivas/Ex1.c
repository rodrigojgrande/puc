#include<stdio.h>

int divisao(int a, int b, int *resto){
    *resto = a % b;
    return a / b;
}

int main(){
    int a = 5;
    int b = 2;
    int *resto;
    int resto2;

    int quociente = divisao(a, b, resto);
    printf("%d %d\n", quociente, *resto);

    int q2 = divisao(11, 2, &resto2);
    printf("%d %d\n", q2, resto2);
}