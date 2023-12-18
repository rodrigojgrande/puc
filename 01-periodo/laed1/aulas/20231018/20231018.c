/*
1 - Implementar uma calculadora para as 4 operações básicas, observando os seguintes requisitos
a - utilizar os caracteres + - * / para as operações
b - A operação deve ser recebida com getchar();
c - Utilizar a estrutura de decisão switch/case
d - O resultado deve ser armazenado em uma variável e apresentado
e - Fazer uso de um laço do/while
f - pesquisar sobre struct
*/

/*
Descricao:
Autor:
Data:
*/

// Para casa - If Else
// Do while - Usar uma funcao para fazer o usuario sair do loop

#include <stdio.h>
#include <ctype.h>

// Prototipos das funcoes
unsigned short int continuar(void);

main(void) {

    float primeiroValor, segundoValor;
    double total;
    char opcao;
    unsigned int flag = 0;

    do {

        // Entrada de dados do usuario
        printf("\nDigite o primeiro valor = ");
        scanf("%.2f", &primeiroValor); // Guarda o valor na area de memoria chamada primeiroValor
        getchar(); // Descartar o Enter

        printf("\nDigite o segundo valor = ");
        scanf("%.2f", &segundoValor);
        getchar();

        printf("\n\nMenu de Operacoes\n");
        printf("=================================\n");
        printf("[+] Adicao\n");
        printf("[-] Subtracao\n");
        printf("[*] Multiplicacao\n");
        printf("[/] Divisao\n\n");
        printf("[5] Sair\n\n");

        printf("Escolha a operacao = ");
        opcao = getchar();
        getchar();


        switch(opcao) {

            case '+':
                total = primeiroValor + segundoValor;
                printf("\nA soma entre o valor %f e %f eh igual a %lf", primeiroValor, segundoValor, total);
                break;

            case '-':
                total = primeiroValor - segundoValor;
                printf("\nA subtracao entre o valor %f e %f eh igual a %lf", primeiroValor, segundoValor, total);
                break;

            case '*':
                total = primeiroValor * segundoValor;
                printf("\nA multiplicacao entre o valor %f e %f eh igual a %lf", primeiroValor, segundoValor, total);
                break;

            case '/':
                if (segundoValor != 0) {// Tratar divisao por 0
                    total = primeiroValor / segundoValor;
                    printf("\nA divisao entre o valor %f e %f eh igual a %lf", primeiroValor, segundoValor, total);
                    break;
                } else {

                    // Para casa - Tratar a divisao por zero
                    flag = 1;
                }

            default:
                flag = 1;
                printf("\nOperacao Invalida");

        } // Final do Switch Case

        if (flag == 0) {
            printf("\nO Resultado da Operacao: %.2f %c %.2f = %.3rlf", primeiroValor, opcao, segundoValor, total);
        } else {
            flag = 0;
            printf("\nOperacao invalida ou Divisao por zero!\n");
        }


     } while (continuar());

    return 0;

} // Final do Main

// Funcoes Auxiliares

// int tolower(int c);

unsigned short int continuar(void){
    char resposta = 's'; // Declaracao de variavel local

    printf("\nDeseja continuar? [s/n]");

    resposta = tolower(getchar());

    if (resposta == 's') {
        return(1);
    }

    return(0);
}
