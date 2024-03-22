#include <stdio.h>

void somar(float a, float b, float *r);
void subtrair(float a, float b, float *r);
void dividir(float a, float b, float *r);
void multiplicar(float a, float b, float *r);
void calculadora(float a, float b, char op, float *r);

int main()
{
    float a, b, r;
    char op, sair;

    do
    {
        printf("Digite dois numeros e um operador\n");
        scanf("%f %f %c", &a, &b, &op);
        fflush(stdin);
        
        calculadora(a, b, op, &r);
        printf("Resultado: %f\n", r);
        printf("Deseja sair?\n");
        scanf("%c", &sair);
    } while (sair != 's');
    return 0;
}

void somar(float a, float b, float *r)
{
    *r = a + b;
}

void subtrair(float a, float b, float *r)
{
    *r = a - b;
}

void multiplicar(float a, float b, float *r)
{
    *r = a * b;
}

void dividir(float a, float b, float *r)
{
    if (b == 0)
    {
        printf("Divisao invalida!\n");
        *r = 0;
    }
    *r = a / b;
}

void calculadora(float a, float b, char op, float *r)
{
    switch (op)
    {
    case '+':
        somar(a, b, r);
        break;
    case '-':
        subtrair(a, b, r);
        break;
    case '/':
        dividir(a, b, r);
        break;
    case '*':
        multiplicar(a, b, r);
        break;
    default:
        printf("Operador invalido\n");
        *r = 0;
    }
}