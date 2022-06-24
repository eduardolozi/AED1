#include <stdio.h>
#include <stdlib.h>
#include "tad.h" 

int main() {
    int i;
    int vet1[5] = {1, 10, 20, 30, 50};
    int vet2[5] = {2, 15, 17, 19, 51};
    int vet3[5] = {3, 5, 6, 98, 101};
    int vet4[15];
   
    intercala3vetores(vet4, vet1, 5, vet2, 5, vet3, 5);

    printf("------VETOR DESORDENADO-------\n");
    for(i=0;i<15;i++) {
        printf("%d ", vet4[i]);
    }
    printf("\n");

    mergeSort(vet4, 0, 14);
    printf("------VETOR ORDENADO-------\n");
    for(i=0;i<15;i++) {
        printf("%d ", vet4[i]);
    }
    printf("\n");
    return 0;
}