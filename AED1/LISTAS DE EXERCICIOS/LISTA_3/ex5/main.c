#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

int main() {
    Lista lista1, lista2;
    int controle;

    init(&lista1, &lista2);
    
    insereElemento(&lista1, 1);
    insereElemento(&lista1, 2);
    insereElemento(&lista1, 9);
    insereElemento(&lista1, 8);
    insereElemento(&lista1, 1);
    insereElemento(&lista1, 8);
    insereElemento(&lista1, 8);
    insereElemento(&lista1, 3);
    insereElemento(&lista1, 2);

    imprimeLista1(lista1);
    printf("\n");

    //Na busca sequencial, não é obrigatorio organizar o vetor antes de realizar as buscas. Por isso, nesse programa, poderiamos fazer de dois jeitos essa etapa da Busca Sequencial. 
    // 1 - Ordenando a lista 1 antes de fazer as buscas
    // 2 - Buscar na lista sem fazer a ordenação antes
    // Nesse caso, recebemos dois resultados diferentes, já que a Lista 2, contém os índices em que os números buscados foram encontrados na Lista 1. 
    // Se a gente usar o método 1, teremos uma saída igual à da Busca Binária, uma vez que ela necessita de uma lista obrigatoriamente organizada para realizar a busca com sucesso.
    //Portanto, vou deixar comentada a opção de realizar a ordenaçao da Lista 1 antes da Busca Sequencial:
    // insertionSordLista1(&lista1);

    // controle = buscaSeq(lista1, 1, &lista2);
    // if(controle == -1) printf("ERRO: Lista Vazia.\n\n");
    // else if(controle == 0) printf("Elemento não encontrado na lista.\n\n");
    // else printf("O elemento foi encontrado %d vezes na lista.\n\n", controle);
    
    // controle = buscaSeq(lista1, 0, &lista2);
    // if(controle == -1) printf("ERRO: Lista Vazia.\n\n");
    // else if(controle == 0) printf("Elemento não encontrado na lista.\n\n");
    // else printf("O elemento foi encontrado %d vezes na lista.\n\n", controle);
    
    // controle = buscaSeq(lista1, 3, &lista2);
    // if(controle == -1) printf("ERRO: Lista Vazia.\n\n");
    // else if(controle == 0) printf("Elemento não encontrado na lista.\n\n");
    // else printf("O elemento foi encontrado %d vezes na lista.\n\n", controle);
    
    // controle = buscaSeq(lista1, 12, &lista2);
    // if(controle == -1) printf("ERRO: Lista Vazia.\n\n");
    // else if(controle == 0) printf("Elemento não encontrado na lista.\n\n");
    // else printf("O elemento foi encontrado %d vezes na lista.\n\n", controle); 

    // //Antes de fazer a busca binaria, é necessário ordenar a Lista 1
    insertionSordLista1(&lista1);
    printf("REALIZANDO A ORGANIZAÇÃO DA LISTA 1:");
    imprimeLista1(lista1);
    printf("\n");

    controle = buscaBin(lista1, 1, &lista2);
    if(controle == -1) printf("ERRO: Lista Vazia.\n\n");
    else if(controle == 0) printf("Elemento não encontrado na lista.\n\n");
    else printf("O elemento foi encontrado %d vezes na lista.\n\n", controle);
    
    controle = buscaBin(lista1, 0, &lista2);
    if(controle == -1) printf("ERRO: Lista Vazia.\n\n");
    else if(controle == 0) printf("Elemento não encontrado na lista.\n\n");
    else printf("O elemento foi encontrado %d vezes na lista.\n\n", controle);
    
    controle = buscaBin(lista1, 3, &lista2);
    if(controle == -1) printf("ERRO: Lista Vazia.\n\n");
    else if(controle == 0) printf("Elemento não encontrado na lista.\n\n");
    else printf("O elemento foi encontrado %d vezes na lista.\n\n", controle);
    
    controle = buscaBin(lista1, 12, &lista2);
    if(controle == -1) printf("ERRO: Lista Vazia.\n\n");
    else if(controle == 0) printf("Elemento não encontrado na lista.\n\n");
    else printf("O elemento foi encontrado %d vezes na lista.\n\n", controle);

    insertionSordLista2(&lista2);
    imprimeLista2(lista2);

    return 0;
}