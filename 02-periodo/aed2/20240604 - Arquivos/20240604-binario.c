#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char nome[25];
    char raca[25];
    float peso;
} Cao;

Cao registraCao();

int main(){
    // Cao d = registraCao();
    // printf("%d %s %s %f", d.id, d.nome, d.raca, d.peso);

    char filename[50] = "caes.b";

    FILE *f;
    f = fopen(filename, "wb");
    if(f == NULL) {
        printf("Falha ao abrir o arquivo");
        exit(1);
    }

    int n;

    printf("\nDigite quantos caes vc quer registrar: ");
    scanf("%d", &n);

    Cao c[n];

    for (int i=0; i<n; i++){
        c[i] = registraCao();
    }

    // Salva o vertor inteiro de Cao
    // fwrite(c, sizeof(Cao), n, f); // Escrever em binário
    // fwrite(vetor, tamanho do registro, número de registros, arquivo)

    for (int i=0; i<n; i++){
     fwrite(&c[i], sizeof(Cao), 1, f);
    }


    fclose(f);
}

Cao registraCao(){
    Cao c;

    printf("Registra info do Cao: \n");

    printf("Id: ");
    scanf("%d", &c.id);
    getchar();

    printf("Nome: ");
    fgets(c.nome, 25, stdin);

    printf("Raca: ");
    fgets(c.raca, 25, stdin);

    printf("Peso: ");
    scanf("%f", &c.peso);

    return c;
}
