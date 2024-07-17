#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int tam;
    char texto[100];
    char filename[50] = ".\\Arquivos\\teste.txt";

    FILE *f;

    f = fopen(filename, "a"); // w = write | a = append
    if(f == NULL){
        printf("Falha ao abrir o arquivo");
        exit(1);
    }

    printf("Digite sua primeira mensagem: ");
    fgets(texto, 100, stdin); // Arquivo - Tamanho da leitura - Entrada padrão (Standard In)
    tam = strlen(texto);
    if(tam > 0 && texto[tam-1] == '\n'){
        texto[tam-1] = '\0';
    }
    printf("%s", texto);

    for(int i = 0; i < strlen(texto); i++){
        fputc(texto[i], f);
    }
    fputc('\n', f);

    printf("\nDigite sua primeira mensagem: ");
    fgets(texto, 100, stdin); // Arquivo - Tamanho da leitura - Entrada padrão (Standard In)
    tam = strlen(texto);
    if(tam > 0 && texto[tam-1] == '\n'){
        texto[tam-1] = '\n';
    }
    printf("%s", texto);

    fputs(texto, f); // Salvar string completa

    fclose(f);
    return 0;
}
