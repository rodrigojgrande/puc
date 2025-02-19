#include <stdio.h>
#include <string.h>

// Revisão - Recursividade em C
// Rodrigo Grande

// 1. Faça uma função recursiva que faz o cálculo de potência  x^n.
// A resolução deverá ser feita através de mutiplicações sucessivas de x por x^(n-1) por exemplo:
// 8^4 = 8 * 8^3
// 8^3 = 8 * 8^2
// 8^2 = 8 * 8^1
// 8^1 = 8

int potencia(int basePotencia, int expoente) {
        if (expoente == 0) {
            return 1;
        }

        return basePotencia * potencia(basePotencia, expoente-1); // x*x^(n-1)
}

// 2. Faça uma função recursiva que calcula o fatorial de um número.
// Ex: 5! = 5 * 4 * 3 * 2 * 1.
int fatorial(int baseFatorial) {
    if (baseFatorial == 0) {
        return 1;
    }

    if (baseFatorial == 1) {
        return 1;
    }

    return baseFatorial * fatorial(baseFatorial-1); // n!=n⋅(n−1)⋅(n−2)⋅…⋅3⋅2⋅1
}

// 3. Faça uma função recursiva que inverte um string.
// A função deve receber como parâmetro o string e as posições a serem trocadas, começando das extremidades do string.
void inverterString(char string[], int inicio, int fim) {
    if (inicio >= fim) {
        return;
    }

    char temp = string[inicio];
    string[inicio] = string[fim];
    string[fim] = temp;

    inverterString(string, inicio+1, fim-1);

}

// 4. Faça uma função recursiva que soma os elementos de um vetor.
int somarVetor(int vetor[], int tamanho) {
    if (tamanho == 0) {
        return 0;
    }

    return vetor[tamanho -1] + somarVetor(vetor, tamanho-1);
}

// 5. Faça uma função recursiva que busca um valor em um vetor e retorna a sua posição, utilizando-se da estratégia de busca binária.
// Lembre-se que busca binária analiza o elemento do meio do vetor e,
// caso não seja o que procura,
// chama recursivamente para a metade do vetor da esquerda caso o numero procurado seja menor,
// ou para a metade do vetor da direita caso seja maior.
int buscaBinaria(int vetor[], int inicio, int fim, int valor){
    if (inicio > fim) {
        return -1;
    }

    int meio = (inicio + fim) / 2;

    if (vetor[meio] == valor) {
        return meio;
    } else if (valor < vetor[meio]) {
        return buscaBinaria(vetor, inicio, meio-1, valor); // Busca na metade esquerda
    } else {
        return buscaBinaria(vetor, meio+1, fim, valor); // Busca na metade direita
    }
}

int main() {
    // Valores pré-determinados do exercício 01
    int basePotencia = 8;
    int expoente = 4;

    // Valores pré-determinados do exercício 02
    int baseFatorial = 5;

    // Valores pré-determinados do exercício 03
    char string[] = "recursividade";

    // Valores pré-determinados do exercício 04
    int vetor[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]); // Tamanho do vetor total / um elemento do vetor

    // Valores pré-determinados do exercício 05
    int vetorOrdenado[] = {1, 2, 3, 5, 7, 11};
    int valorBuscado = 7;

    // Resultado exercício 01
    printf("Exercicio 01\n");
    int resultadoPotencia = potencia(basePotencia, expoente); // Resultado = 4096
    printf("%d^%d = %d\n", basePotencia, expoente, resultadoPotencia);

    // Resultado exercício 02
    printf("\nExercicio 02\n");
    int resultadoFatorial = fatorial(baseFatorial); // Resultado = 120
    printf("%d! = %d\n", baseFatorial, resultadoFatorial);

    // Resultado exercício 03
    printf("\nExercicio 03\n");
    printf("String Original: %s\n", string); // recursividade
    inverterString(string, 0, strlen(string) -1);
    printf("String Invertida: %s\n", string); //edadivisrucer

    // Resultado exercício 04
    printf("\nExercicio 04\n");
    int resultadoSomarVetor = somarVetor(vetor, tamanho); // Resultado = 15
    printf("Resultado Soma do Vetor: %d\n", resultadoSomarVetor);

    // Resultado exercício 05
    printf("\nExercicio 05\n");
    int resultadoPosicao = buscaBinaria(vetorOrdenado, 0, sizeof(vetorOrdenado) / sizeof(vetorOrdenado[0]) -1, valorBuscado); // Resultado = Posição 4
    if (resultadoPosicao != -1) {
        printf("Valor %d encontrado na posicao %d\n", valorBuscado, resultadoPosicao);
    } else {
        printf("Valor %d nao encontrado", valorBuscado);
    }

    return 0;
}
