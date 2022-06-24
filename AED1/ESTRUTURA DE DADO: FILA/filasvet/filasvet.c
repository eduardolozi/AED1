#include<stdio.h>
#include<stdlib.h>
#include"filasvet.h"

#define MAXTAM 1000

void criaFila(Fila* fila) {
    fila->frente=0;
    fila->tras = fila->frente;
}

int filaVazia(Fila* fila) {
    return(fila->frente == fila->tras);
}

void enfileira(Fila* fila, int x) {
    if(fila->tras - fila->frente >= MAXTAM) return;
    else {
        fila->item[fila->tras] = x;
        fila->tras++;
    }
}

int desenfileira(Fila* fila) {
    if(filaVazia(fila)==1) return 0;
    int x = fila->item[fila->frente];
    fila->frente++;
    printf("O número %d foi desenfileirado.\n", x);
    return 1;
}

void imprimeFila(Fila* fila) {
    int i;
    for(i=fila->frente;i<fila->tras;i++) {
        printf("%d\n", fila->item[i]);
    }
}