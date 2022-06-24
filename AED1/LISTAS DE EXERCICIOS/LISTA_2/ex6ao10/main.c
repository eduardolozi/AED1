#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

int main() {
    int vetor1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int vetor2[10] = {1, 5, 10, 15, 20, 25, 30, 35};
    Lista lista1, lista2, lista3, lista4;
    int soma;

    criaLista(&lista1);
    criaLista(&lista2);

    //exercício 6
    criaListaVetor(&lista1, vetor1, 10);
    printf("Lista 1: ");
    imprime(lista1);
    
    criaListaVetor(&lista2, vetor2, 8);
    printf("Lista 2: ");
    imprime(lista2);

    //exercício 7
    concatena(lista1, lista2, &lista3);
    printf("Lista concatenada: ");
    imprime(lista3);

    //exercício 8
    printf("Lista concatenada sem repetições: ");
    excluiRepetidos(&lista3);
    imprime(lista3);

    //exercício 9
    intercala(lista1, lista2, &lista4);
    printf("Lista intercalada: ");
    imprime(lista4);
    
    //exercício 10
    soma = somaLista(lista1);
    printf("Soma da lista 1: %d\n", soma);

    soma = somaLista(lista2);
    printf("Soma da lista 2: %d\n", soma);


    liberaLista(&lista1);
    liberaLista(&lista2);
    liberaLista(&lista3);

    return 0;
}