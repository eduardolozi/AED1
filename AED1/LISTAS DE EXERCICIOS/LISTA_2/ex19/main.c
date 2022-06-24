#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

int main() {
    Pilha pilha;
    char vetor1[4] = {'2', '0', '0', '2'};
    char vetor2[5] = {'E', 'D', 'U', 'D', 'E'};
    int i;

    criaPilha(&pilha);
    for(i=0;i<4;i++) {
        insere(&pilha, vetor1[i]);
    }
    imprime(pilha);
    printf("\n");
    palindromo(pilha);
    libera(&pilha);

    printf("\n");
    criaPilha(&pilha);
    for(i=0;i<5;i++) {
        insere(&pilha, vetor2[i]);
    }
    imprime(pilha);
    printf("\n");
    palindromo(pilha);
    libera(&pilha);

    return 0;
}