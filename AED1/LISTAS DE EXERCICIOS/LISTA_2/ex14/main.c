#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

int main() {
    int id, controle;
    char nome[15];
    Fila fila;
    char resp;

    do {
        printf("Insira o nome (máximo 15 letras) do avião: ");
        scanf("%[^\n]", nome);
        printf("Insira o número de identificação do avião: ");
        scanf("%d", &id);
        insereElemento(&fila, nome, id);

        printf("Você deseja saber quantos aviões aguardam a decolagem? DIGITE N SE A RESPOSTA FOR NEGATIVA\n");
        scanf("%*c%c", &resp);
        if(resp != 'N') {
            printf("\n");
            tamanhoFila(fila);
            printf("\n");
        }

        printf("DIGITE 1 PARA VER AS CARACTERÍSCTICAS DO PRIMEIRO AVIÃO DA FILA: ");
        scanf("%d", &controle);
        if(controle == 1) {
            printf("\n");
            imprimePrimeiro(fila);
            printf("\n");
        }

        printf("AUTORIZAR A DECOLAGEM DO PRIMEIRO AVIÃO DA FILA? DIGITE N SE A RESPOSTA FOR NEGATIVA\n");
        scanf("%*c%c", &resp);
        if(resp != 'N') {
            printf("\n");
            removePrimeiro(&fila);
            printf("\n");
        }

        printf("DIGITE 1 PARA VER A FILA: ");
        scanf("%d", &controle);
        if(controle == 1) {
            printf("\n");
            imprime(fila);
            printf("\n");
        }

        printf("Inserir mais um avião? DIGITE N PARA PARAR.\n");
        scanf("%*c%c%*c", &resp);
    }while(resp != 'N');


    libera(&fila);

    return 0;
}