#include <stdio.h>

//int geraNumero(int faixa);
void geraNumero(int faixa, int *n);

main()
{
    int f, r;
    printf("Informe a faixa de valores = ");
    scanf("%d", &f);

    geraNumero(f, &r);
    printf("Numero gerado = %d\n\n", r);
}

void geraNumero(int faixa, int *n)
{
    srand(time(NULL));
    *n = rand() % faixa;
}
