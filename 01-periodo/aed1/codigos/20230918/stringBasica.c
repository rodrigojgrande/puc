#include <stdio.h>
#include <string.h>

main()
{
    //char s[11];
    char s[11] = "Computacao";
    //char s[11] = "Computacao na PUC Minas";

    printf("Manipulando strings\n");
    printf("===================\n\n");

    printf("%s\n\n", s);

    printf("Digite uma sequencia com ate 10 caracteres = ");
    gets(s);
    printf("%s\n\n", s);

    printf("Primeiro caractere da string = %c\n", s[0]);
    printf("Ultimo caractere da string = %c\n",
           s[strlen(s)-1]);

    s[0] = toupper(s[0]);
    printf("Primeiro caractere da string = %c\n", s[0]);
    printf("%s\n\n", s);
}
