#include <stdio.h>

int v;

main()
{
    int i1, i2, *pi;

    printf("Endereco das variaveis...\n\n");

    printf("Variavel v = %X  %d\n\n", &v, &v);
    printf("Variavel i1 = %X  %d\n\n", &i1, &i1);
    printf("Variavel i2 = %X  %d\n\n", &i2, &i2);
    printf("Variavel pi = %X  %d\n\n", &pi, &pi);

    i1 = 10;
    pi = &i1;
    i2 = *pi;

    printf("Valor da variavel i2 = %d\n\n", i2);
}
