#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

main()
{
   byte bloco;
   int  contadorBytes=0;
   char marca[7]="CRYPTO";
   FILE *original, *criptografado;

   original = fopen("foto.jpg","rb");
   criptografado = fopen("fotocript.jpg","wb");

   if(original == NULL || criptografado == NULL)
   {
      printf("\nArquivo original nao pode ser aberto ou criptografia nao pode ser gerada!\n\n");
      exit(1);
   }

   printf("TECNICA DE CRIPTOGRAFIA COM WATERMARKING\n");
   printf("========================================\n\n");
   printf("Criptografando o arquivo de imagem...\n\n");
   while (!feof(original))
   {
         if (!feof(original))
         {
             fread(&bloco, sizeof(byte), 1, original);
             contadorBytes++;
             fwrite(&bloco, sizeof(byte), 1, criptografado);
             if (contadorBytes == 256)
                 fwrite(&marca, sizeof(byte), 6, criptografado);
         }
   }

   printf("Criptografia realizada com sucesso! Verifique o arquivo criptografado!\n\n");
   fclose(original);
   fclose(criptografado);
}
