
// Utilizando a IDE de sua preferencia indente, comente, compile e entao, execute o seguinte codigo

#include <stdio.h>
/*Inclui a Biblioteca ao Código*/
#include <stdlib.h>
/*Inclui a Biblioteca ao Código*/

// EXIT_SUCCESS
/* Comentarios */

#define SZ 32
/*Esta linha é uma diretiva de pré-processamento que define uma constante chamada SZ com o valor 32.
Isso permite que você use SZ em vez de 32 em várias partes do código, tornando-o mais legível e fácil de manter.*/


void show(int, char []);
/*Esta linha declara um protótipo de função chamada show.
Isso informa ao compilador que existe uma função chamada show que recebe um inteiro (int) e um array de caracteres (char []) como argumentos,
mas a implementação real da função está abaixo da função main.*/


int main(void) {
/*Aqui começa a definição da função principal main, que é o ponto de entrada do programa em C.
 A função main retorna um valor inteiro (int), que é usado para indicar o status de saída do programa para o sistema operacional.*/


    char linha[SZ] = {0};
    /*Esta linha declara uma matriz de caracteres chamada linha com um tamanho de SZ, que é 32, conforme definido anteriormente. Inicializa todos os elementos da matriz com o valor 0.
     Essa matriz é usada para armazenar a linha de entrada do usuário.*/


    int n = 0;
    /*Declara uma variável inteira n e a inicializa com o valor 0. Essa variável será usada para rastrear o índice atual na matriz linha.*/


    /* Limpar o terminal de texto */
    printf("\033c");
    /*Essa linha emite um código de escape ANSI (escape sequence) para limpar o terminal de texto. Ele remove o conteúdo anterior do terminal.*/


    printf("\033[H\033[J");
    /*Outra sequência de escape ANSI que move o cursor para a posição inicial (\033[H) e limpa a tela (\033[J) do terminal.*/



    while (1) {
        /*Inicia um loop infinito. O programa continuará a executar até que uma instrução break seja encontrada.*/

        linha[n] = getchar();
        /*Lê um caractere da entrada padrão (teclado) e o armazena na posição atual da matriz linha (dada pelo valor de n).*/

        if ((linha[n] == '\n') || (n == (SZ - 1)))
        /*Verifica se o caractere lido é uma quebra de linha ('\n') ou se o índice n alcançou o tamanho máximo da matriz (SZ - 1).*/

        break;
        /*Se a condição no ponto 10 for verdadeira, o loop while é interrompido, e o programa continua na próxima linha após o loop.*/

        n++; // n = n + 1;
        /*Incrementa o valor de n para apontar para a próxima posição na matriz linha.*/
    }

    show(n, linha);
    /*Chama a função show com os valores atuais de n e linha. Essa função irá imprimir os caracteres armazenados na matriz linha.*/

    return(EXIT_SUCCESS);
    /*Retorna EXIT_SUCCESS para indicar que o programa foi concluído com êxito ao sistema operacional e sai da função main.*/
}


void show(int n, char linha[]) {
    /*Aqui começa a definição da função show, que foi prototipada anteriormente.*/

    int i = 0;
    /*Declara uma variável inteira i e a inicializa com o valor 0. Esta variável será usada para iterar através dos caracteres na matriz linha.*/

    for (i = 0; i <= n; i += 1) {
    /*Inicia um loop for que percorre todos os caracteres da matriz linha, incluindo o caractere na posição n.*/

        putchar(linha[i]);
        /*Imprime o caractere atual na posição i da matriz linha. */
    }
    return;
    /*Retorna da função show. Note que return aqui é opcional, já que a função é declarada como retornando void, o que significa que não retorna nenhum valor.
    É uma boa prática incluir return; em funções void, mas não é estritamente necessário.*/
}



/* SOBRE AS BIBLIOTECAS */

//<stdlib.h>

/*A linha de código `#include <stdlib.h>` em C é uma diretiva de pré-processamento que inclui a biblioteca padrão `<stdlib.h>` no seu programa C. A inclusão desta biblioteca fornece acesso a várias funções e tipos de dados úteis para manipulação de memória, gerenciamento de processos e outras operações relacionadas ao ambiente de execução do programa. Aqui estão algumas das funcionalidades comuns fornecidas por `<stdlib.h>`:

1. **Alocação de Memória Dinâmica:** A biblioteca `<stdlib.h>` oferece funções como `malloc`, `calloc` e `realloc` para alocar memória dinamicamente durante a execução do programa. Essas funções são essenciais para criar estruturas de dados dinâmicas, como listas ligadas, pilhas e filas.

2. **Liberar Memória:** A função `free` é usada para liberar a memória alocada dinamicamente quando ela não é mais necessária, ajudando a evitar vazamentos de memória.

3. **Controle de Processo:** A função `exit` permite encerrar o programa e retornar um código de status ao sistema operacional. Isso é útil para indicar se o programa foi concluído com sucesso (`EXIT_SUCCESS`) ou se ocorreu algum erro (`EXIT_FAILURE`).

4. **Conversão de Strings para Números:** As funções `atoi` (ASCII to Integer) e `atof` (ASCII to Float) permitem converter strings em valores numéricos inteiros ou de ponto flutuante.

5. **Geração de Números Aleatórios:** A função `rand` é usada para gerar números pseudoaleatórios, e a função `srand` permite inicializar a semente para controlar a sequência de números gerados.

6. **Ambiente do Programa:** Funções como `getenv` permitem acessar variáveis de ambiente do sistema operacional.

7. **Outras Funções de Utilidade:** A biblioteca `<stdlib.h>` também inclui várias outras funções úteis, como manipulação de strings (`itoa`, `bsearch`, `qsort`), funções relacionadas a aritmética de ponto flutuante (`abs`, `labs`, `fabs`), e funções para manipulação de arquivos (`fopen`, `fclose`, `fread`, `fwrite`).

Em resumo, `#include <stdlib.h>` é usado para incluir a biblioteca padrão de funções úteis em um programa C. Ela é amplamente utilizada para operações relacionadas a memória, processos, conversões de dados e outras tarefas essenciais na programação C.*/



// <stdlib.h>
/*A linha de código `#include <stdlib.h>` em C é uma diretiva de pré-processamento que inclui a biblioteca padrão `<stdlib.h>` no seu programa. Essa biblioteca fornece várias funções e tipos de dados relacionados a alocação de memória, controle de processos e outras operações relacionadas à manipulação de dados e gerenciamento do programa.

A inclusão dessa biblioteca é comum em muitos programas C, pois ela contém funções essenciais, como `malloc`, `free`, `exit`, `rand`, `atoi`, `atof` e várias outras que são amplamente usadas em programação C. Aqui estão alguns dos principais recursos fornecidos por `<stdlib.h>`:

1. **Gerenciamento de Memória Dinâmica:** A biblioteca `<stdlib.h>` oferece funções como `malloc`, `calloc`, `realloc` e `free` para alocação e desalocação de memória dinâmica. Isso é fundamental para a criação e manipulação de estruturas de dados dinâmicas, como listas ligadas, pilhas e filas.

2. **Controle de Processo:** A função `exit` permite que você encerre o programa e retorne um código de status ao sistema operacional. Isso é útil para indicar se o programa terminou com sucesso (`EXIT_SUCCESS`) ou se ocorreu algum erro (`EXIT_FAILURE`).

3. **Conversão de Strings para Números:** As funções `atoi` (ASCII to Integer) e `atof` (ASCII to Float) permitem converter strings em valores numéricos inteiros ou de ponto flutuante.

4. **Geração de Números Aleatórios:** A função `rand` é usada para gerar números pseudoaleatórios.

5. **Ambiente do Programa:** Funções como `getenv` permitem que você acesse variáveis de ambiente do sistema.

6. **Outros recursos:** Além desses, a biblioteca `<stdlib.h>` contém várias outras funções úteis, como manipulação de strings (`itoa`, `bsearch`, `qsort`), funções para manipulação de arquivos (`fopen`, `fclose`, `fread`, `fwrite`) e funções relacionadas à aritmética de ponto flutuante.

Em resumo, `#include <stdlib.h>` é usado para incluir essa biblioteca padrão no seu programa C, dando-lhe acesso a essas funcionalidades importantes para a manipulação de dados, memória e controle de processos.*/



// Encaminhe o codigo indentado e comentado. Lembre-se de incluir o nome dos integrantes.



/*INTEGRANTES
Rodrigo Jose Grande*/
