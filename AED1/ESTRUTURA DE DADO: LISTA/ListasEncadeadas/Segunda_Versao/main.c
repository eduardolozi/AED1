#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.h"

int main() {
    Lista lista;
    int option, num, ant;

    criaLista(&lista);

    do {
        printf("Digite:\n0 - SAIR\n1 - INSERIR NUMERO NO INICIO\n2 - INSERIR NUMERO NO MEIO\n3 - INSERIR NUMERO NO FINAL\n4 - INSERIR ORDENADO\n5 - REMOVER ELEMENTO\n6 - REMOVER POSIÇÃO\n7 - BUSCA ELEMENTO\n8 - IMPRIMIR A LISTA\n");

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
                printf("Digite a posição que deseja excluir: ");
                scanf("%d", &num);
                removePosicao(&lista, num);
                break;
            case 7:
                printf("Digite o número que você deseja buscar: ");
                scanf("%d", &num);
                buscaElemento(&lista, num);
                break;
            case 8:
                imprime(lista);
                break;
            default:
                if(option != 0) printf("Opção inválida!\n");
        }
        
    } while(option != 0);
    
    libera(&lista);


    return 0;
}