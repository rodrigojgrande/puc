#include <stdio.h>

main()
{
    int n1, n2;

    printf("Comparacao entre dois numeros inteiros...\n");
    printf("=========================================\n\n");

    printf("Digite o primeiro numero inteiro = ");
    scanf("%d", &n1);
    printf("Digite o segundo numero inteiro = ");
    scanf("%d", &n2);

    printf("Testando os numeros digitados...\n");

    if (n1 <= 0 && n2 <= 0)
    {
        printf("Numeros invalidos...\n");
    }
    else
    {
        printf("Comparando os dois numeros...\n");
        if (n1 > n2)
        {
            printf("%d e maior que %d", n1, n2);
        }
        else
        {
            printf("%d e maior que %d", n2, n1);
        }
    }
}





