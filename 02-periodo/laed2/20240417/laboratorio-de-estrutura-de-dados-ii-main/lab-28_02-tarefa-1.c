/*
Dadas as temperaturas que foram registradas diariamente
durante uma semana, deseja-se determinar em quantos dias
dessa semana a temperatura esteve acima da média. Escreva
uma função utilizando vetores para calcular esta informação.
*/

#include <stdio.h>

int calcula_dias_acima_media(float *temperaturas, int n);

int main()
{
    float temps[] = {26.0, 25.0, 28.0, 30.0, 18.0, 20.0, 23.0};
    printf("Numero de dias da semana com temp. acima da media: ");
    printf("%d\n", calcula_dias_acima_media(temps, 7));
    return 0;
}

int calcula_dias_acima_media(float *temperaturas, int n)
{
    int dias = 0;
    float media, soma = 0.0;

    /* calcula a média das temperaturas */
    for (int i = 0; i < n; i++)
        soma += temperaturas[i];
 
    media = soma / n;

    /* conta o número de dias com a temperatura
     * acima da média calculada.
     */
    for (int i = 0; i < n; i++)
        if (temperaturas[i] > media)
            dias++;

    return dias;
}