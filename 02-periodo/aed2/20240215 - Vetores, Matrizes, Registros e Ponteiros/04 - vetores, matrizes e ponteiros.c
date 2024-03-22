#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    int idade;
} Pessoa;

// const int LINHAS = 2; <- nao permitido
// #define LINHAS 2 <- permitido

void imprimeVetor(int v[], int tamanho);
void preencheVetor(int v[], int tamanho);
void preenchePonteiro(int *p, int tamanho);

void imprimeMatriz(int m[2][3], int linhas, int colunas);

void imprimePessoas(Pessoa pessoas[], int tam);
void inserePessoa(Pessoa *pessoa, char nome[], int idade);

int main()
{
    int vetor[] = {1, 2, 3, 4, 5};
    int tamanho = 5;
    imprimeVetor(vetor, tamanho);
    preencheVetor(vetor, tamanho);
    imprimeVetor(vetor, tamanho);
    preenchePonteiro(&vetor[0], tamanho);
    imprimeVetor(vetor, tamanho);

    int matriz[2][3] =
        {
            {1, 2, 3},
            {10, 20, 30}};
    imprimeMatriz(matriz, 2, 3);

    /*
        Registros ocupam na memoria o total de memoria requirido por suas variaveis.
        Pessoa ocupa:
            char[50] -> 50bytes
            int -> 6 bytes,
            total = 54bytes

        O acesso a registros se vai atraves de ponto ('.'). Com ponteiros, a notacao muda
        para uma flecha ('->').
        Exemplo:
        Pessoa a, *p;
        a.idade = 32;
        p = &a;
        p->idade = 47;

        Um vetor de Pessoa funciona igual a um vetor de tipos basicos, e ocupa um bloco
        continuo de memoria igual a tam(vetor) * tam(registro).
        Exemplo:
        Pessoa v[50] -> *Pessoa apontando para bloco de memoria com:
                                    54 bytes * 50 = 2700 bytes

    */
    printf("\n\nVetor de pessoas:\n");
    Pessoa pessoas[5];

    inserePessoa(&pessoas[0], "Clark Kent", 20);         // endereco de memoria da posicao 0 do vetor
    inserePessoa(&pessoas[1], "Daenerys Targaryen", 18); // endereco de memoria da posicao 1 do vetor
    inserePessoa(&pessoas[2], "Diana Prince", 110);
    inserePessoa(&pessoas[3], "Homer Simpson", 44);
    inserePessoa(&pessoas[4], "Jessica Jones", 35);
    //imprimePessoas(pessoas, 5);

    printf("\n\nPonteiros de pessoas:\n");
    Pessoa leya, yoda, *ponteiroPessoas;
    
    leya.idade = 25;
    strcpy(leya.nome, "Leia Skywalker");
    yoda.idade = 900;
    strcpy(yoda.nome, "Yoda");

    ponteiroPessoas = &leya;
    imprimePessoas(ponteiroPessoas, 1);

    printf("\nAcesso do que esta no ponteiro:\n");
    printf(ponteiroPessoas->nome);

    printf("\n\nAlterando endereco do ponteiro pela funcao inserePessoa.\n");
    inserePessoa(ponteiroPessoas, "Phoebe Buffay", 20);

    printf("\nAcesso do que esta no ponteiro:\n");
    printf(ponteiroPessoas->nome);

    printf("\n\nAlterando endereco do ponteiro diretamente.\n");
    ponteiroPessoas = &yoda;

    printf("\nAcesso do que esta no ponteiro:\n");
    printf(ponteiroPessoas->nome);

    printf("\n\n imprimePessoas com tamanho = 2:\n");
    imprimePessoas(ponteiroPessoas, 2);

    printf("\n\nCom tamanho = 3:\n");
    imprimePessoas(ponteiroPessoas, 3);

    

    printf("ponteiroPessoas = %d, &pessoas = %d\n\n", ponteiroPessoas, &pessoas);

    printf("Tamanho na memoria:\n");
    printf("sizeof(leya) = %d, sizeof(ponteiroPessoas) = %d, sizeof(pessoas) = %d\n", sizeof(leya), sizeof(ponteiroPessoas), sizeof(pessoas));
    printf("sizeof(pessoas[0].nome) = %d, sizeof(ponteiroPessoas->nome) = %d\n", sizeof(pessoas[0].nome), sizeof(ponteiroPessoas->nome));
}

void imprimeVetor(int v[], int tamanho)
{
    printf("Vetor = ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void imprimeMatriz(int m[2][3], int linhas, int colunas)
{
    printf("Matriz = [\n");
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    printf("]\n");
}

void preencheVetor(int v[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        v[i] = 100;
    }
}

void preenchePonteiro(int *p, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        *(p + i) = 200;
    }
}

void imprimePessoas(Pessoa pessoas[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%s\n", pessoas[i].nome);
        printf("%d\n\n", pessoas[i].idade);
    }
    printf("\n");
}

void inserePessoa(Pessoa *pessoa, char nome[], int idade)
{
    pessoa->idade = idade;
    strcpy(pessoa->nome, nome);
    // copia de strings (vetores de char) devem ser feitas com strcpy(), da biblioteca string.h
}