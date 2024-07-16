#ifndef SMART_CITY_H
#define SMART_CITY_H

typedef struct
{
    int codigo;
    char nome[30];
    float comprimento;
    int tipo_piso;
} via;

typedef struct
{
    via *vias;
    int capacidade;
    int tamanho;
} smart_city;

// Funcoes
smart_city* criaCidade(smart_city *cidade, int capacidade);
void redimensionaCapacidade(smart_city *cidade);
void adicionaVia(smart_city *cidade, via novaVia);
void removeVia(smart_city *cidade, int codigo);
void exibeVias(smart_city cidade);
void liberaMemoria(smart_city *cidade);


#endif
