//Eduardo Lozano Azevedo (202103718)

#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 200 //como foi falado no enunciado, podem ser analisados ate 200 códigos por lista

typedef struct TipoItem {
    char * nome;
    int codigo;
} TipoItem;

typedef struct No {
    TipoItem item[MAXTAM]; 
    int primeiro, ultimo;
    int tamanho;
} No;

typedef struct Lista {
    No lista[2]; //pois serão duas listas a serem analisadas
} Lista;

void init(Lista *lista1, Lista *lista2);

int tamanhoNome(char *nome); // para auxiliar na funçao de inserir elementos nas listas

void insereElementoLista1(Lista *lista, char *nome, int codigo);

void insereElementoLista2(Lista *lista, char *nome, int codigo);

void removeElementoLista1(Lista *lista, int pos); //remove o elemento de determinada posiçao

void removeUltimoLista1(Lista *lista);

void removeElementoLista2(Lista *lista, int pos); //remove o elemento de determinada posiçao

void removeUltimoLista2(Lista *lista);

void imprimeLista1(Lista lista);

void imprimeLista2(Lista lista);

void remElemRepList1(Lista *lista); //essa função vai remover elementos repetidos na lista 1, isso facilitará na hora de comparar as duas listas. Assim, ficará apenas uma vez o produto na lista.

void remElemRepList2(Lista *lista);

void comparaListas(Lista lista1, Lista lista2);

void selectionsordLista1(Lista *lista);

void selectionsordLista2(Lista *lista);

void insertionsordLista1(Lista *lista);

void insertionsordLista2(Lista *lista);

void buscaSeqLista1(Lista lista, int codigo);

void buscaSeqLista2(Lista lista, int codigo);

