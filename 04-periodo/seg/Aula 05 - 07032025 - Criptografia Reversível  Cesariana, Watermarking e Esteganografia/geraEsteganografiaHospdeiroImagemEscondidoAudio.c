#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

main()
{
    byte bloco;
    FILE *hospedeiro, *escondido;

    hospedeiro = fopen("hellokitty.jpg","rb+");
    escondido = fopen("audio.mp3", "rb");

    if(hospedeiro == NULL || escondido == NULL)
    {
        printf("\nEsteganografia nao pode ser realizada!\n\n");
        exit(1);
    }

    fseek(hospedeiro,0L,SEEK_END);
    while (!feof(escondido))
    {
        if (!feof(escondido))
        {
            fread(&bloco, sizeof(byte), 1, escondido);
            fwrite(&bloco, sizeof(byte), 1, hospedeiro);
        }
    }
    fclose(hospedeiro);
    fclose(escondido);
}
