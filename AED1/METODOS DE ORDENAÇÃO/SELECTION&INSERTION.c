#include <stdio.h>
#include <stdlib.h>

#define N_MAX 10

typedef struct TipoItem {
    int numero;
} TipoItem;

typedef struct No {
    TipoItem vetor[N_MAX];
    int tam;
} No;

void init(No *v);

void insereElemento(No *v, int numero);

void selectionsord(No *v, int tam);

void insertionsord(No *v, int tam);

void imprime(No *v);

int main() {
    int v[8] = {190, 1, 5, 10, 5, 3, 1, 0};
    int i;
    No vetor[8];

    init(vetor);
    
    for(i=0;i<8;i++) {
        insereElemento(vetor, v[i]);
    }

    printf("O VETOR ADICIONADO FOI: \n");
    imprime(vetor);
    printf("\n");
    
    /*printf("O VETOR ORGANIZADO FICA: \n");
    selectionsord(vetor, 5);
    imprime(vetor);
    printf("\n");*/

    printf("O VETOR ORGANIZADO FICA: \n");
    insertionsord(vetor, 8);
    imprime(vetor);
    printf("\n");

    return 0;
}

void init(No *v) {
    v->tam = 0;
}

void insereElemento(No *v, int numero) {
    if(v->tam >= N_MAX) {
        printf("ERRO: Vetor com capacidade máxima.\n");
    }
    else {
        v->vetor[v->tam].numero = numero;
        v->tam++;
    }
}

void imprime(No *v) {
    int i;
    for(i=0;i<v->tam;i++) {
        printf("%d ", v->vetor[i].numero);
    }
}

void selectionsord(No *v, int tam) {
    int i, j, aux, menor;

    for(i=0;i<tam;i++) {
        menor = i;  //a variavel menor pega o indice do valor a ser comparado
        for(j=i+1;j<tam;j++) {
            if(v->vetor[menor].numero > v->vetor[j].numero) { //ve se o valor a direita dele é menor que ele
                menor = j; //a variavel menor pega o indice do numero, pois fará a troca de posições logo apos a condicional
            }
            aux = v->vetor[i].numero;
            v->vetor[i].numero = v->vetor[menor].numero;
            v->vetor[menor].numero = aux;
        }
    }
}

void insertionsord(No *v, int tam) {
    int i, j, aux, aux2;

    for(i=1;i<tam;i++) {
        aux2 = i; //essa variavel vai pegar o valor de i para conseguir manusear o indice dentro do proximo loop

        for(j=i-1;j>=0;j--) { //percorremos o vetor em direçao da esquerda para ver se esxitem valores maiores que o valor da posicao i
            if(v->vetor[aux2].numero < v->vetor[j].numero) {  //se o valor à esquerda for maior, ocorre uma troca
                aux = v->vetor[aux2].numero;
                v->vetor[aux2].numero = v->vetor[j].numero;
                v->vetor[j].numero = aux; 
            }
            else break; //se o valor a esquerda não for maior, entao quebra o loop
            aux2--; //aqui atualizamos o novo indice que o valor vai ocupar na lista, por ex: se estivesse na 3a e tivesse ido para a 2a
        }
        
    }
}
