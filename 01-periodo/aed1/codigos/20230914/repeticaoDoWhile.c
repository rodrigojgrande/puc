#include <stdio.h>
#include <windows.h>

main()
{
    int n1, n2, r, opcao;

    do
    {
        system("cls");
        Sleep(2000);
        printf("Operacoes Matematicas com Dois Numeros Inteiros\n");
        printf("===============================================\n\n");

        printf("Menu de Operacoes\n");
        printf("=================\n");
        printf("[1] Adicao\n");
        printf("[2] Subtracao\n");
        printf("[3] Multiplicacao\n");
        printf("[4] Divisao\n\n");

        printf("Qual e a sua opcao = ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            printf("Digite o primeiro numero = ");
            scanf("%d", &n1);
            printf("Digite o segundo numero = ");
            scanf("%d", &n2);
            r = n1 + n2;
            printf("A soma de %d com %d e igual a %d\n", n1, n2, r);
        }

        if (opcao == 2)
        {
            printf("Digite o primeiro numero = ");
            scanf("%d", &n1);
            printf("Digite o segundo numero = ");
            scanf("%d", &n2);
            r = n1 - n2;
            printf("A subtracao de %d de %d e igual a %d\n", n2, n1, r);
        }

        if (opcao == 3)
        {
            printf("Digite o primeiro numero = ");
            scanf("%d", &n1);
            printf("Digite o segundo numero = ");
            scanf("%d", &n2);
            r = n1 * n2;
            printf("A multiplicacao de %d por %d e igual a %d\n", n2, n1, r);
        }

        if (opcao == 4)
        {
            printf("Digite o primeiro numero = ");
            scanf("%d", &n1);
            printf("Digite o segundo numero = ");
            scanf("%d", &n2);
            r = n1 / n2;
            printf("A divisao de %d por %d e igual a %d\n", n2, n1, r);
        }

        if (opcao < 1 || opcao > 5)
            printf("Opcao invalida...\n");

        system("pause");
    } while (opcao != 5);

}
