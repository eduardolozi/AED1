#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

int main() {
    int resp, controle;
    Fila filapar, filaimpar;
    Pilha pilha;

    criaFila(&filaimpar);
    criaFila(&filapar);

    printf("Digite um número (0 para parar de inserir): ");
    scanf("%d", &resp);
    while(resp != 0) {
        if(resp%2==0) insereFila(&filapar, resp);
        else insereFila(&filaimpar, resp);

        printf("Digite um número (0 para parar de inserir): ");
        scanf("%d", &resp);
    }

    printf("----------FILA PAR----------\n");
    imprimeFila(filapar);
    printf("----------FILA ÍMPAR----------\n");
    imprimeFila(filaimpar);

    criaPilha(&pilha);
    while(filaimpar.tamanho != 0 && filapar.tamanho != 0) {
        controle = removeElementoFila(&filaimpar);
        if(controle > 0) {
            inserePilha(&pilha, controle);
        }
        controle = removeElementoFila(&filapar);
        if(controle > 0) {
            inserePilha(&pilha, controle);
        }
    }

    printf("----------PILHA----------\n");
    imprimePilha(pilha);



    liberaFila(&filaimpar);
    liberaFila(&filapar);
    liberaPilha(&pilha);

    return 0;
}