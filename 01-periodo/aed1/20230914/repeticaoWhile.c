#include <stdio.h>
#include <windows.h>

main()
{
    int n1, n2, r, opcao=0;

    while (opcao != 5)
    {
        system("cls");
        printf("Operacoes Matematicas com Dois Numeros Inteiros\n");
        printf("===============================================\n\n");

        Sleep(2000);

        printf("Menu de Opcoes\n");
        printf("[1] Adicao\n");
        printf("[2] Subtracao\n");
        printf("[3] Multiplicacao\n");
        printf("[4] Divisao\n");
        printf("[5] Sair\n\n");
        printf("Escolha a sua opcao = ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            printf("Digite o primeiro numero = ");
            scanf("%d", &n1);
            printf("Digite o segundo numero = ");
            scanf("%d", &n2);
            r = n1 + n2;
            printf("Resultado da soma = %d\n", r);
        }

        if (opcao == 2)
        {
            printf("Digite o primeiro numero = ");
            scanf("%d", &n1);
            printf("Digite o segundo numero = ");
            scanf("%d", &n2);
            r = n1 - n2;
            printf("Resultado da subtracao = %d\n", r);
        }

        if (opcao == 3)
        {
            printf("Digite o primeiro numero = ");
            scanf("%d", &n1);
            printf("Digite o segundo numero = ");
            scanf("%d", &n2);
            r = n1 * n2;
            printf("Resultado da multiplicacao = %d\n", r);
        }

        if (opcao == 4)
        {
            printf("Digite o primeiro numero = ");
            scanf("%d", &n1);
            printf("Digite o segundo numero = ");
            scanf("%d", &n2);
            r = n1 / n2;
            printf("Resultado da divisao = %d\n", r);
        }

        if (opcao < 1 || opcao > 5)
        {
            //exit(1);
            printf("Opcao invalida...\n\n");
        }

        system("pause");
    }
}
