#include <stdio.h>
#include <windows.h>

int geraNumero(int faixa);

main()
{
    int n1, n2, n3, f;
    printf("Digite uma faixa de valores = ");
    scanf("%d", &f);
    n1 = geraNumero(f);
    Sleep(500);
    n2 = geraNumero(f);
    Sleep(500);
    n3 = geraNumero(f);

    printf("\nNumeros gerados = %d %d %d\n\n", n1, n2, n3);
}

int geraNumero(int faixa)
{
    srand(time(NULL));
    return rand() % faixa;
}



