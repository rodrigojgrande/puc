#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAMANHO 8
typedef unsigned char byte;
void criptografa(byte *bloco, byte *chave, int tam);

main()
{
  byte bloco[TAMANHO], chave[TAMANHO];
  char arquivoOriginal[30], arquivoCriptografado[30];
  int  bytesLidos;
  FILE *original, *criptografado;

  printf("Arquivo original = "); scanf("%s", &arquivoOriginal);
  printf("Arquivo para criptografia = "); scanf("%s", &arquivoCriptografado);
  printf("Chave com ate 8 digitos = "); scanf("%s", &chave);

  original  = fopen(arquivoOriginal,"rt");
  criptografado = fopen(arquivoCriptografado,"wt");
  do
  {
    bytesLidos = fread(bloco, 1, TAMANHO, original);
    if(bytesLidos != 0)
    {
      criptografa(bloco, chave, bytesLidos);
      fwrite(bloco, bytesLidos, 1, criptografado);
    }
  } while(!feof(original));

  fclose(original); fclose(criptografado);
  printf("\nCriptografia realizada com sucesso! Verifique o arquivo criptografado!\n\n");
}

void criptografa(byte *bloco, byte *chave, int tam)
{
  int i;
  for(i=0; i < tam; i++)
  {
    bloco[i] = bloco[i] + chave[i];
  }
}
