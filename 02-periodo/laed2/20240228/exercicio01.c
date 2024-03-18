/*
1. Dada as temperaturas que foram registradas diariamente durante uma semana,
deseja-se determinar enquanto dias dessa semana a temperatura esteve acima da média.
Escreva uma função utilizando vetores para calcular essa função e teste a função no programa principal da linguagem C.
*/

#include<stdio.h>

int calculaDiasAcimaMedia(float *temperaturas, int n);

int main() {
    float temps [] = {26.0, 25.0, 28.0, 30.0, 18.0, 20.0, 23.0}; //Inicializando o vetor
    printf("Numero de dias da semana com temperatura acima da media\n");
    printf("%d\n", calculaDiasAcimaMedia(temps, 7));
    return 0;
}

int calculaDiasAcimaMedia(float *temperaturas, int n) {
    int dias = 0;
    float media, soma = 0.0;

    // Calcula a media das temperaturas
    for (int i = 0; i < n; i++) {
        soma += temperaturas[i];
    }
    media = soma / n;

    // conta o numero de dias com a temperatura acima da media
    for (int i = 0; i < n; i++) {
        if (temperaturas[i] > media) {
            dias++;
        }
    }

    return dias;
}
