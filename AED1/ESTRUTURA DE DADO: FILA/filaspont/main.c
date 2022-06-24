#include <stdio.h>
#include <stdlib.h>
#include "filaspont.h"

int main() {
    Fila fila;
    int controle1, controle2, x;
    char resp, resp2;

    printf("------CRIANDO FILA------\n");
    controle1 = criaFila(&fila);
    if(controle1==1) printf("Fila criada com sucesso.\n");
    else  {
        printf("Erro ao criar a fila.\n");
        return 0;
    }

    controle2 = filaVazia(&fila);
    if(controle2 == 1) printf("A lista está vazia.\n");
    else  {
        printf("A fila não está vazia.\n");
    }

    while(resp != 'N' && resp != 'n') {
        printf("Insira um elemento na fila: ");
        scanf("%d", &x);
        enfileira(&fila, x);
        printf("Você deseja continuar colocando elementos na fila? Digite S ou N.\n");
        scanf("%*c%c", &resp);
    }
    system("clear || cls");
    printf("A fila está assim: \n");
    imprime(fila);

    while(resp2 != 'N' && resp2 != 'n') {
        printf("Você deseja retirar um elemento da fila? Digite S ou N.\n");
        scanf("%*c%c", &resp2);
        system("clear || cls");
        if(resp2 != 'N' && resp2 != 'n') {
            desenfileira(&fila);
            printf("A fila está assim: \n");
            imprime(fila);
        }
    }

    libera(&fila);

    return 0;
}