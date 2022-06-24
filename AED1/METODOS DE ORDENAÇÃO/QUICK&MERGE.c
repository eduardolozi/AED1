#include <stdio.h>
#include <stdlib.h>

void quickSort(int *vetor, int esq, int dir);

void mergeSort(int *vetor, int inicio, int fim);

void merge(int *vetor, int inicio, int meio, int fim);

int main() {
    int vetor[6] = {10, 3, 5, 1, 5, 2};
    int vetor2[6] = {10, 3, 5, 1, 5, 2};
    int i;

    //mergeSort(&vetor, 0, 5);
    quickSort(vetor, 0, 5);
    for(i=0;i<6;i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    mergeSort(vetor2, 0, 5);
    for(i=0;i<6;i++) {
        printf("%d ", vetor2[i]);
    }
    printf("\n");

    return 0;
}

/* ---------------------------------------------------------QUICK SORT---------------------------------------------------*/ 
void quickSort(int *vetor, int esq, int dir){
    int pivo = vetor[(esq+dir) / 2];
    int i = esq;
    int j = dir;
    int aux;

    while(i<=j) {
        while(vetor[i] < pivo && i < dir) {
            i++;
        }
        while(vetor[j] > pivo && j > esq) {
            j--;
        }

        if(i <= j) {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    }

    if(j > esq) {
        quickSort(vetor, esq, j);
    }
    if(i < dir) {
        quickSort(vetor, i, dir);
    }
}

/* ---------------------------------------------------------MERGE SORT---------------------------------------------------*/ 
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
