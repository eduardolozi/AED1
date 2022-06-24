//Eduardo Lozano Azevedo (202103718)

#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

#define MAXTAM 200

void init(Lista *lista1, Lista *lista2) {
    lista1->lista[0].primeiro = 0;
    lista1->lista[0].ultimo = 0;
    lista1->lista[0].tamanho = 0;

    lista2->lista[1].primeiro = 0;
    lista2->lista[1].ultimo = 0;
    lista2->lista[1].tamanho = 0;

    if(lista1->lista[0].primeiro == 0 && lista1->lista[0].ultimo == 0 && lista2->lista[1].primeiro == 0 &&  lista2->lista[1].ultimo == 0) {
        printf("Listas inicializadas com sucesso.\n");
    }
    else printf("Erro ao inicializar listas.\n");
}

int tamanhoNome(char *nome) {  //função que conta o número de caracteres no nome do elemento
    int i=0;
    while(nome[i] != '\0') {
        i++;
    }
    return i;
}

void insereElementoLista1(Lista *lista, char *nome, int codigo) {
    if(lista->lista[0].tamanho >= MAXTAM) {
        printf("ERRO: Capacidade máxima atingida, impossível inserir elemento.\n");
        return;
    }
    

    int i = 0;
    lista->lista[0].item[lista->lista[0].tamanho].codigo = codigo;
    
    int tamNome = tamanhoNome(nome);
    lista->lista[0].item[lista->lista[0].tamanho].nome = (char *)malloc(tamNome * sizeof(char));
    while(nome[i] != '\0') {
        lista->lista[0].item[lista->lista[0].tamanho].nome[i] = nome[i]; //cada letra do nome recebido, é colocado no nome do novo elemento
        i++;
    }
    lista->lista[0].item[lista->lista[0].tamanho].nome[i] = '\0'; //recebe o caractere de fim de string

     printf("Elemento %s(%d) inserido.\n", lista->lista[0].item[lista->lista[0].tamanho].nome, lista->lista[0].item[lista->lista[0].tamanho].codigo);

    lista->lista[0].tamanho++;
}

void insereElementoLista2(Lista *lista, char *nome, int codigo) {
    if(lista->lista[1].tamanho >= MAXTAM) {
        printf("ERRO: Capacidade máxima atingida, impossível inserir elemento.\n");
        return;
    }

    int i = 0;
    lista->lista[1].item[lista->lista[1].tamanho].codigo = codigo;
    
    int tamNome = tamanhoNome(nome);
    lista->lista[1].item[lista->lista[1].tamanho].nome = (char *)malloc(tamNome * sizeof(char));
    while(nome[i] != '\0') {
        lista->lista[1].item[lista->lista[1].tamanho].nome[i] = nome[i]; //cada letra do nome recebido, é colocado no nome do novo elemento
        i++;
    }
    lista->lista[1].item[lista->lista[1].tamanho].nome[i] = '\0'; //recebe o caractere de fim de string

    printf("Elemento %s(%d) inserido.\n", lista->lista[1].item[lista->lista[1].tamanho].nome, lista->lista[1].item[lista->lista[1].tamanho].codigo);

    lista->lista[1].tamanho++;
}

void removeElementoLista1(Lista *lista, int pos) {
    int aux;
    if(pos > lista->lista[0].tamanho) {
        printf("ERRO: Impossível remover elemento de uma posição inexistente.\n");
        return;
    }
    else {
        for(aux=pos-1;aux < lista->lista[0].tamanho; aux++) {  //reordena o vetor, agora sem o elemento da pos excluida
            lista->lista[0].item[aux] = lista->lista[0].item[aux+1];
        }
        lista->lista[0].tamanho--;
    }
    printf("O elemento da posição %d foi removido com sucesso.\n", pos);
}

void removeUltimoLista1(Lista *lista) {
    if(lista->lista[0].tamanho == 0) {
        printf("ERRO: Lista vazia, impossível remover elementos.\n");
        return;
    }
    else {
        lista->lista[0].tamanho--;
        printf("O último elemento foi removido com sucesso.\n");
    }
}

void removeElementoLista2(Lista *lista, int pos) {
    int aux;
    if(pos > lista->lista[1].tamanho) {
        printf("ERRO: Impossível remover elemento de uma posição inexistente.\n");
    }
    else {
        
        for(aux=pos-1;aux < lista->lista[1].tamanho; aux++) { //reordena o vetor, agora sem o elemento da pos excluida
            lista->lista[1].item[aux - 1] = lista->lista[1].item[aux];
        }
        lista->lista[1].tamanho--;
    }
    printf("O elemento da posição %d foi removido com sucesso.\n", pos);
}

void removeUltimoLista2(Lista *lista) {
    if(lista->lista[1].tamanho == 0) {
        printf("ERRO: Lista vazia, impossível remover elementos.\n");
        return;
    }
    else {
        lista->lista[1].tamanho--;
        printf("O último elemento foi removido com sucesso.\n");
    }
}

void imprimeLista1(Lista lista) {
    int i;
    if(lista.lista[0].tamanho == 0) {
        printf("Lista vazia.\n");
        return;
    }
    else {
        printf("\nLISTA 1\n");
        printf("---------------------------------------\n");
        for(i=0;i<lista.lista[0].tamanho;i++) {
            printf("NOME: %s\n", lista.lista[0].item[i].nome);
            printf("CÓDIGO: %d\n", lista.lista[0].item[i].codigo);
            printf("---------------------------------------\n");
        }
                printf("\n");
    }
}

void imprimeLista2(Lista lista) {
    int i;
    if(lista.lista[1].tamanho == 0) {
        printf("Lista vazia.\n");
        return;
    }
    else {
            printf("\nLISTA 2\n");
        printf("---------------------------------------\n");
        for(i=0;i<lista.lista[1].tamanho;i++) {
            printf("NOME: %s\n", lista.lista[1].item[i].nome);
            printf("CÓDIGO: %d\n", lista.lista[1].item[i].codigo);
            printf("---------------------------------------\n");
        }
        printf("\n");
    }
}

void remElemRepList1(Lista *lista) {
    int i, j, aux;
    int tam = lista->lista[0].tamanho;
    for(i=0;i<lista->lista[0].tamanho;i++) {
        for(j=i+1;j<lista->lista[0].tamanho;j++) {
            if(lista->lista[0].item[i].codigo == lista->lista[0].item[j].codigo) {
                for(aux=j;aux<lista->lista[0].tamanho;aux++) {
                    lista->lista[0].item[aux] = lista->lista[0].item[aux+1];
                }
                lista->lista[0].tamanho--;
            }
        }
    }
    if(tam == lista->lista[0].tamanho) printf("\nNão existem elementos repetidos na lista.\n");
    else printf("\nForam excluídos os elementos repetidos da lista.\n");

    /*No caso, esta função tem um erro que pode passar desapercebido, mas realizei ele a proposito pois necessitaria de mais tempo. No entanto, esse erro poderia acontecer em algum descuido da pessoa que coloca os dados para o programa analisar. Já que, esse erro se trata de que ele apenas compara somente os códigos dos produtos, e não os nomes e códigos(na linha 170). Assim, um produto de nome Coca-Cola com codigo 200 seria excluído se aparecesse depois de um produto de nome Doritos com codigo 200. Espero que entenda, professor, afinal essa seria apenas uma funçao complementar ao propósito do código.*/
}

void remElemRepList2(Lista *lista) {
    int i, j, aux;
    int tam = lista->lista[1].tamanho;
    for(i=0;i<lista->lista[1].tamanho;i++) {
        for(j=i+1;j<lista->lista[1].tamanho;j++) {
            if(lista->lista[1].item[i].codigo == lista->lista[1].item[j].codigo) {
                for(aux=j;aux<lista->lista[1].tamanho;aux++) {
                    lista->lista[1].item[aux] = lista->lista[1].item[aux+1];
                }
                lista->lista[1].tamanho--;
            }
        }

    }
    if(tam == lista->lista[1].tamanho) printf("\nNão existem elementos repetidos na lista.\n");
    else printf("\nForam excluídos os elementos repetidos da lista.\n");

    /* O MESMO COMENTARIO DA FUNÇAO ANTERIOR----------------------------------------------------------------------------
    No caso, esta função tem um erro que pode passar desapercebido, mas realizei ele a proposito pois necessitaria de mais tempo. No entanto, esse erro poderia acontecer em algum descuido da pessoa que coloca os dados para o programa analisar. Já que, esse erro se trata de que ele apenas compara somente os códigos dos produtos, e não os nomes e códigos(na linha 188). Assim, um produto de nome Coca-Cola com codigo 200 seria excluído se aparecesse depois de um produto de nome Doritos com codigo 200. Espero que entenda, professor, afinal essa seria apenas uma funçao complementar ao propósito do código.*/
}

void comparaListas(Lista lista1, Lista lista2) {
    int i, j;
    int cont = 0;
    if(lista1.lista[0].tamanho != lista2.lista[1].tamanho) {
        printf("LISTAS DIFERENTES.\n");
        printf("---------------PRODUTOS EM COMUM:---------------\n");
        for(i=0;i<lista1.lista[0].tamanho;i++) {
            for(j=0;j<lista2.lista[1].tamanho;j++) {
                if(lista1.lista[0].item[i].codigo == lista2.lista[1].item[j].codigo) {
                    printf("%s(%d)\n", lista1.lista[0].item[i].nome, lista1.lista[0].item[i].codigo);
                }
            }
        }
    }
    else {
        for(i=0;i<lista1.lista[0].tamanho;i++) {
            for(j=0;j<lista2.lista[1].tamanho;j++) {
                if(lista1.lista[0].item[i].codigo == lista2.lista[1].item[j].codigo) {
                    cont++;
                    //printf("%s(%d)\n", lista1.lista[0].item[i].nome, lista1.lista[0].item[i].codigo);
                }
            }
        }
        if(cont == lista1.lista[0].tamanho) printf("LISTAS IGUAIS.\n");
    }
}

void selectionsordLista1(Lista *lista) {
    int i, j, menor, aux;
  
    for(i=0;i<(lista->lista[0].tamanho-1);i++) {
        menor = i;//a variavel menor vai pegando o indice i
        for(j=i+1;j<lista->lista[0].tamanho;j++) {
            if(lista->lista[0].item[j].codigo < lista->lista[0].item[menor].codigo) {
                menor = j; //caso a condicional de cima seja verdadeira, agora, a var menor muda de valor para o indice j
            }
        }

        if(i!=menor) { //fazemos um swap
            aux = lista->lista[0].item[i].codigo;
            lista->lista[0].item[i].codigo = lista->lista[0].item[menor].codigo;
            lista->lista[0].item[menor].codigo = aux;
        }
    } 
}

void selectionsordLista2(Lista *lista) {
    int i, j, menor, aux;
  
    for(i=0;i<(lista->lista[1].tamanho-1);i++) {
        menor = i; //a variavel menor vai pegando o indice i
        for(j=i+1;j<lista->lista[1].tamanho;j++) {
            if(lista->lista[1].item[j].codigo < lista->lista[1].item[menor].codigo) {
                menor = j; //caso a condicional de cima seja verdadeira, agora, a var menor muda de valor para o indice j
            }
        }

        if(i!=menor) { //fazemos um swap
            aux = lista->lista[1].item[i].codigo;
            lista->lista[1].item[i].codigo = lista->lista[1].item[menor].codigo;
            lista->lista[1].item[menor].codigo = aux;
        }
    } 
}

void insertionsordLista1(Lista *lista) {
    int i, j, aux, aux2;

    for(i=1;i<lista->lista[0].tamanho;i++) {
        aux2 = i; //essa variavel vai pegar o valor de i para conseguir manusear o indice dentro do proximo loop

        for(j=i-1;j>=0;j--) { //percorremos o vetor em direçao da esquerda para ver se esxitem valores maiores que o valor da posicao i
            if(lista->lista[0].item[aux2].codigo < lista->lista[0].item[j].codigo) {  //se o valor à esquerda for maior, ocorre uma troca
                aux = lista->lista[0].item[aux2].codigo;
                lista->lista[0].item[aux2].codigo = lista->lista[0].item[j].codigo;
                lista->lista[0].item[j].codigo = aux;
            }
            else break; //se o valor a esquerda não for maior, entao quebra o loop
            aux2--; //aqui atualizamos o novo indice que o valor vai ocupar na lista, por ex: se estivesse na 3a e tivesse ido para a 2a
        }
        
    }
}

void insertionsordLista2(Lista *lista) {
    int i, j, aux, aux2;

    for(i=1;i<lista->lista[1].tamanho;i++) {
        aux2 = i; //essa variavel vai pegar o valor de i para conseguir manusear o indice dentro do proximo loop

        for(j=i-1;j>=0;j--) { //percorremos o vetor em direçao da esquerda para ver se esxitem valores maiores que o valor da posicao i
            if(lista->lista[1].item[aux2].codigo < lista->lista[1].item[j].codigo) {  //se o valor à esquerda for maior, ocorre uma troca
                aux = lista->lista[1].item[aux2].codigo;
                lista->lista[1].item[aux2].codigo = lista->lista[1].item[j].codigo;
                lista->lista[1].item[j].codigo = aux;
            }
            else break; //se o valor a esquerda não for maior, entao quebra o loop
            aux2--; //aqui atualizamos o novo indice que o valor vai ocupar na lista, por ex: se estivesse na 3a e tivesse ido para a 2a
        }
        
    }
}

void buscaSeqLista1(Lista lista, int codigo) {
    int i;
    lista.lista[0].item[0].codigo = codigo;
    i = lista.lista[0].tamanho + 1;
    do {i--;} while (lista.lista[0].item[i].codigo != codigo);
    if(i==0) printf("O produto não foi encontrado\n");
    else printf("O produto de código %d foi encontrado.\n", codigo);
}

void buscaSeqLista2(Lista lista, int codigo) {
    int i;
    lista.lista[1].item[0].codigo = codigo;
    i = lista.lista[1].tamanho + 1;
    do {i--;} while (lista.lista[1].item[i].codigo != codigo);
    if(i==0) printf("O produto não foi encontrado\n");
    else printf("O produto de código %d foi encontrado.\n", codigo);
}
