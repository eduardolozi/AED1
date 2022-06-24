// Eduardo Lozano Azevedo 202103718

#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

int main() {
    int max, controle, cont=0;
    Lista l;
    char placa[6];
    char resp, resp1;
    int x;

    controle = criaLista(&l);
    if(controle==1) printf("Lista criada com sucesso.\n");
    else {
        printf("Não foi possível crair a lista.\n");
        return 0;
    }
    printf("Quantos veículos são capazes de ser transportados? ");
    scanf("%d", &max);

    while(resp != 'N' && resp != 'n') {
        printf("\nInsira a placa do novo veículo: (DEVE CONTER 6 DIGITOS).\n");
        scanf("%*c%s", placa);
        insere(&l, placa, max);

        controle = capacidade(&l);
        if(controle == 1) break;

        printf("Será colocado mais um veículo na balsa? Digite N para para, e qualquer outra letra para continuar.\n");
        scanf("%*c%c", &resp);
    }

    printf("\nA lista de veículos se encontra assim: \n");
    imprime(&l);

    while(resp1 != 'N' || resp1 != 'n') {
        printf("Escolha uma posição para realizar a retirada: ");
        scanf("%d", &x);
        retira(&l, x);
        printf("A lista agora está assim: \n");
        imprime(&l);
    }


    return 0;
}