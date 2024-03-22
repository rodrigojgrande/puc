#include<stdio.h>

void troca(int *k, int *z){
    int ax = *k;
    *k = *z;
    *z = ax;
}

void ordena(int *a, int *b, int *c){
    if(*a > *b){
        troca(a, b);
    }
    if(*a > *c){
        troca(a, c);
    }
    if(*b > *c){
        troca(b, c);
    }
}

int main(){
    int a = 5, b = 4, c = 1;

    ordena(&a, &b, &c);
    printf("%d %d %d\n", a, b, c);
}