#include <stdio.h>

main()
{
    int t[6]={0,0,0,0,0,0}, i, menor, maior, soma;
    float media;

    printf("Mostrando os valores armazenados no vetor...\n");
    for (i=0; i < 6; i++)
    {
        printf("%d\n", t[i]);
    }

    printf("Gerando as temperaturas aleatoriamente...\n");
    srand(time(NULL));
    for (i=0; i < 6; i++)
    {
        t[i] = rand() % 50;
        printf("%3d", t[i]);
    }

    printf("\n\nProcurando a menor e a maior temperatura\n");
    menor = t[0];
    maior = t[0];
    soma = t[0];
    for (i=1; i < 6; i++)
    {
        if (t[i] < menor)
            menor = t[i];
        if (t[i] > maior)
            maior = t[i];

        soma = soma + t[i];
    }

    printf("A menor temperatura = %d\n", menor);
    printf("A maior temperatura = %d\n", maior);
    printf("A soma das temperaturas = %d\n\n", soma);

    media = (float) soma / 6;
    printf("A media das temperaturas = %5.2f\n\n", media);
}
