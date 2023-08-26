/*
Autor: Todos nós
Data: August-24th,2023
*/
#include <stdio.h>

main()
{
    char necessidade;
    unsigned short int idade;
    float renda;
    char data[9];
    char cpf[12];
    char nome[30];
    char endereco[50];

    printf("Formulario para Coleta de Dados\n");
    printf("===============================\n\n");

    printf("Digite o nome = ");
    gets(nome);
    printf("Digite a idade = ");
    scanf("%hu", &idade);
    getchar();
    printf("Digite o endereco = ");
    gets(endereco); //scanf("%s", &nome);
    printf("Digite a renda mensal = ");
    scanf("%f", &renda);
    getchar();
    printf("Digite o CPF = ");
    gets(cpf);
    printf("Digite a data de nascimento = ");
    gets(data);
    printf("Tem alguma necesidade especial (S/N) = ");
    necessidade = getche();
    printf("\n\nApresentando as informacoes...\n");
    printf("==============================\n\n");
    printf("Nome digitado = %s\n", nome);
    printf("Idade digitada = %hu\n", idade);
    printf("Endereco digitado = %s\n", endereco);
    printf("Renda digitada = %5.2f\n", renda);
    printf("CPF digitado = %s\n", cpf);
    printf("Data digitada = %s\n", data);
    printf("Necessidades especiais = %c\n\n", necessidade);

    printf("Informacao especial\n");
    printf("Dia da data = %c%c\n\n", data[0], data[1]);
}
