#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimeVetor(int *v, int tam);
void quicksort(int *v, int esq, int dir);

int main()
{
    int tam = 6;
    int v[6] = {79, 82, 68, 69, 78, 65};
    printf("Vetor inicial: ");
    imprimeVetor(&v, tam);

    printf("\nIniciando Quicksort\n");
    quicksort(&v, 0, tam - 1);
    printf("\n\nResutado final:\n");
    imprimeVetor(&v, tam);

    return 0;
}

void imprimeVetor(int *v, int tam)
{
    printf("[");
    for (int i = 0; i < tam; i++)
    {
        printf("%d\t", v[i]);
    }
    printf("]\n");
}

void quicksort(int *vet, int esq, int dir)
{
    printf("\nquicksort(vet, %d, %d)\nesq = %d, dir = %d, vet = ", esq, dir, esq, dir);
    imprimeVetor(vet, 6);
    int i = esq, j = dir, x, y;
    x = vet[(int)((esq + dir) / 2)];
    printf("i(inicio) = %d, j(inicio) = %d, pivot = %d\n", i, j, x);
    do
    {
        while ((vet[i] < x) && (i < dir))
        {
            i++;
            printf("i = %d\n", i);
        }
        while ((x < vet[j]) && (j > esq))
        {
            j--;
            printf("j = %d\n", j);
        }
        if (i <= j)
        { // troca vet[i] e vet[j]
            y = vet[i];
            vet[i] = vet[j];
            vet[j] = y;
            i++;
            j--;
            printf("troca vet[i] e vet[j]. Estado atual vetor = ");
            imprimeVetor(vet, 6);
        }
    } while (i <= j);
    if (esq < j)
        quicksort(vet, esq, j);
    if (i < dir)
        quicksort(vet, i, dir);
}