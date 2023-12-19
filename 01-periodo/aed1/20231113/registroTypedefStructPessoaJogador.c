#include <stdio.h>
#include <string.h>

typedef struct
{
    char  nome[25];
    int   idade;
    float altura;
}pessoa;

typedef struct
{
    int   id;
    char  nome[30];
    float pontuacao;
}jogador;

main()
{
    pessoa p;
    jogador j[3];
    int i;

    strcpy(p.nome, "Maria");
    p.idade = 30;
    p.altura = 1.70;

    printf("Nome = %s\n", p.nome);
    printf("Idade = %d\n", p.idade);
    printf("Altura = %5.2f\n\n", p.altura);

    strcpy(j[0].nome, "Beatriz");
    j[0].id = 10;
    j[0].pontuacao = 4.5;

    strcpy(j[1].nome, "Rodrigo");
    j[1].id = 20;
    j[1].pontuacao = 5.5;

    strcpy(j[2].nome, "Maria");
    j[2].id = 30;
    j[2].pontuacao = 6.5;

    for (i=0; i < 3; i++)
         printf("O(A) jogador(a) %s, com id = %d obteve %5.2f pontos\n",
                j[i].nome, j[i].id, j[i].pontuacao);
}
