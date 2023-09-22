
#include <stdio.h> //Arquivo de Cabeçalho (header)

/*
Autor:
Data:
Descrição: Exemplo de tamnoh dos tipos de variaveis
*/

int main(void) {
	// Declaracdao de variaveis locais
	char caractere;
	int contador;
	int idade;
	float tempo;
	double distancia;
	unsigned short int ano; //Unsigned => Sem Sinal

	printf("\n Esse eh o texto apresentado no terminal. \n\n");
	printf("Tamanho do tipo int:\t\t\t\t %ld bytes\n", sizeof(int)); //%d => Máscara para decimal inteiro
	printf("Tamanho do tipo int:\t\t\t\t %ld bytes\n", sizeof(contador));
	printf("Tamanho do tipo char:\t\t\t\t %ld bytes\n", sizeof(caractere));
	printf("Tamanho do tipo float:\t\t\t\t %ld bytes\n", sizeof(float));
	printf("Tamanho do tipo double:\t\t\t\t %ld bytes\n", sizeof(double));
	printf("Tamanho do tipo unsigned short int:\t\t %ld bytes\n", sizeof(ano));
	printf("Tamanho da soma das variaveis:\t\t\t %ld bytes\n", sizeof(caractere)+sizeof(contador)+sizeof(idade)+sizeof(tempo)+sizeof(distancia)+sizeof(ano));

	// \n => Caractere de Controle

	return 0;
}

// PARA CASA: FAZER APARECER OS VALORES NA MESMA COLUNA DA QUANTIDADE DE BYTES E RESOLVER MENSAGENS DO COMPILADOR
