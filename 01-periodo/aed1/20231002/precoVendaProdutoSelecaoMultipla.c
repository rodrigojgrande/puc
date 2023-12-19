#include <stdio.h>

main()
{
    int   opcao, podeExecutar = 0;
    float precoVendaProduto, precoFinalVendaProduto;

    do
    {
        printf("\n\nMenu de Operacoes\n");
        printf("=================================\n");
        printf("[1] Leitura do preco de venda\n");
        printf("[2] Calculo do preco de venda com 10%% de desconto\n");
        printf("[3] Calculo do preco de venda com 20%% de desconto\n");
        printf("[4] Sair\n\n");
        printf("Escolha a operacao = ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1: printf("\nDigite o preco de venda = ");
                    scanf("%f", &precoVendaProduto);
                    podeExecutar = 1;
                    break;
            case 2: if (podeExecutar == 1)
                    {
                        printf("Calculando o preco de venda com 10%% de desconto\n");
                        precoFinalVendaProduto = precoVendaProduto - (precoVendaProduto * 0.10);
                        printf("Preco final de venda = %5.2f",
                               precoFinalVendaProduto);
                    }
                    else
                        printf("Escolha a operacao [1] primeiro...\n\n");
                    break;
            case 3: if (podeExecutar == 1)
                    {
                        printf("Calculando o preco de venda com 20%% de desconto\n");
                        precoFinalVendaProduto = precoVendaProduto - (precoVendaProduto * 0.20);
                        printf("Preco final de venda = %5.2f",
                               precoFinalVendaProduto);
                    }
                    else
                        printf("Escolha a operacao [1] primeiro...\n\n");
                    break;
            case 4: printf("Terminando...\n");
                    break;
            default: printf("Operacao invalida...\n");
        }
    } while (opcao != 4);
}
