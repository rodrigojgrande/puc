#include <stdio.h>

int main(void) {
    float primeiroValor, segundoValor;
    double total;
    char opcao;

    // Entrada de dados do usuário
    printf("Digite o primeiro valor = ");
    scanf("%f", &primeiroValor);

    printf("Digite o segundo valor = ");
    scanf("%f", &segundoValor);

    // Limpar o buffer de entrada antes de usar getchar
    while (getchar() != '\n') {}

    // Menu de Operações
    printf("\n\nMenu de Operacoes\n");
    printf("=================================\n");
    printf("[+] Adicao\n");
    printf("[-] Subtracao\n");
    printf("[*] Multiplicacao\n");
    printf("[/] Divisao\n\n");
    printf("[5] Sair\n\n");

    printf("Escolha a operacao = ");
    opcao = getchar();

    switch(opcao) {
        case '+':
            total = primeiroValor + segundoValor;
            printf("\nA soma entre o valor %.2f e %.2f eh igual a %.2lf", primeiroValor, segundoValor, total);
            break;

        case '-':
            total = primeiroValor - segundoValor;
            printf("\nA subtracao entre o valor %.2f e %.2f eh igual a %.2lf", primeiroValor, segundoValor, total);
            break;

        case '*':
            total = primeiroValor * segundoValor;
            printf("\nA multiplicacao entre o valor %.2f e %.2f eh igual a %.2lf", primeiroValor, segundoValor, total);
            break;

        case '/':
            if (segundoValor != 0) {
                total = primeiroValor / segundoValor;
                printf("\nA divisao entre o valor %.2f e %.2f eh igual a %.2lf", primeiroValor, segundoValor, total);
            } else {
                printf("\nErro: Divisao por zero.");
                do {
                    printf("\nDigite o segundo valor (diferente de zero) = ");
                    scanf("%f", &segundoValor);
                } while (segundoValor == 0); // Repete até que o segundoValor seja diferente de zero

                total = primeiroValor / segundoValor;
                printf("\nA divisao entre o valor %f e %f eh igual a %f", primeiroValor, segundoValor, total);
            }
            break;

        case '5':
            return 0; // Sair do programa

        default:
            printf("\nOperacao Invalida");
    }

    return 0;
}
