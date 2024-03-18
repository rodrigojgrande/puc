#include<stdio.h>

int fatorial(int n);

int main(){
    fatorial(5);

    printf("%d", fatorial(5));

    return 0;

}

int fatorial(int n) {
    // int resultado = 0;

    if (n <= 1){
        return 1;
    }

    return n * fatorial(n-1);
}