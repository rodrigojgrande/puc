#include <stdio.h>
#include <string.h>
#include <windows.h>

main()
{
    char frase[41];
    int  i, contadorEspacos;

    printf("Analisador de Frase...\n");
    printf("======================\n\n");
    printf("Digite uma frase com ate 40 caracteres = ");
    gets(frase);

    printf("Frase digitada = %s\n", frase);
    printf("Tamanho da frase e de %d caracteres\n\n",
           strlen(frase));

    printf("Convertendo a frase para maiusculas...\n");
    for (i=0; i < strlen(frase); i++)
    {
        frase[i] = toupper(frase[i]);
        printf("%c", frase[i]);
        Sleep(250);
    }

    printf("\n\nApresentando a frase invertida...\n\n");
    for (i=strlen(frase)-1; i >= 0; i--)
    {
        printf("%c", frase[i]);
        Sleep(250);
    }

    printf("\n\nContando os espacos em branco...\n\n");
    contadorEspacos = 0;
    for (i=0; i < strlen(frase); i++)
    {
        if (frase[i] == ' ')
            contadorEspacos++;
    }
    printf("Total de espacos em branco = %d\n\n", contadorEspacos);
}
