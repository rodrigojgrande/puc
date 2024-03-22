#include <stdio.h>

int main(){

    //ponteiros tem tipos, e respeitam o tamanho ocupado por seus tipos em memoria.
    // int: 4 bytes
    // float: 4 bytes
    // char: 1 byte
    int a, *pInt;
    float b, *pFloat;
    char c, *pChar;

    printf("Informe um inteiro, um float e um char:\n");
    scanf("%d %f %c", &a, &b, &c);

    // recebendo os enderecos de memoria das variaveis
    pInt = &a;
    pFloat = &b;
    pChar = &c;

    printf("Exibindo valores apos atribuicao:\n");
    printf("%d %d %d\n", pInt, pFloat, pChar);
    printf("%d %f %c\n\n", *pInt, *pFloat, *pChar);

    //alterando o valor das variaveis, atraves dos ponteiros
    *pInt = 65;
    *pFloat += 7;
    (*pChar)++; // ++ tem precedencia a *, portanto deve-se utilizar parenteses
    //sem parenteses, teria sido incrementado o valor do endereco, movendo o ponteiro para o proximo local da memoria

    printf("Exibindo valores apos manipulacao de valores:\n");
    printf("%d %d %d\n", pInt, pFloat, pChar);
    printf("%d %f %c\n\n", *pInt, *pFloat, *pChar);

    //modificando o endereco de memoria onde os ponteiros apontam
    // pInt = &c; //CUIDADO, pInt (que reserva 4 bytes para um inteiro) agora aponta para um char (1 byte), resultando em comportamento inesperado
    // pFloat--; //Move-se para o endereco de memoria anterior, de acordo com um float. Ou seja, subtrai-se 4 (o tamanho de um float) da referencia guardada
    // pChar = &a; //Outra atribuicao ilegal, mas neste caso pode-se observar que o valor inteiro guardado em a eh convertido em um char

    // printf("Exibindo valores apos manipulacao de referencias:\n");
    // printf("%d %d %d\n", pInt, pFloat, pChar);
    // printf("%d # %f # %c\n\n", *pInt, *pFloat, *pChar);

    //criando um ponteiro de ponteiro. nesse caso, p precisa receber o endereco de memoria de um ponteiro
    int **p;
    p = &pInt;

    //aqui exibe-se, respectivamente: o endereco de pInt, o endereco guardado em pInt (endereco da variavel c), e o conteudo da variavel apontada por pInt
    printf("Exibindo valores de ponteiro de ponteiro:\n");
    printf("%d %d %d", p, *p, **p);

    return 0;
}