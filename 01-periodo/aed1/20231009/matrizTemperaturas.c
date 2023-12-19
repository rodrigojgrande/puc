#include <stdio.h>

main()
{
    int i,j,maior,menor,diaMaior,diaMenor;
    int t[5][3]={{0,0,0},
                 {0,0,0},
                 {0,0,0},
                 {0,0,0},
                 {0,0,0}};
    char dias[5][14]={"segunda-feira","terca-feira","quarta-feira",
                      "quinta-feira","sexta-feira"};

    printf("Apresentando o estado inicial da matriz...\n\n");
    for (i=0; i < 5; i++)
    {
        for (j=0; j < 3; j++)
        {
            t[i][j] = 0;
            printf("%d ", t[i][j]);
        }
        printf("\n\n");
    }

    printf("Gerando aleatoriamente as temperaturas...\n\n");
    srand(time(NULL));
    for (i=0; i < 5; i++)
    {
        for (j=0; j < 3; j++)
        {
            t[i][j] = rand() % 50;
            //if (t[i][j] > 0 && j % 2 == 0)
                //t[i][j] = -t[i][j];
            printf("%5d", t[i][j]);
        }
        printf("\n\n");
    }

    printf("Localizando a menor e a maior temperatura\n\n");
    menor = t[0][0];
    maior = t[0][0];
    for (i=0; i < 5; i++)
    {
        for (j=0; j < 3; j++)
        {
            if (t[i][j] < menor)
            {
                menor = t[i][j];
                diaMenor = i;
            }

            if (t[i][j] > maior)
            {
                maior = t[i][j];
                diaMaior = i;
            }
        }
    }
    printf("Menor temperatura = %d\n", menor);
    printf("Dia da menor temperatura = %s\n", dias[diaMenor]);
    printf("Maior temperatura = %d\n", maior);
    printf("Dia da maior temperatura = %s\n\n", dias[diaMaior]);

}
