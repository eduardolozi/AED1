#include <stdio.h>
#include <stdlib.h>
#include "listasvet.h"

int main() {
    Lista* l, *l2;
    int x, pos, temp;
    char c, resp, resp2;

    criaLista(l);

    while(resp != 'N') {
        printf("Insira um elemento na lista: ");
        scanf("%d", &x);
        insereLista(l, x);

        printf("Você deseja retirar algum elemento da lista? Digite S ou N.\n");
        scanf("%*c%c", &c);
        if(c == 'S') {
            printf("Posição do número a excluir: ");
            scanf("%d", &pos);
            retiraLista(l, pos);
        }

        printf("Você deseja saber se a lista está vazia? Se ela não estiver, será mostrada a lista. Digite S ou N.\n");
        scanf("%*c%c", &c);
        if(c == 'S') {
            temp = listaVazia(l);
            if(temp == 1) {
                printf("A lista está vazia. Agora será mostrada a lista: \n");
            }
            else {
                printf("A lista não está vazia. Agora será mostrada a lista:\n");
                imprimeLista(l);
            }
        }
        printf("Você deseja continuar? Digite S ou N.\n");
        scanf("%*c%c", &resp);
        system("clear||cls");
    }



    return 0;
}