#include <stdio.h>
#include <stdlib.h>
#include "listaDE.h"

int main() {
    Lista lista;
    int option, num, ant;

    criaLista(&lista);

    do {
        printf("Digite:\n0 - SAIR\n1 - INSERIR NUMERO NO INICIO\n2 - INSERIR NUMERO NO FINAL\n3 - REMOVER PRIMEIRO ELEMENTO\n4 - REMOVER ULTIMO ELEMENTO\n5 - IMPRIMIR A LISTA DESDE O INICO\n6 - IMPRIMIR A LISTA DESDE O FIM\n");

        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("Digite o número que deseja inserir: ");
                scanf("%d", &num);
                insereElementoInicio(&lista, num);
                break;
            case 2:
                printf("Digite o número que deseja inserir: ");
                scanf("%d", &num);
                insereElementoFinal(&lista, num);
                break;
            case 3:
                retiraElementoInicio(&lista);
                break;
            case 4:
                retiraElementoFinal(&lista);
                break;
            case 5:
                imprimeInicio(lista);
                break;
            case 6:
                imprimeFim(lista);
                break;
            default:
                if(option != 0) printf("Opção inválida!\n");
        }
        
    } while(option != 0);
    
    libera(&lista);


    return 0;
}