#include<stdio.h>
#include<stdlib.h>

#define MAXTAM 1000

typedef struct fila {
    int item[MAXTAM], tras, frente;
}Fila;

void criaFila(Fila* fila);

void enfileira(Fila* fila, int x);

int desenfileira(Fila* fila);

int filaVazia(Fila* fila);

void imprimeFila(Fila* fila);