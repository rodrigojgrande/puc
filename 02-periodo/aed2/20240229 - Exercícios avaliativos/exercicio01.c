#include <stdio.h>

void imprime (int n);

int main(){
    imprime(3);
    return 0;
}

void imprime (int n) {
    printf("%d\n", n);
    if(n > 0){
        imprime (n -1);
    }
}
