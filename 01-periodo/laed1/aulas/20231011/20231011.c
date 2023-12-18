/*
1 - Implementar uma calculadora para as 4 operações básicas, observando os seguintes requisitos
a - utilizar os caracteres + - * / para as operações
b - A operação deve ser recebida com getchar();
c - Utilizar a estrutura de decisão switch/case
d - O resultado deve ser armazenado em uma variável e apresentado
e - Fazer uso de um laço do/while
*/

/*
Descricao:
Autor:
Data:
*/

// Para casa - If Else
// Do while - Usar uma funcao para fazer o usuario sair do loop

#include <stdio.h>

main(void) {

    float primeiroValor, segundoValor;
    double total;
    char opcao;

    // Entrada de dados do usuario
    printf("\nDigite o primeiro valor = ");
    scanf("%.2f", &primeiroValor); // Guarda o valor na area de memoria chamada primeiroValor
    getchar(); // Descartar o Enter

    printf("\nDigite o segundo valor = ");
    scanf("%.2f", &segundoValor);
    getchar();

    //do {

        printf("\n\nMenu de Operacoes\n");
        printf("=================================\n");
        printf("[+] Adição\n");
        printf("[-] Subtração\n");
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
                }
            default:
                printf("\nOperacao Invalida");

        } // Final do Switch Case

        printf("\nO Resultado da Operacao: %.2f %c %.2f = %.3rlf", primeiroValor, opcao, segundoValor, total);


    //} while (opcao != 5);

    return 0;
} // Final do Main
