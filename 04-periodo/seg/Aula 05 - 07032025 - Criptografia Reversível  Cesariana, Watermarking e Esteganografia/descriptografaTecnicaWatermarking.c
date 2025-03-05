#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

main()
{
   byte bloco;
   int  contadorBytes=0;
   FILE *criptografado, *descriptografado;

   criptografado = fopen("fotocript.jpg","rb");
   descriptografado = fopen("novaimagem.jpg","wb");

   if(criptografado == NULL || descriptografado == NULL)
   {
      printf("\nArquivo criptografado nao pode ser aberto ou descriptografia nao pode ser gerada!\n\n");
      exit(1);
   }

   printf("\nTECNICA DE DESCRIPTOGRAFIA COM WATERMARKING\n");
   printf("=============================================\n\n");
   printf("Descriptografando a imagem...\n\n");

   contadorBytes = 0;
   while (!feof(criptografado))
   {
         if (!feof(criptografado))
         {
             fread(&bloco, sizeof(byte), 1, criptografado);
             contadorBytes++;
             if (contadorBytes > 256 && contadorBytes <= 262)
                 continue;
             fwrite(&bloco, sizeof(byte), 1, descriptografado);
         }
   }
   fclose(criptografado);
   fclose(descriptografado);
   printf("Descriptografia realizada com sucesso! Verifique o arquivo descriptografado!\n\n");
}

