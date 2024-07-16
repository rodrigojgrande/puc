#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "smartcity.h"

int main() {
    smart_city *cidade = criaCidade(NULL, 2);
    if (cidade == NULL) {
        return EXIT_FAILURE;
    }

    via v1 = {1, "Rua A", 100.5, 1};
    via v2 = {2, "Rua B", 200.0, 2};
    via v3 = {3, "Rua C", 300.75, 1};

    adicionaVia(cidade, v1);
    adicionaVia(cidade, v2);
    adicionaVia(cidade, v3);

    printf("Vias na cidade:\n");
    exibeVias(*cidade);

    printf("\nRemovendo a via com codigo 2...\n");
    removeVia(cidade, 2);

    printf("\nVias na cidade apos remocao:\n");
    exibeVias(*cidade);

    liberaMemoria(cidade);

    return 0;
}
