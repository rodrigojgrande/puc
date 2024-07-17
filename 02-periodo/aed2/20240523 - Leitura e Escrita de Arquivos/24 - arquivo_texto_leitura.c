#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
    Leitura de arquivos textos utilizando as funcoes
    - fgetc() -> salva um caractere por vez
    - fgets() -> salva uma string por vez
*/


int main(){

    char texto[100];
    char letra;

    int count, tam;

    // ira criar um arquivo com caminho relativo: o diretorio onde o programa esta
    // vc pode criar em outra pasta passando o caminho completo, ex: C://Teste//teste.txt
    // ou passar em outro diretorio a partir do caminho relativo, ex: .//NovaPasta//teste.txt
    char filename[20] = "teste.txt";

    //ponteiro do tipo FILE, que ira apontar para o comeco do arquivo
    FILE *f;

    // 'r': read - abre arquivo em modo de leitura
    // 'r+': read and write - abre arquivo em modo de leitura e escrita, sobrescreve o arquivo
    // 'a+': read and append - abre o arquivo em modo de leitura e escrita, insere conteudo novo no fim
    f = fopen(filename, "r");
    if(f == NULL){ // checa se deu certo abrir o arquivo
        printf("Problemas para abrir o arquivo");
        exit(1);
    }

    printf("Lendo o arquivo...\n");

    count = 0;
    while(1){ // loop infinito, ira parar quando chegar ao fim de arquivo
        letra = fgetc(f);

        // quando fgetc nao conseguir ler, ira sinalizar fim de arquivo. feof(f) checa se ja foi sinalizado
        if(feof(f))
            break;

        //caso ainda nao eh fim de arquivo, sigo guardando as letras
        texto[count] = letra;
        count++;
    }

    //terminei de ler, insiro o caractere de fim de string
    texto[count] = '\0';
    printf("O conteudo do arquivo eh: \n");
    printf("%s", texto);

    /* lendo o mesmo arquivo com fgets */

    //colocando o ponteiro novamente no comeco do arquivo
    rewind(f);

    // fgets retorna um ponteiro p/ a string lida e, caso nao consiga ler, retorna NULL
    // desse modo podemos repetir ate ele retornar NULL, ou seja, chegou ate o fim do arquivo
    // parametros: variavel para guardar a string, quantidade de caracteres a serem lidos, ponteiro para o arquivo
    count = 0;
    while(fgets(texto, 100, f) != NULL){
        // removendo \n caso esteja presente...
        tam = strlen(texto);
        if(tam > 0 && texto[tam-1] == '\n')
            texto[tam-1] = '\0';

        printf("\nA string %d eh: %s\n", count, texto);
        count++;
    }

    fclose(f);

}
