#include <stdio.h>

main()
{
    int n;

    printf("Analisando a divisibilidade de um numero inteiro\n");
    printf("================================================\n\n");

    printf("Digite um numero inteiro = ");
    scanf("%d", &n);

    if (n >= 2)
    {
        printf("Calculando a divisibilidade por 2, 3 e 5\n");

        if (n % 2 == 0)
            printf("%d e divisivel por 2\n", n);
        else
            printf("%d nao e divisivel por 2\n", n);

        if (n % 3 == 0)
            printf("%d e divisivel por 3\n", n);
        else
            printf("%d nao e divisivel por 3\n", n);

        if (n % 5 == 0)
            printf("%d e divisivel por 5\n", n);
        else
            printf("%d nao e divisivel por 5\n", n);
    }
    else
    {
        printf("Numero inteiro invalido e divibilidade nao verificada...\n");
    }
}
