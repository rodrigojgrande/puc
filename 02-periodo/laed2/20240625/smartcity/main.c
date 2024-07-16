#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "smartcity.h"

int main() {
    // Criando uma cidade com capacidade inicial de 5 vias
    smart_city *cidade = criaCidade(NULL, 5);

    // Adicionando vias a essa cidade
    via via1 = {1, "Rua A", 100.5, 1};
    via via2 = {2, "Cruzamento B", 200.0, 2};
    via via3 = {3, "Viela C", 150.75, 1};
    via via4 = {4, "Praca D", 123.3, 2};
    via via5 = {5, "Avenida E", 100.00, 1};

    adicionaVia(cidade, via1);
    adicionaVia(cidade, via2);
    adicionaVia(cidade, via3);
    adicionaVia(cidade, via4);
    adicionaVia(cidade, via5);

    // Exibindo as vias da cidade para verificar se todas foram adicionadas
    printf("Vias da cidade:\n");
    exibeVias(*cidade);
    printf("\n");

    // Criando uma fila de pedidos
    Fila fila;
    criaFila(&fila);

    // Inserindo os pedidos na fila
    insereFila(&fila, "Pedido 1, interditar via 2");
    insereFila(&fila, "Pedido 2, interditar via 5");
    insereFila(&fila, "Pedido 3, consertar vias");

    // Mostrando a fila de pedidos
    printf("\nFila de pedidos:\n");
    mostraFila(fila);
    printf("\n");

    printf("Removendo vias de codigo 2 e 5\n");
    // Removendo vias
    removeVia(cidade, 2);
    removeVia(cidade, 5);

    // Exibindo as vias da cidade para verificar se a remocao ocorreu corretamente
    printf("\nVias atualizadas da cidade:\n");
    exibeVias(*cidade);
    printf("\n");

    printf("\nRetirando os pedidos da fila\n");
    char pedidoRetirado[100];
    // Retirando pedido 1
    if (retiraFila(&fila, pedidoRetirado))
        printf("Pedido retirado: %s\n", pedidoRetirado);

    // Retirando pedido 2
    if (retiraFila(&fila, pedidoRetirado))
        printf("Pedido retirado: %s\n", pedidoRetirado);

    // Mostrando a fila de pedidos apos a retirada
    printf("\nFila de pedidos atualizada:\n");
    mostraFila(fila);
    printf("\n");

    // Criando a lista de caminhos entre as vias
    ListaCDE lista;
    criaLista(&lista);

    // Inserindo elementos na lista
    insereLista(&lista, 1);
    insereLista(&lista, 3);
    insereLista(&lista, 2);
    insereLista(&lista, 5);
    insereLista(&lista, 4);

    // Mostrando a lista no sentido do comeco ao fim
    printf("Lista de caminhos antes dos pedidos (da primeira via a ultima):\n");
    mostraLista(lista, 0);
    printf("\n");

    // Mostrando a lista no sentido do fim para o comeco
    printf("Lista de caminhos antes dos pedidos (da ultima via ate a primeira):\n");
    mostraLista(lista, 1);
    printf("\n");

    // Retirando as vias demolidas da lista
    retiraLista(&lista, 2);
    retiraLista(&lista, 5);

    // Mostrando a lista apos remover um dos caminhos
    printf("Lista de caminhos atualizada (da primeira a ultima via):\n");
    mostraLista(lista, 0);
    printf("\n");

    // Liberando a memoria alocada
    liberaMemoria(cidade);
    for(int i = 0; i < 5; i++){
        retiraLista(&lista, i);
    }
    retiraFila(&fila, pedidoRetirado);
    return 0;
}
