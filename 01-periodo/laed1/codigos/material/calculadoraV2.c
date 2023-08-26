#include <stdio.h>
#include <stdlib.h> // Necessario para a funcao exit()
#include <ctype.h>	// toupper();

// Comentarios
/* Author: Claudio Correa, 2023/05 */

// Estruturas de dados
// Criar uma estrutura de dados para armazenar os seguintes valores:
struct info {
    nome
    primeiro valor
    segundo valor
    operacao
    resultado
};

// Funcoes para uso com a calculadora
// Tipo do retorno: float
// Nome da funcao: soma
// Parametros: duas variaveis do tipo float

// Prototipo das funcoes
float soma(float, float);
float subtracao(float, float);
float multiplicacao(float, float);
float divisao(float, float);

char operador(void);
unsigned short continuar(void);

/* Calculadora para as quatro operacoes basicas */
int main(void) {
    float num_a, num_b, resultado;
    char op, nome[256] = {0};
    // int sair = 0;

    printf("\nInforme seu nome: ");
    scanf("%255[^\n]s", nome); // Maximo 5 caracteres e ateh encontra nova linha (ENTER)
    printf("\nO nome informado eh: %s\n", nome);

    do {
    printf("\nCalculadora para operacoes basicas [+ - * /]");
    fprintf(stdout, "\nInforme o primeiro valor: ");
    scanf("%f", &num_a);
    getchar();          // Elimina o valor da tecla enter do buffer de entrada

    fprintf(stdout, "\nInforme o segundo valor: ");
    scanf("%f", &num_b);
    getchar();

    // Obrigar o usuario digitar um operador valido
    op = operador();

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

    printf("\nO resultado eh: %.2f %c %.2f = %.3f\n\n", \
        num_a, op, num_b, resultado);

    } while (continuar());
    return(0);
 }  // Final do escopo do main

 // Funcoes auxiliares
 char operador(void) {
	char op = 1;

	do {
	    printf("\nInforme a operacao [+ - * /]: ");
	    op = getchar();
	    getchar();	// Esse getchar() eh necessario para consumir o ENTER que permanece no buffer

	    switch(op) {
		case '+':
		case '-':
		case '*':
		case '/':
		   break;
		default:
		   printf("\nA operacao %c eh invalida!\n", op);
		   op = 0;
		   // break;
	    }
	} while (op == 0);
	return(op);
}

unsigned short continuar(void) {
	char resp;
	int count = 5;	// Ateh 5 tentativas

	while (count) {
		printf("\nDeseja continuar [s/n]: ");
		resp = toupper(getchar());	// A funcao toupper faz parte do header #include <ctype.h>
		getchar();			        // Esse getchar() eh necessario para consumir o ENTER
                                    // que permanece no buffer

		if (resp == 'S') {
		    return(1);
		}
		if (resp == 'N') {
		    return(0);
		}
		count--;
	}
	return(0);
}
// Limpar a tela em Linux
void clearscr(void) {
	printf("\033c");
	printf("\033[H\033[J");
	return;
}

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


// Codigo antigo comentado
/*
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

#include <locale.h>

   if (strcmp(setlocale(LC_CTYPE, NULL), "C") == 0)
        setlocale(LC_CTYPE, "pt_BR");
*/
