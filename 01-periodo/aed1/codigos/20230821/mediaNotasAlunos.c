#include <stdio.h>
#include <locale.h>
main()
{
    int   idade;
    float n1, n2, n3, n4, m;
    char  nome[30];

    setlocale(LC_ALL,"Portuguese");
    printf("Calculando a média das notas\n");
    printf("============================\n\n");

    printf("Digite o nome do(a) aluno(a) = ");
    gets(nome);
    printf("Digite a idade do(a) aluno(a) = ");
    scanf("%d", &idade);
    printf("Digite a primeira nota = ");
    scanf("%f", &n1);
    printf("Digite a segunda nota = ");
    scanf("%f", &n2);
    printf("Digite a terceira nota = ");
    scanf("%f", &n3);
    printf("Digite a quarta nota = ");
    scanf("%f", &n4);

    m = (n1 + n2 + n3 + n4)/4;

    printf("Resultados\n");
    printf("============================\n");
    printf("O(A) aluno(a) %s, com idade %d anos obteve média = %5.2f\n\n",
           nome, idade, m);
}
