#include<stdio.h>

void anosParaDias(int anos, int *dias, int *meses){
    *dias = anos * 365;
    *meses = anos * 12;
}

int main(){
    int dias, *meses;
    anosParaDias(2, &dias, meses);
    printf("%d %d\n", dias, *meses);
}