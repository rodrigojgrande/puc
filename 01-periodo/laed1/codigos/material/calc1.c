#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Comentarios

// Definicoes e prototipos

int main(void) {
   float a, b, r;
   char op, continuar = 's';
   unsigned short int flag = 1;

   printf("\nCalculadora para as quatro operacoes basicas\n");

   do {
	printf("\nInforme o primeiro valor: ");
	scanf("%f", &a);
        getchar();

	printf("\nInforme o segundo valor: ");
	scanf("%f", &b);
        getchar();

	printf("\nInforme a operacao [+ - * /]: ");
	op = getchar();
        getchar();

	// while ( (op != '+') && (op != '-') && (op != '*') && (op != '/')) {
	//	printf("\nInforme NOVAMENTE a operacao [+ - * /]: ");
	//	op = getchar();
	//       getchar();
	// }

	switch(op) {
		case '+':
			r = a + b;
			break;
		case '-':
			r = a - b;
			break;
		case '*':
			r = a * b;
			break;
		case '/':
			if (b != 0) {
				r = a / b;
			}
			break;
		default:
			printf("\nOperador invalido!\n");
			flag = 0;
	}
	if (flag) {
		if ((op == '/') && (b == 0)) {
			printf("\nDivisao por zero!\n");
		} else {
			printf("\nO resultado da operacao %.2f %c %.2f eh: %.3f\n", a, op, b, r);
		}
	}

	printf("\nCalcular novamente? [s n]: ");
	continuar = tolower(getchar());
	getchar();
	flag = 1;
   } while(continuar == 's');
   return(0);
}



/*

#include <stdio.h>

int main(void) {
	char c;

	printf("\nInforme uma letra: ");
	c = getchar();
	getchar();

	if (c >= 97) && (c <= 'z')	// 97 == 'a'
		c = c -32		// Verificar a tabela ascii

//	if (c == 'A') {
//		printf("\nO caractere %c eh vogal!", c);
//	} else if (c == 'E') {
//		printf("\nO caractere %c eh vogal!", c);
//	} else if (c == 'I') {
//		printf("\nO caractere %c eh vogal!", c);
//	} else if (c == 'O') {
//		printf("\nO caractere %c eh vogal!", c);
//	} else if (c == 'U') {
//		printf("\nO caractere %c eh vogal!", c);
//	} else {
//		printf("\nO caractere %c NAO eh vogal!", c);
//	}

	switch(c) {
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			printf("\nO caractere %c eh vogal!", c);
			break;
		default:
			printf("\nO caractere %c NAO eh vogal!", c);
	}

	return(0);
}
*/

