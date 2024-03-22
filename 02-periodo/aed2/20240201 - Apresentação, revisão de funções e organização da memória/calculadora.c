#include <stdio.h>

float somar(float a, float b);
float subtrair(float a, float b);
float dividir(float a, float b);
float multiplicar(float a, float b);
float calculadora(float a, float b, char op);

int main()
{
    float a, b;
    char op, sair;

    do
    {
        printf("Digite dois numeros e um operador\n");
        scanf("%f %f %c", &a, &b, &op);
        fflush(stdin);

        printf("Resultado: %f\n", calculadora(a, b, op));
        printf("Deseja sair?\n");
        scanf("%c", &sair);
    } while (sair != 'n');
    return 0;
}

float somar(float a, float b)
{
    return a + b;
}

float subtrair(float a, float b)
{
    return a - b;
}

float multiplicar(float a, float b)
{
    return a * b;
}

float dividir(float a, float b)
{
    if (b == 0)
    {
        printf("Divisao invalida!\n");
        return 0;
    }
    return a / b;
}

float calculadora(float a, float b, char op)
{
    switch (op)
    {
    case '+':
        return somar(a, b);
    case '-':
        return subtrair(a, b);
    case '/':
        return dividir(a, b);
    case '*':
        return multiplicar(a, b);
    default:
        printf("Operador invalido\n");
        return 0;
    }
}