#include <stdio.h>
#include <stdlib.h>
#include "filasvet.h"

int main() {
    Fila f1;
    int x, controle;
    char resp;

    printf("------CRIAÇÃO DA FILA------\n");
    criaFila(&f1);
    while(resp != 'N' && resp != 'n') {
        printf("Insira um elemento na fila: ");
        scanf("%d", &x);
        enfileira(&f1, x);
        printf("Deseja continuar colocando elementos na fila? Digite S para continuar e N para parar.\n");
        scanf("%*c%c", &resp);
    }
    system("clear||cls");
    printf("Sua fila está assim: \n");
    imprimeFila(&f1);

    resp = 'S';
    while(resp != 'N' && resp != 'n') {
        printf("Você deseja retirar um elemento da lista? Quando quiser parar apenas digite N, para prosseguir digite S.\n");
        scanf("%*c%c", &resp);
        system("clear||cls");
        if(resp != 'N' && resp != 'n') {
            controle = desenfileira(&f1);
            printf("A lista está assim: \n");
            imprimeFila(&f1);
            if(controle==0) printf("A fila está vazia.\n");
        }
    }



    return 0;
}