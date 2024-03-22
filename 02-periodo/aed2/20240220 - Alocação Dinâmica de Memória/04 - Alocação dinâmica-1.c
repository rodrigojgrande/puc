#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[50];
    float salario;
} Pessoa;

int main()
{

    float *p, *v, valor = 10.5;
    int *pInt, tam;
    char *pChar;
    Pessoa *pPessoa;

    // atribuicao normal de ponteiro, alocacao no escopo da main
    p = &valor;
    printf("O valor de p eh: %f\n", *p);
    printf("O valor de valor eh: %f\n", valor);
    printf("O endereco de valor eh: %d\n", &valor);
    printf("p aponta para o endereco: %d\n", p);
    printf("p esta no endereco: %d\n\n", &p);

    // ---------------------------------------------------------------------------------------------------

    // alocacao dinamica:
    //  um espaco do tamanho de um float eh alocado na heap, e seu endereco eh retornado para o ponteiro p
    p = (float *)malloc(sizeof(float));
    if (p == NULL)
    { // verificacao se houve erro na alocacao
        printf("ERRO: memoria insufiente");
        exit(1); // se sim, interrompe a execucao do programa
    }
    *p = 20.3; // o endere�o apontado por p, que eh um espaco de memoria na heap, recebe 20.3
    printf("O valor de p eh: %f\n", *p);
    printf("O valor de valor eh: %f\n", valor);
    printf("O endereco de valor eh: %d\n", &valor);
    printf("p aponta para o endereco: %d\n", p);
    printf("p esta no endereco: %d\n\n", &p);
    free(p); // libera a memoria, para evitar "vazamento de memoria" (memory leakage)

    // ---------------------------------------------------------------------------------------------------

    // verificando o tamanho dos tipos
    printf("O tamanho de float eh: %d\n", sizeof(float));     // 4B
    printf("O tamanho de int eh: %d\n", sizeof(int));         // 4B
    printf("O tamanho de char eh: %d\n", sizeof(char));       // 1B
    printf("O tamanho de Pessoa eh: %d\n\n", sizeof(Pessoa)); // 56B

    // ---------------------------------------------------------------------------------------------------

    // alocando um inteiro na heap
    pInt = (int *)malloc(sizeof(int));
    if (pInt == NULL)
    {
        printf("ERRO: memoria insufiente");
        exit(1);
    }
    *pInt = 600;
    printf("O valor de pInt eh: %d\n", *pInt);
    printf("pInt aponta para o endereco: %d\n", pInt);
    printf("pInt esta no endereco: %d\n\n", &pInt);
    free(pInt);

    // ---------------------------------------------------------------------------------------------------

    // alocando um char na heap
    pChar = (char *)malloc(sizeof(char));
    if (pChar == NULL)
    {
        printf("ERRO: memoria insufiente");
        exit(1);
    }
    *pChar = 'Z';
    printf("O valor de pChar eh: %c\n", *pChar);
    printf("pChar aponta para o endereco: %d\n", pChar);
    printf("pChar esta no endereco: %d\n\n", &pChar);
    free(pChar);

    // ---------------------------------------------------------------------------------------------------

    // alocando uma Pessoa na heap
    pPessoa = (Pessoa *)malloc(sizeof(Pessoa));
    if (pPessoa == NULL)
    {
        printf("ERRO: memoria insufiente");
        exit(1);
    }

    pPessoa->salario = 5600.90; // lembrando, ponteiro de struct usa a notacao -> ao inves de .
    strcpy(pPessoa->nome, "Speed Racer");

    printf("A pessoa %s recebe %f reais\n", pPessoa->nome, pPessoa->salario);
    printf("pPessoa aponta para o endereco: %d\n", pPessoa);
    printf("pPessoa esta no endereco: %d\n\n", &pPessoa);
    free(pPessoa);

    // ---------------------------------------------------------------------------------------------------

    // alocando um vetor de inteiro na heap
    tam = 15;                                 // vetor de 15 posicoes
    v = (float *)malloc(tam * sizeof(float)); // 15 * 4B = 60B
    if (v == NULL)
    {
        printf("ERRO: memoria insufiente");
        exit(1);
    }

    // apenas a alocacao eh diferente em um vetor dinamico, as demais operacoes continuam as mesmas
    for (int i = 0; i < tam; i++)
    { // preenchendo o vetor
        v[i] = i * 2;
    }
    for (int i = 0; i < tam; i++) // exibindo o vetor
        printf("%f\t", v[i]);

    free(v);

    printf("\n\nPonteiro de pessoa:\n");

    Pessoa elon, *mosca, *pessoas;
    elon.salario = 5000.0; // por segundo
    strcpy(elon.nome, "Elon");

    mosca = (Pessoa *)malloc(sizeof(Pessoa));
    mosca->salario = 7000.0;
    strcpy(mosca->nome, "Joana");

    printf("Pessoa com struct: %s, salario %f\n", elon.nome, elon.salario);
    printf("Endereco elon: %d\n", &elon);
    printf("Pessoa com ponteiro: %s, salario %f\n", mosca->nome, mosca->salario);
    printf("Endereco mosca: %d\n", &mosca);
    printf("Endereco para onde mosca aponta: %d\n", mosca);

    tam = 2;

    pessoas = (Pessoa *)malloc(tam * sizeof(Pessoa)); // reserva tam * Pessoas
    strcpy(pessoas[0].nome, "Ana");
    pessoas[0].salario = 20000.0;
    printf("pessoas[0].nome e pessoas[0].salario: %s %f\n", pessoas[0].nome, pessoas[0].salario);

    strcpy(pessoas[1].nome, "Newton");
    pessoas[1].salario = 6000.0;
    printf("pessoas[1].nome e pessoas[1].salario: %s %f\n", pessoas->nome, pessoas->salario);

    printf("Acessando no for:\n");
    for (int i = 0; i < tam; i++)
        printf("%s %f\n", pessoas[i].nome, pessoas[i].salario);
}
