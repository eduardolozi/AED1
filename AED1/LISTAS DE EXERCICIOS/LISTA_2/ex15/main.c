#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

int main() {
    int vet1[5] = {9, 3, 5, 7, 1};
    int vet2[5] = {0, 4, 2, 8, 6};
    int i;
    Fila f1;
    Fila f2;
    Fila f3;

    criaFila(&f1);
    for(i=0;i<5;i++) {
        insere(&f1, vet1[i]);
    }
    ordenaCrescente(&f1);

    criaFila(&f2);
    for(i=0;i<5;i++) {
        insere(&f2, vet2[i]);
    }
    ordenaCrescente(&f2);

    criaFila(&f3);
    juntaFilas(f1, f2, &f3);
    ordenaCrescente(&f3);

    imprime(f1);
    printf("\n");
    imprime(f2);
    printf("\n");
    imprime(f3);
    printf("\n");
    libera(&f1);
    libera(&f2);
    libera(&f3);

    return 0;
}