/*
2 - Construa uma função recursiva em C que imprima o enésimo número de Fibonnaci, 
sabendo que:
Fibonacci(0) = 0
Fibonacci(1) = 1
Fibonacci(n) = Fibonacci(n-1)+Fibonacci(n-2)
*/ 

#include<stdio.h>

int fibonacci(int n);

int main(){
    int resultado = fibonacci(5);

    printf("%d\n", resultado);

    return 0;

}

int fibonacci(int n) {
    // int resultado = 0;

    if (fibonacci(0)){
        return 0;
    }

    else if (fibonacci(1)){
        return 1;
    }

    return fibonacci(n-1)+fibonacci(n-2);

}
