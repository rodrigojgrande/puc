
// Utilizando a IDE de sua preferencia indente, comente, compile e entao, execute o seguinte codigo

#include <stdio.h>
/*Inclui a Biblioteca ao C�digo*/
#include <stdlib.h>
/*Inclui a Biblioteca ao C�digo*/

// EXIT_SUCCESS
/* Comentarios */

#define SZ 32
/*Esta linha � uma diretiva de pr�-processamento que define uma constante chamada SZ com o valor 32.
Isso permite que voc� use SZ em vez de 32 em v�rias partes do c�digo, tornando-o mais leg�vel e f�cil de manter.*/


void show(int, char []);
/*Esta linha declara um prot�tipo de fun��o chamada show.
Isso informa ao compilador que existe uma fun��o chamada show que recebe um inteiro (int) e um array de caracteres (char []) como argumentos,
mas a implementa��o real da fun��o est� abaixo da fun��o main.*/


int main(void) {
/*Aqui come�a a defini��o da fun��o principal main, que � o ponto de entrada do programa em C.
 A fun��o main retorna um valor inteiro (int), que � usado para indicar o status de sa�da do programa para o sistema operacional.*/


    char linha[SZ] = {0};
    /*Esta linha declara uma matriz de caracteres chamada linha com um tamanho de SZ, que � 32, conforme definido anteriormente. Inicializa todos os elementos da matriz com o valor 0.
     Essa matriz � usada para armazenar a linha de entrada do usu�rio.*/


    int n = 0;
    /*Declara uma vari�vel inteira n e a inicializa com o valor 0. Essa vari�vel ser� usada para rastrear o �ndice atual na matriz linha.*/


    /* Limpar o terminal de texto */
    printf("\033c");
    /*Essa linha emite um c�digo de escape ANSI (escape sequence) para limpar o terminal de texto. Ele remove o conte�do anterior do terminal.*/


    printf("\033[H\033[J");
    /*Outra sequ�ncia de escape ANSI que move o cursor para a posi��o inicial (\033[H) e limpa a tela (\033[J) do terminal.*/



    while (1) {
        /*Inicia um loop infinito. O programa continuar� a executar at� que uma instru��o break seja encontrada.*/

        linha[n] = getchar();
        /*L� um caractere da entrada padr�o (teclado) e o armazena na posi��o atual da matriz linha (dada pelo valor de n).*/

        if ((linha[n] == '\n') || (n == (SZ - 1)))
        /*Verifica se o caractere lido � uma quebra de linha ('\n') ou se o �ndice n alcan�ou o tamanho m�ximo da matriz (SZ - 1).*/

        break;
        /*Se a condi��o no ponto 10 for verdadeira, o loop while � interrompido, e o programa continua na pr�xima linha ap�s o loop.*/

        n++; // n = n + 1;
        /*Incrementa o valor de n para apontar para a pr�xima posi��o na matriz linha.*/
    }

    show(n, linha);
    /*Chama a fun��o show com os valores atuais de n e linha. Essa fun��o ir� imprimir os caracteres armazenados na matriz linha.*/

    return(EXIT_SUCCESS);
    /*Retorna EXIT_SUCCESS para indicar que o programa foi conclu�do com �xito ao sistema operacional e sai da fun��o main.*/
}


void show(int n, char linha[]) {
    /*Aqui come�a a defini��o da fun��o show, que foi prototipada anteriormente.*/

    int i = 0;
    /*Declara uma vari�vel inteira i e a inicializa com o valor 0. Esta vari�vel ser� usada para iterar atrav�s dos caracteres na matriz linha.*/

    for (i = 0; i <= n; i += 1) {
    /*Inicia um loop for que percorre todos os caracteres da matriz linha, incluindo o caractere na posi��o n.*/

        putchar(linha[i]);
        /*Imprime o caractere atual na posi��o i da matriz linha. */
    }
    return;
    /*Retorna da fun��o show. Note que return aqui � opcional, j� que a fun��o � declarada como retornando void, o que significa que n�o retorna nenhum valor.
    � uma boa pr�tica incluir return; em fun��es void, mas n�o � estritamente necess�rio.*/
}



/* SOBRE AS BIBLIOTECAS */

//<stdlib.h>

/*A linha de c�digo `#include <stdlib.h>` em C � uma diretiva de pr�-processamento que inclui a biblioteca padr�o `<stdlib.h>` no seu programa C. A inclus�o desta biblioteca fornece acesso a v�rias fun��es e tipos de dados �teis para manipula��o de mem�ria, gerenciamento de processos e outras opera��es relacionadas ao ambiente de execu��o do programa. Aqui est�o algumas das funcionalidades comuns fornecidas por `<stdlib.h>`:

1. **Aloca��o de Mem�ria Din�mica:** A biblioteca `<stdlib.h>` oferece fun��es como `malloc`, `calloc` e `realloc` para alocar mem�ria dinamicamente durante a execu��o do programa. Essas fun��es s�o essenciais para criar estruturas de dados din�micas, como listas ligadas, pilhas e filas.

2. **Liberar Mem�ria:** A fun��o `free` � usada para liberar a mem�ria alocada dinamicamente quando ela n�o � mais necess�ria, ajudando a evitar vazamentos de mem�ria.

3. **Controle de Processo:** A fun��o `exit` permite encerrar o programa e retornar um c�digo de status ao sistema operacional. Isso � �til para indicar se o programa foi conclu�do com sucesso (`EXIT_SUCCESS`) ou se ocorreu algum erro (`EXIT_FAILURE`).

4. **Convers�o de Strings para N�meros:** As fun��es `atoi` (ASCII to Integer) e `atof` (ASCII to Float) permitem converter strings em valores num�ricos inteiros ou de ponto flutuante.

5. **Gera��o de N�meros Aleat�rios:** A fun��o `rand` � usada para gerar n�meros pseudoaleat�rios, e a fun��o `srand` permite inicializar a semente para controlar a sequ�ncia de n�meros gerados.

6. **Ambiente do Programa:** Fun��es como `getenv` permitem acessar vari�veis de ambiente do sistema operacional.

7. **Outras Fun��es de Utilidade:** A biblioteca `<stdlib.h>` tamb�m inclui v�rias outras fun��es �teis, como manipula��o de strings (`itoa`, `bsearch`, `qsort`), fun��es relacionadas a aritm�tica de ponto flutuante (`abs`, `labs`, `fabs`), e fun��es para manipula��o de arquivos (`fopen`, `fclose`, `fread`, `fwrite`).

Em resumo, `#include <stdlib.h>` � usado para incluir a biblioteca padr�o de fun��es �teis em um programa C. Ela � amplamente utilizada para opera��es relacionadas a mem�ria, processos, convers�es de dados e outras tarefas essenciais na programa��o C.*/



// <stdlib.h>
/*A linha de c�digo `#include <stdlib.h>` em C � uma diretiva de pr�-processamento que inclui a biblioteca padr�o `<stdlib.h>` no seu programa. Essa biblioteca fornece v�rias fun��es e tipos de dados relacionados a aloca��o de mem�ria, controle de processos e outras opera��es relacionadas � manipula��o de dados e gerenciamento do programa.

A inclus�o dessa biblioteca � comum em muitos programas C, pois ela cont�m fun��es essenciais, como `malloc`, `free`, `exit`, `rand`, `atoi`, `atof` e v�rias outras que s�o amplamente usadas em programa��o C. Aqui est�o alguns dos principais recursos fornecidos por `<stdlib.h>`:

1. **Gerenciamento de Mem�ria Din�mica:** A biblioteca `<stdlib.h>` oferece fun��es como `malloc`, `calloc`, `realloc` e `free` para aloca��o e desaloca��o de mem�ria din�mica. Isso � fundamental para a cria��o e manipula��o de estruturas de dados din�micas, como listas ligadas, pilhas e filas.

2. **Controle de Processo:** A fun��o `exit` permite que voc� encerre o programa e retorne um c�digo de status ao sistema operacional. Isso � �til para indicar se o programa terminou com sucesso (`EXIT_SUCCESS`) ou se ocorreu algum erro (`EXIT_FAILURE`).

3. **Convers�o de Strings para N�meros:** As fun��es `atoi` (ASCII to Integer) e `atof` (ASCII to Float) permitem converter strings em valores num�ricos inteiros ou de ponto flutuante.

4. **Gera��o de N�meros Aleat�rios:** A fun��o `rand` � usada para gerar n�meros pseudoaleat�rios.

5. **Ambiente do Programa:** Fun��es como `getenv` permitem que voc� acesse vari�veis de ambiente do sistema.

6. **Outros recursos:** Al�m desses, a biblioteca `<stdlib.h>` cont�m v�rias outras fun��es �teis, como manipula��o de strings (`itoa`, `bsearch`, `qsort`), fun��es para manipula��o de arquivos (`fopen`, `fclose`, `fread`, `fwrite`) e fun��es relacionadas � aritm�tica de ponto flutuante.

Em resumo, `#include <stdlib.h>` � usado para incluir essa biblioteca padr�o no seu programa C, dando-lhe acesso a essas funcionalidades importantes para a manipula��o de dados, mem�ria e controle de processos.*/



// Encaminhe o codigo indentado e comentado. Lembre-se de incluir o nome dos integrantes.



/*INTEGRANTES
Rodrigo Jose Grande*/
