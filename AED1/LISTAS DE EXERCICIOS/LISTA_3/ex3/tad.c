#include <stdio.h>
#include <stdlib.h>
#include "tad.h" 

void intercala3vetores(int *vetInt, int *vet1, int tamv1, int *vet2, int tamv2, int *vet3, int tamv3) {
    int tam = tamv1+tamv2+tamv3;
    int vetorInt[tam];
    int i, j, k;
    for(i=0;i<tamv1;i++) {
        vetInt[i] = vet1[i];   
    }
    for(j=0;j<tamv2;j++) {
        vetInt[i] = vet2[j];
        i++;
    }
    for(k=0;k<tamv3;k++) {
        vetInt[i] = vet3[k];
        i++;
    }
}

void mergeSort(int *vetor, int inicio, int fim) { //o fim se refere ao ultimo indice do vetor, nao ao tamanho
    int meio;

    if(inicio<fim) {
        meio = (inicio+fim)/2;

        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

void merge(int *vetor, int inicio, int meio, int fim) {
    int com1 = inicio, com2 = meio+1, comAux = 0, vetAux[fim-inicio+1];

    while((com1 <= meio) && (com2 <= fim)) {
        if(vetor[com1] <= vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        }
        else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    //esses dois whiles são acionados caso uma das partes (inicio-meio ou meio+1-fim) nao esteja ordenada ainda
    while(com1 <= meio) { 
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }
    while(com2 <= fim) {
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }
    for(comAux = inicio;(comAux <= fim);comAux++) { //vai sobrescrever os dados do vetor inicial, colocando o vetor ordenado
        vetor[comAux] = vetAux[comAux - inicio];
    }
}