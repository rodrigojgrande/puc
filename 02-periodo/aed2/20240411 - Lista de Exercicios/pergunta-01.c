/*
Pergunta 01
Implemente uma calculadora simples que realiza operações de adição,
subtração, multiplicação edivisão com dois números inseridos pelo usuário.
Tudo devidamente separado em funções para cadaoperação aritmética.
*/

#include <stdio.h>

float soma(float x, float y);
float subtracao(float x, float y);
float multiplicacao(float x, float y);
float divisao(float x, float y);

int main() {
  float primeiroNumero, segundoNumero;
  int operacao;

  printf("Digite o primeiro numero: ");
  scanf("%f", &primeiroNumero);
  printf("Digite o segundo numero: ");
  scanf("%f", &segundoNumero);

  printf("\nPara escolher a operacao desejada\n");
  printf ("Digite um valor de 1 a 5: \n");
  printf ("[1] + Adicao\n");
  printf ("[2] - Subtracao\n");
  printf ("[3] * Multiplicacao\n");
  printf ("[4] / Divisao\n\n");
  scanf("%d", &operacao);
  getchar();

  float resultado;
  switch (operacao) {
    case 1:
      resultado = soma(primeiroNumero, segundoNumero);
      break;
    case 2:
      resultado = subtracao(primeiroNumero, segundoNumero);
      break;
    case 3:
      resultado = multiplicacao(primeiroNumero, segundoNumero);
    case 4:
      resultado = divisao(primeiroNumero, segundoNumero);
      break;
    default:
      printf("Operacao invalida!");
      return 1;
  }

  printf("O resultado da operacao eh: %.2f\n", resultado);
  return 0;
}

float soma(float a, float b) {
  return a + b;
}

float subtracao(float a, float b) {
  return a - b;
}

float multiplicacao(float a, float b) {
  return a * b;
}

float divisao(float a, float b) {
  return a / b;
}