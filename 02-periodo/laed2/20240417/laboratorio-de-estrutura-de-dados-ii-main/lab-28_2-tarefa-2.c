/*
 * Tentando descobrir se um dado era viciado, um dono de cassino
 * honesto (ha! ha! ha! ha!) o lançou n vezes. Dados os n resultados
 * dos lançamentos, determinar o número de ocorrências de cada face.
 */

#include <stdio.h>

void conta_ocorrencia_face(int *lancamentos, int n, int *faces);

int main()
{
    int lancs[] = {1, 2, 2, 3, 3, 4, 5, 5, 5, 6},
        faces[] = {0, 0, 0, 0, 0, 0};

    conta_ocorrencia_face(lancs, 10, faces);

    printf("Face - Quantidade\n");
    for (int i = 0; i < 6; i++)
        printf("\n%d = %d", i + 1, faces[i]);

    return 0;
}

void conta_ocorrencia_face(int *lancamentos, int n, int *faces)
{
    for (int i = 0; i < n; i++)
        faces[lancamentos[i] - 1] += 1;
}