/*
2. Tentando descobrir se um dado era viciado, um dono de cassino honesto o lançou N vezes,
dado os N resultados em lançamentos, determinar o número de ocorrências de cada face.
*/

#include<stdio.h>

void contaOcorrenciaFace(int *lancamentos, int n, int *faces);

int main() {
    int lances[] = {1, 2, 2, 3, 3, 4, 5, 5, 5, 6},
        faces[] = {0, 0, 0, 0, 0, 0};

    contaOcorrenciaFace(lances, 10, faces);
    printf("Face - Quantidade\n");
    for (int i = 0; i < 6; i++){
        printf("\n%d = %d", i + 1, faces[i]);
    }

    return 0;
}

void contaOcorrenciaFace(int *lancamentos, int n, int *faces){
    for (int i = 0; i < n; i++){
        faces[lancamentos[i] - 1] += 1;
    }
}
