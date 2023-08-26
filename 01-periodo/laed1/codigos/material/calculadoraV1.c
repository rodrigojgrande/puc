#include <stdio.h>
#include <stdlib.h> // Necessario para a funcao exit()

// Comentarios
// Autor:
// Funcoes para uso com a calculadora

// Tipo do retorno: float
// Nome da funcao: soma
// Parametros: duas variaveis do tipo float

// Prototipo das funcoes
float soma(float, float);
float subtracao(float, float);
float multiplicacao(float, float);
float divisao(float, float);

/* Calculadora para as quatro operacoes basicas */
int main(void) {
    float num_a, num_b, resultado;
    char op;
    int sair = 0;

    printf("\nCalculadora para operacoes basicas [+ - * /]");
    fprintf(stdout, "\nInforme o primeiro valor: ");
    scanf("%f", &num_a);
    getchar();          // Elimina o valor da tecla enter do buffer de entrada

    fprintf(stdout, "\nInforme o segundo valor: ");
    scanf("%f", &num_b);
    getchar();

    // Obrigar o usuario digitar um operador valido
    do {

        fprintf(stdout, "\nInforme a operacao [+ - * /]: ");
        // scanf("%c", &op);
        op = getchar();
        getchar();

        if ((op != '+') && (op != '-') && (op != '*') && (op != '/')) {
            printf("\nOperacao invalida!\n");
            sair = 1;
        } else
            sair = 0;

    } while (sair); // Testar se a operacao eh valida

    printf("\nOperacao solicitada: %f %c %f\n", num_a, op, num_b);

    if ( op == '+' ) {
        // resultado = num_a + num_b;
	resultado = soma(num_a, num_b);
    }

    if ( op == '-' ) {
        // resultado = num_a - num_b;
	resultado = subtracao(num_a, num_b);
    }

    if ( op == '*' ) {
        // resultado = num_a * num_b;
	resultado = multiplicacao(num_a, num_b);
    }

    if ( op == '/' ) {
	resultado = divisao(num_a, num_b);
    }

//    // Testar se a operacao eh valida
//    if (
//        (op != '+') &&
//        (op != '-') &&
//        (op != '*') &&
//        (op != '/')
//    ) {
//        printf("\nOperacao invalida!\n");
//        exit(EXIT_FAILURE);            // #include <stdlib.h>
//    }

    printf("\nO resultado eh: %.2f %c %.2f = %.3f\n\n", \
        num_a, op, num_b, resultado);

    return(0);
 }  // Final do escopo do main

// Funcoes de operacoes aritmeticas
float soma(float a, float b) { // As variaveis "a" e "b" sao locais ao escopo de soma
    float r;		// Variavel local ao escopo da funcao soma()
    r = a + b;		// Operacao realizada pela funcao
    return(r);		// Sempre devolve um componente
}

float subtracao(float a, float b) {
    return(a - b);		// Sempre devolve um componente
}

float multiplicacao(float a, float b) {
    return(a * b);		// Sempre devolve um componente
}

float divisao(float a, float b) {
     if ( b != 0 ) {
          return(a / b);
     }
     printf("\nDivisao por zero!\n");
     // EXIT_FAILURE eh igual ao valo 1
     // Failing exit status.

     exit(EXIT_FAILURE);            // #include <stdlib.h>
}

