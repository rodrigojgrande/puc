#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
    Escrita de arquivos textos utilizando as funcoes
    - fputc() -> salva um caractere por vez
    - fputs() -> salva uma string por vez
*/


int main(){

    int tam;
    char texto[100];

    // ira criar um arquivo com caminho relativo: o diretorio onde o programa esta
    // vc pode criar em outra pasta passando o caminho completo, ex: C://Teste//teste.txt
    // ou passar em outro diretorio a partir do caminho relativo, ex: .//NovaPasta//teste.txt
    char filename[20] = "teste.txt";

    //ponteiro do tipo FILE, que ira apontar para o comeco do arquivo
    FILE *f;

    // 'w': write - abre arquivo em modo de escrita, mas substitui o arquivo se ja existir
    // opcao: 'a' -> abre o arquivo em modo de escrita, escrevendo no seu fim.
    f = fopen(filename, "w");
    if(f == NULL){ // checa se deu certo abrir o arquivo
        printf("Problemas para abrir o arquivo");
        exit(1);
    }

    printf("Digite a mensagem que vc quer guardar em arquivo: ");

    //fgets pode ser usado para arquivos e para a entrada padrao (stdin)
    // eh a funcao recomendada para se ler string em C
    fgets(texto, 100, stdin);

    //fgets guarda o \n ao final da leitura - eh interessante remove-lo com a seguinte logica
    tam = strlen(texto);
    if(tam > 0 && texto[tam-1] == '\n')
        texto[tam-1] = '\0';
    printf("%s", texto);

    //salvando caractere a caractere
    for(int i = 0; i < strlen(texto); i++)
        fputc(texto[i], f);

    fputc('\n', f);

    /* salvando um string */

    printf("\nDigite uma segunda mensagem que vc quer guardar em arquivo: ");
    fgets(texto, 100, stdin);

    tam = strlen(texto);
    if(tam > 0 && texto[tam-1] == '\n')
        texto[tam-1] = '\0';

    fputs(texto, f);

    //fechando comunicacao com o arquivo
    fclose(f);


}
