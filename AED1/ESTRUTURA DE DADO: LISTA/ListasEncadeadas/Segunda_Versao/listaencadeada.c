#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.h"

void criaLista(Lista *lista) {
    lista->inicio = NULL;
    lista->tam = 0;
}

void insereElementoInicio(Lista *lista, int x) {
    No *novo = malloc(sizeof(No));

    if(novo!=NULL) {
        novo->valor = x;
        novo->proximo = lista->inicio; // o novo nó vai apontar para o elemento que lista->inicio aponta.
        lista->inicio = novo; // agora lista->inicio vai apontar para o novo nó.
        lista->tam++;
    }
    else printf("Erro ao alocar memória.\n");
}

void insereElementoFinal(Lista *lista, int x) {
    No *novo = malloc(sizeof(No));
    No *aux = malloc(sizeof(No));

    if(novo!=NULL) {
        novo->valor = x;
        novo->proximo = NULL;

        if(lista->inicio == NULL) { //se a lista estiver vazia
            lista->inicio = novo;
        }
        else {
            aux = lista->inicio;
            while(aux->proximo != NULL) {
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
        lista->tam++;
    }
}

void insereElementoMeio(Lista *lista, int x, int ant) {
    No *novo = malloc(sizeof(No));
    No *aux = malloc(sizeof(No));

    if(novo!=NULL) {
        novo->valor = x;
        if(lista->inicio == NULL) { //se a lista estiver vazia
            novo->proximo = NULL;
            lista->inicio = novo;
        }
        else {
            aux = lista->inicio;
            while((aux->valor != ant) && (aux->proximo != NULL)) { //se um for descumprido o loop acaba
                aux = aux->proximo;
            } 
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else printf("Erro ao alocar memória.\n");
}

void insereOrdenado(Lista *lista, int x) {
    No *aux = malloc(sizeof(No));
    No *novo = malloc(sizeof(No));

    if(novo) {
        novo->valor = x;

        if(lista->inicio == NULL) {
            novo->proximo = NULL;
            lista->inicio = novo;
        }
        else if(lista->inicio && novo->valor < lista->inicio->valor) { //se o elemento for menor do q o primeiro da lista
            novo->proximo = lista->inicio;
            lista->inicio = novo; // atualizando pra quem aponta o inicio.
        }
        else {
            aux = lista->inicio;
            while(aux->proximo && (novo->valor > aux->proximo->valor)) {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo; 
            aux->proximo = novo; // atualizando pra quem o anterior vai apontar agora.
        }
        lista->tam++;
    }
    else printf("Erro ao alocar memória.\n");
}

void removeElemento(Lista* lista, int x) {
    No *remove = NULL; // inicializa eles eme NULL, pois se o elemento nao estiver, sera NULL.
    No *aux = NULL;

    if(lista->inicio == NULL) {
        printf("A lista está vazia.\n");
        return;
    }
    else {
        if(lista->inicio->valor == x) {  //se quiser remover o 1 elemento
            remove = lista->inicio;
            lista->inicio = remove->proximo; // o inicio passa a ser o segundo elemento
            lista->tam--;
        }
        else {
            aux = lista->inicio;
            while(aux->proximo && aux->proximo->valor != x) {
                aux = aux->proximo;
            }
            if(aux->proximo) { // caso o aux->prox nao for NULL, entao o loop quebrou pq achou o elemento na lista
                remove = aux->proximo;
                aux->proximo = remove->proximo;
                lista->tam--;
            }
            else {
                printf("O elemento não está na lista.\n");
            }
        }
    }

    if(remove!=NULL) {
        printf("O elemento %d foi excluido.\n", remove->valor);
        free(remove);
    }
}

void removePosicao(Lista *lista, int pos) {
    No *aux = NULL;
    No *remove = NULL;

    if(lista->inicio == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    if(lista->tam < pos) {
        printf("Posição inexistente na lista.\n");
        return;
    }
    else {
        if(pos <= 0) {
            printf("Posição inexistente.\n");
            return;
        }
        if(pos == 1) {
            remove = lista->inicio;
            lista->inicio = remove->proximo;
            lista->tam--;
        }
        else {
            int cont=0;
            aux = lista->inicio;

            while(cont < pos-2) {
                aux = aux->proximo;
                cont++;
            }
            remove = aux->proximo;
            aux->proximo = remove->proximo;
            lista->tam--;
        }
    }

    if(remove!=NULL) {
        printf("O elemento na posição %d foi excluído.\n", pos);
        free(remove);
    }
}

void buscaElemento(Lista *lista, int num) {
    No *no = NULL;
    No *aux = NULL;

    aux=lista->inicio;
    while(aux && aux->valor != num) {
        aux = aux->proximo;
    }
    if(aux) {
        no = aux;
    }

    if(no != NULL) {
        printf("O valor %d foi encontrado na lista.\n", no->valor); // nao dar free, pois senao o valor some e dps para excluir ele com alguma funçao, da erro pois ele nao existe mais.
    }
    else {
        printf("O elemento não faz parte da lista.\n");
    }
}

void libera(Lista *lista) {
    No *aux = NULL;

    if(lista->inicio == NULL) {
        printf("Erro: Lista vazia.\n");
        return;
    }

    while(lista->inicio != NULL) {
        aux = lista->inicio;
        lista->inicio = lista->inicio->proximo;
        free(aux);
    }
    aux = lista->inicio; //coloca fora depois pq ainda falta excluir o ultimo elemento.
    free(aux);

    if(aux == NULL) {
        printf("Memória desalocada com sucesso.\n");
    }
    else {
        printf("Erro ao desalocar memória.\n");
    }
}

void imprime(Lista lista) {
    No *no = lista.inicio;
    printf("Lista de tamanho %d: ", lista.tam);
    while(no) {
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n");
}