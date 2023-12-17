// Utilizando a IDE de sua preferencia indente, comente, compile e entao, execute o seguinte codigo

// Arquivos de Cabeçalho
#include <stdio.h>
#include <stdlib.h> // EXIT_SUCCESS

/* Comentarios */
// Definição de uma constante chamada SZ com valor 32
#define SZ 32 //SZ = SiZe

// Prototipo de uma função
void show(int, char []);
// Tipo de Dado = void
// Nome da Função = show
// () = Identifica uma função
// int, char [] = Argumentos

// Função principal da linguagem C
int main(void)
{
    // Declaração de variaveis locais e inicialização
    char linha[SZ] = {0};
    // String = Vetor

    getchar() // Faz um "escape" do enter digitado

    int n = 0;

    /* Limpar o terminal de texto */
    printf("\033c");

    printf("\033[H\033[J");

    // Laço de Repetição
    while (1)
    {
        // Pega o caractere
        linha[n] = getchar();

        // Se linha for igual a pular linha ou n for igual a SZ-1 Pare
        if ((linha[n] == '\n') || (n == (SZ - 1)))

            break;

        n++; // n = n + 1;
    }

    // Mostre o número e a linha
    show(n, linha);

    // Devolva saída com uscesso
    return(EXIT_SUCCESS);
}

// Função para apresentar cada caractere armazenado na string linha
void show(int n, char linha[])
{

    int i = 0;

    for (i = 0; i <= n; i += 1)
    {

        putchar(linha[i]);
    }
    return;

}


// Encaminhe o codigo indentado e comentado. Lembre-se de incluir o nome dos integrantes.


/*INTEGRANTES
Rodrigo Jose Grande*/
