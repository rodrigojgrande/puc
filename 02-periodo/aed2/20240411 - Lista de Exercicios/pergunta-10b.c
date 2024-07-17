/*
Pergunta 10 - c
b. Escreva uma função recursiva para calcular o fatorial de um número.
*/

int calcularFatorial(int numero)
{
	if (numero == 0) {
		return 1;
	}
	else { 
		return numero * calcularFatorial(numero - 1);
	}
}

/*FIM B*/