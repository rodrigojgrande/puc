#include <stdio.h>
#include <math.h>

main()
{
    int   di1, di2, qi, ri;
    float df1, df2, qf;
    int   n1, n2, soma, subt, mult;
    int   b, e, pot;
    int   n3;
    float raiz;


    printf("Digite um numero inteiro para dividendo = ");
    scanf("%d", &di1);
    printf("Digite um numero inteiro para divisor = ");
    scanf("%d", &di2);
    qi = di1 / di2;
    ri = di1 % di2;
    printf("Quociente da divisao = %d\n", qi);
    printf("Resto da divisao = %d\n\n", ri);

    printf("Digite um numero real para dividendo = ");
    scanf("%f", &df1);
    printf("Digite um numero real para divisor = ");
    scanf("%f", &df2);
    qf = df1 / df2;
    printf("Quociente da divisao = %f\n\n", qf);

    printf("Digite um numero inteiro = ");
    scanf("%d", &n1);
    printf("Digite outro numero inteiro = ");
    scanf("%d", &n2);
    soma = n1 + n2;
    subt = n1 - n2;
    mult = n1 * n2;

    printf("Resultado da soma = %d\n", soma);
    printf("Resultado da subtracao = %d\n", subt);
    printf("Resultado da multiplicacao = %d\n", mult);

    printf("Digite um valor inteiro para a base = ");
    scanf("%d", &b);
    printf("Digite um valor para o expoente = ");
    scanf("%d", &e);
    pot = pow(b,e);
    printf("Resultado da potenciacao = %d\n\n", pot);

    printf("Digite um numero inteiro para raiz quadrada = ");
    scanf("%d", &n3);
    raiz = sqrt(n3);
    printf("Resultado da raiz quadrada = %f\n\n", raiz);
}
