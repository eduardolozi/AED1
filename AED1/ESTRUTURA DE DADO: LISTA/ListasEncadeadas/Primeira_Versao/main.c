#include <stdio.h>
#include <stdlib.h>
#include "listasencadeadas.h"

int main() {
    No *lista = NULL; // esse ponteiro para a struct No smp vai apontar para o primeiro elemento da lista, portanto guarda um endereço de memoria ja que é um ponteiro.
    int option, num, ant;

    do {
        printf("Digite:\n0 - SAIR\n1 - INSERIR NUMERO NO INICIO\n2 - INSERIR NUMERO NO MEIO\n3 - INSERIR NUMERO NO FINAL\n4 - INSERIR ORDENADO\n5 - REMOVER ELEMENTO\n6 - BUSCAR ELEMENTO\n7 - IMPRIMIR A LISTA\n");

        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("Digite o número que deseja inserir: ");
                scanf("%d", &num);
                insereElementoInicio(&lista, num);
                break;
            case 2:
                printf("Digite o número que deseja inserir e o número antecessor a ele: ");
                scanf("%d %d", &num, &ant);
                insereElementoMeio(&lista, num, ant);
                break;
            case 3:
                printf("Digite o número que deseja inserir: ");
                scanf("%d", &num);
                insereElementoFinal(&lista, num);
                break;
            case 4:
                printf("Digite o número que deseja inserir: ");
                scanf("%d", &num);
                insereOrdenado(&lista, num);
                break;
            case 5:
                printf("Digite o número que deseja remover: ");
                scanf("%d", &num);
                removeElemento(&lista, num);
                break;
            case 6:
                printf("Digite o número que você deseja buscar: ");
                scanf("%d", &num);
                busca(&lista, num);
                break;
            case 7:
                imprimir(lista);
                break;
            default:
                if(option != 0) printf("Opção inválida!\n");
        }
        
    } while(option != 0);


    return 0;
}