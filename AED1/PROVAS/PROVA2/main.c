//Eduardo Lozano Azevedo (202103718)

#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

int main() {
    Lista lista1, lista2;

    init(&lista1, &lista2);
    printf("\n");

    insereElementoLista1(&lista1, "Geladeira Eletrolux", 222);
    insereElementoLista1(&lista1, "Manteiga Delicia", 217); 
    insereElementoLista1(&lista1, "Geladeira Eletrolux", 222);
    insereElementoLista1(&lista1, "Microondas", 876);
    insereElementoLista1(&lista1, "Fogão 4 bocas", 99);
    insereElementoLista1(&lista1, "Fogão 4 bocas", 99);
    insereElementoLista1(&lista1, "Manteiga Delicia", 217);
    //insereElementoLista1(&lista1, "Microondas", 876);
    //insereElementoLista1(&lista1, "PlayStation", 1004);
    remElemRepList1(&lista1); //vai remover as duas aparições extras do Fogao 4 bocas
    imprimeLista1(lista1);

    insereElementoLista2(&lista2, "Geladeira Eletrolux", 222);
    insereElementoLista2(&lista2, "Microondas", 876);
    insereElementoLista2(&lista2, "Fogão 4 bocas", 99);
    insereElementoLista2(&lista2, "Manteiga Delicia", 217);
    insereElementoLista2(&lista2, "Balinha de morango", 100);
    insereElementoLista2(&lista2, "Tapete Estrelado", 1);
    removeUltimoLista2(&lista2);
    remElemRepList2(&lista2);
    imprimeLista2(lista2);

    printf("COMPARANDO LISTAS:\n");
    comparaListas(lista1, lista2);

    printf("\nORDENANDO A LISTA 1 PELO CÓDIGO:\n");
    selectionsordLista1(&lista1);
    //insertionsordLista1(&lista1);
    imprimeLista1(lista1);

    printf("ORDENANDO A LISTA 2 PELO CÓDIGO:\n");
    selectionsordLista2(&lista2);
    //insertionsordLista2(&lista2);
    imprimeLista2(lista2);

    buscaSeqLista1(lista1, 222);
    buscaSeqLista1(lista1, 876);
    buscaSeqLista1(lista1, 9999);

    buscaSeqLista2(lista2, 217);
    buscaSeqLista2(lista2, 876);
    buscaSeqLista2(lista2, 4);


    return 0;
}

/*compilar usando as seguintes linhas de comando:
    1 - gcc -c tad.c -o tad.o
    2 - gcc main.c tad.o -o main
    3 - ./main
*/