#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

int main() {

    Pilha pilha;
    int vetor[5] = {1, 2, 3, 4, 5};
    int i, num;

    criaPilha(&pilha);
    for(i=0;i<5;i++) {
        insere(&pilha, vetor[i]);
    }

    printf("A pilha criada foi:\n");
    imprime(pilha);

    num = retira(&pilha);
    if(num==0) printf("A lista está vazia.\n");
    else printf("O número %d foi retirado.\n", num);

    printf("Agora a pilha está assim: \n");
    imprime(pilha);

    printf("\n");
    libera(&pilha);

    return 0;
}