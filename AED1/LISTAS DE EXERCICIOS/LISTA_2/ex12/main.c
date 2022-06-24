#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

int main() {
    int num, prioridade, base;
    Fila fila1;
    Fila fila2;
    Fila fila3;
    char resp;

    criaFila(&fila1);

    do{
        printf("Digite o elemento e a sua prioridade: \n~ Elemento: ");
        scanf("%d", &num);
        printf("\n~ Prioridade: ");
        scanf("%d", &prioridade);

        enfileira(&fila1, num, prioridade);

        printf("\nVocê deseja continuar? Digite N para parar de inserir elementos.\n");
        scanf("%*c%c", &resp);
    }while(resp != 'N');

    system("clear || cls");
    imprime(fila1);

    criaFila(&fila2);
    criaFila(&fila3);


    printf("Digite o valor base P que você desejar: ");
    scanf("%d", &base);

    
    divideFilas(fila1, &fila2, &fila3, base);
    printf("Filas dividas.\n");
    printf("----------------------------------------------------\n");
    printf("\nFILA COM A PRIORIDADE MENOR OU IGUAL A PRIORIDADE P\n");
    imprime(fila2);
    printf("\n");
    printf("----------------------------------------------------\n");
    printf("\nFILA COM A PRIORIDADE MAIOR DO QUE A PRIORIDADE P\n");
    imprime(fila3);
    printf("\n");
    printf("----------------------------------------------------\n");
    
    libera(&fila1);
    libera(&fila2);
    libera(&fila3);
    return 0;
}