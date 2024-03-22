#include <stdio.h>

// Definição da estrutura Pessoa
struct Pessoa {
    char nome[30];
    int idade;
};

// Função para preencher os dados de uma pessoa
void setPerson(struct Pessoa *pessoa, int idade, char nome[30]) {
    pessoa->idade = idade;
    //snprintf(pessoa->nome, sizeof(pessoa->nome), "%s", nome);
    strcpy(pessoa->nome, nome);
}

void imprime(struct Pessoa pessoa) {
    printf("Nome = %s, Idade = %d", pessoa.nome, pessoa.idade);
}

int main() {
    struct Pessoa fulano; // Declaração de uma variável do tipo Pessoa

    int idade;
    char nome[30];

    // Solicita ao usuário inserir a idade e o nome da pessoa
    printf("Informe a idade: ");
    scanf("%d", &idade);

    printf("Informe o nome: ");
    scanf("%s", nome);

    // Chama a função setPerson para preencher os dados da pessoa
    setPerson(&fulano, idade, nome);

    imprime(fulano);

    return 0;
}
