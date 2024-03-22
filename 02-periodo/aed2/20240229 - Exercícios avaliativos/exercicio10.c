#include <stdio.h>

// Defini��o da estrutura Pessoa
struct Pessoa {
    char nome[30];
    int idade;
};

// Fun��o para preencher os dados de uma pessoa
void setPerson(struct Pessoa *pessoa, int idade, char nome[30]) {
    pessoa->idade = idade;
    //snprintf(pessoa->nome, sizeof(pessoa->nome), "%s", nome);
    strcpy(pessoa->nome, nome);
}

void imprime(struct Pessoa pessoa) {
    printf("Nome = %s, Idade = %d", pessoa.nome, pessoa.idade);
}

int main() {
    struct Pessoa fulano; // Declara��o de uma vari�vel do tipo Pessoa

    int idade;
    char nome[30];

    // Solicita ao usu�rio inserir a idade e o nome da pessoa
    printf("Informe a idade: ");
    scanf("%d", &idade);

    printf("Informe o nome: ");
    scanf("%s", nome);

    // Chama a fun��o setPerson para preencher os dados da pessoa
    setPerson(&fulano, idade, nome);

    imprime(fulano);

    return 0;
}
