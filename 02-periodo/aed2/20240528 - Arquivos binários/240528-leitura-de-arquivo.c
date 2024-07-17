#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char texto[100], letra;
    char filename[50] = ".\\Arquivos\\teste.txt";

    FILE *f;
    f = fopen(filename, "r");
    if(f == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    printf("O conteudo do arquivo eh: \n");
    while(1){
        letra = fgetc(f); //EOF = End Of File -> TRUE
        if(feof(f)){ //feof = Testa se EOF é true
            break;
        }
        printf("%c", letra);
    }
    rewind(f); // Reiniciar o ponteiro

    printf("\n Imprimindo strings: \n");

    while(fgets(texto, 100, f) != NULL){ // Esquanto existir texto
        printf("\n A string eh %s", texto);
    }

    fclose(f); // Fechar o buffer

    return 0;
}
