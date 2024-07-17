/*
Pergunta 05
Solicite ao usuário que insira a base e a altura de um triângulo
e calcule e exiba a área desse triângulo (Área = 0.5 * Base * Altura).
*/

#include <stdio.h>

float calcularArea(float base, float altura);

int main() {
    float base, altura;

    printf("Insira a base do triangulo: ");
    scanf("%f", &base);

    printf("Insira a altura do triangulo: ");
    scanf("%f", &altura);

    float area = calcularArea(base, altura);

    printf("A area do triangulo com base %.2f e altura %.2f eh: %.2f\n", base, altura, area);

    return 0;
}

float calcularArea(float base, float altura){
    return  0.5 * base * altura;
}
