#include <stdio.h>

main()
{
    char c;
    unsigned char u;
    int i;
    short int s;
    float f;
    double d;
    long int l;
    char ss[30];

    printf("Tamanho das variaveis em Bytes\n");
    printf("==============================\n\n");

    printf("Variavel c = %d Byte(s)\n", sizeof(c));
    printf("Variavel f = %d Byte(s)\n", sizeof(f));
    printf("Variavel d = %d Byte(s)\n", sizeof(d));
    printf("Variavel ss = %d Byte(s)\n\n", sizeof(ss));
}
