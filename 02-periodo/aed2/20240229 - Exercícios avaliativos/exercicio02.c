#include <stdio.h>

void imprimeCrescente (int n);

int main(){
    imprimeCrescente(3);
    return 0;
}

void imprimeCrescente (int n) {
    if(n > 0){
        imprimeCrescente (n -1);
    }
    printf("%d\n", n);
}
