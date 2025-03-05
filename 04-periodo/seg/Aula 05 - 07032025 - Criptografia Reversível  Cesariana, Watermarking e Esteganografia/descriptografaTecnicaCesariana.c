#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 8
typedef unsigned char byte;
void descriptografa(byte *bloco, byte *chave, int tam);

main()
{
  byte bloco[TAMANHO], chave[TAMANHO];
  char arquivoCriptografado[30], arquivoDescriptografado[30];
  int  bytesLidos;
  FILE *criptografado, *descriptografado;

  printf("Arquivo criptografado = "); scanf("%s", &arquivoCriptografado);
  printf("Arquivo para descriptografia = "); scanf("%s", &arquivoDescriptografado);
  printf("Chave com ate 8 digitos = "); scanf("%s", &chave);

  criptografado  = fopen(arquivoCriptografado,"rt");
  descriptografado = fopen(arquivoDescriptografado,"wt");
  do
  {
    bytesLidos = fread(bloco, 1, TAMANHO, criptografado);
    if(bytesLidos != 0)
    {
      descriptografa(bloco, chave, bytesLidos);
      fwrite(bloco, bytesLidos, 1, descriptografado);
    }
  } while(!feof(criptografado));

  fclose(criptografado); fclose(descriptografado);
  printf("\nDescriptografia realizada com sucesso! Verifique o arquivo descriptografado!\n\n");
}

void descriptografa(byte *bloco, byte *chave, int tam)
{
  int i;
  for(i=0; i < tam; i++)
  {
    bloco[i] = bloco[i] - chave[i];
  }
}
