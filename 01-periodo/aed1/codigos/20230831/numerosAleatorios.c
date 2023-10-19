#include <stdio.h>
#include <stdlib.h>

main()
{
    int n;

    printf("Gerando um numero aleatorio...\n");

    //srand(clock());
    srand(time(NULL));
    n = rand() % 10;
    printf("Numero gerado = %d\n\n", n);
}
