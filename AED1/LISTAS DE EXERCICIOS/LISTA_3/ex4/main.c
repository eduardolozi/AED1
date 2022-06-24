#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

int main() {
    Lista lista;

    init(&lista);
    insereElementoFim(&lista, 202103718, 7.5678);
    insereElementoFim(&lista, 202103710, 8);
    insereElementoFim(&lista, 202103719, 9.1);
    insereElementoFim(&lista, 202103711, 7.5677);
    insereElementoFim(&lista, 202103709, 7.5679);
    insereElementoFim(&lista, 202103718, 1.25);

    imprimeLista(lista);

    libera(&lista);


    return 0;
}