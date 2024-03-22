#include<stdio.h>
#include<string.h>

typedef struct
{
    char nome[50];
    int idade;
} Pessoa;

void inserePessoa(Pessoa *p, char nome[], int idade);
void imprimePessoa(Pessoa *p);

int main(){
    printf("Pessoas:\n\n");
    Pessoa leya, yoda, *jedi;
    jedi = &leya;
    inserePessoa(&leya, "Leya Skywalker", 25);
    inserePessoa(&yoda, "Yoda", 900);

    imprimePessoa(&leya);
    imprimePessoa(&yoda);
    imprimePessoa(jedi);

    jedi->idade = 40;
    imprimePessoa(&leya);
}

void imprimeVetor(int vetor[], int tamanho){
    printf("Vetor: [");
    for(int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
    printf("]\n");
}

void inserePessoa(Pessoa *p, char nome[], int idade){
    p->idade = idade;
    strcpy(p->nome, nome);
}

void imprimePessoa(Pessoa *p){
    printf("nome = %s, idade = %d\n", p->nome, p->idade);
}