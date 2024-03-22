#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimeVetor(int *v);
void preencheVetor(int *v);
void trocar(int *v, int i, int j);

int particiona(int *v, int esq, int dir);
void quicksort(int *v, int esq, int dir);

// variaveis globais para simplificacao das funcoes
// vez eh usada para contagem de recursoes
// tam eh o tamanho do vetor, para exibicao do passo a passo
int vez = 0, tam;

int main()
{

    printf("Digite o tamanho do seu vetor:\n");
    scanf("%d", &tam);
    int *v = (int *)malloc(tam * sizeof(int));

    srand(time(NULL));
    preencheVetor(v);
    printf("Vetor gerado aleatoriamente:\n");
    imprimeVetor(v);

    printf("\n\nExecutando Quicksort\n\n");
    quicksort(v, 0, tam - 1);
    printf("\n\nResutado final:\n");
    imprimeVetor(v);

    free(v);
    return 0;
}

void imprimeVetor(int *v)
{

    for (int i = 0; i < tam; i++)
    {
        printf("%d\t", v[i]);
    }
    printf("\n");
}

void preencheVetor(int *v)
{

    for (int i = 0; i < tam; i++)
    {
        v[i] = rand() % 1000;
    }
}

void trocar(int *v, int i, int j)
{
    int aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

/*
    Essa funcao eh responsavel por encontrar a posicao do pivo no vetor, e colocar tudo que eh menor a sua
    esquerda, e tudo que eh maior a sua direita. Por fim, a funcao retorna a posicao final do pivo.
*/
int particiona(int *v, int esq, int dir)
{

    int i, j, x;
    i = esq;    // i inicia no comeco do vetor
    j = dir;    // j inicia no fim do vetor
    x = v[esq]; // guardando o valor do pivo

    printf("Pivo escolhido = %d\n", x);
    printf("Trocas:\n");
    while (i < j)
    { // executa ate i e j se cruzarem

        // movimenta o i ate encontrar um valor maior que o pivo
        while ((v[i] <= x) && (i < dir))
            i++;

        // movimenta o j ate encontrar um valor menor ou igual ao pivo
        while ((v[j] > x))
            j--;

        // se i e j ainda nao se cruzaram, troca os valores no vetor
        // eh essa troca que coloca tudo que for menor que o pivo a esquerda e o que for maior a direita
        if (i < j)
        {
            trocar(v, i, j);
            imprimeVetor(v);
        }
    }
    // quando i e j se cruzam, a posicao que j esta eh exatamente onde o pivo deve ficar
    // nesse momento, troca-se o valor de j com o valor de esq (o valor do pivo)
    trocar(v, esq, j);
    imprimeVetor(v);

    return j;
}

/*
    Essa versao do quicksort escolhe como o elemento pivo o primeiro elemento do trecho que esta trabalhando.
    esq guarda a posicao de come�o do subvetor, dir a de fim.
    Portanto, se quicksort(v, 3, 7), v[3] sera o elemento escolhido.
    Quicksort encontra a posicao que o pivo deve ficar no vetor, colocando tudo que eh menor � sua esquerda e
    tudo que eh maior a sua direita. Entao, recursivamente, ele repete o processo para o subvetor a esquerda
    e a direita. O processo se repete ate o subvetor ser de tamanho unitario ou < 0, onde a recursao encerra.

    Ex: quicksort(v, 0, 9) ---> chamada inicial
        pivo -> v[0], deve ficar na posicao 4 com menores a esquerda e maiores a direita
        Recursivamente:
            quicksort(v, 0, 3)
            quicksort(v, 5, 9)

            cada uma dessas ira encontrar o pivo, posiciona-lo no lugar certo e chamar recursivamente para
            outros subvetores, que serao cada vez menores.
*/
void quicksort(int *v, int esq, int dir)
{
    int pivo;

    printf("\n\nChamada da funcao = %d\nEsq = %d, Dir = %d\n", vez, esq, dir);
    vez++;

    if (esq >= dir) // criterio de parada, vetor unitario ou esq > dir (tam negativo)
        return;     // return em funcao void indica quebra brusca de execucao

    printf("Configuracao atual do vetor:\n");
    imprimeVetor(v);

    pivo = particiona(v, esq, dir); // posiciona o pivo
    quicksort(v, esq, pivo - 1);    // chama para o subvetor esq ate pivo - 1
    quicksort(v, pivo + 1, dir);    // chama para o subvetor pivo + 1 ate dir
}
