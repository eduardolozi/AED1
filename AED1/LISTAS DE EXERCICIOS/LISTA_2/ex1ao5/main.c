#include<stdio.h>
#include<stdlib.h>
#include"lista.h"

int main() {
    Lista l1, l2, l3;
    int x, controle;
    char resp, resp2;
    float media;

    printf("---------CRIAÇÃO DA PRIMEIRA LISTA---------\n");
    criaLista(&l1);
    while(resp != 'N' && resp != 'n') {
        printf("Insira um elemento: ");
        scanf("%d", &x);
        insereElemento(&l1, x);
        printf("Você deseja visualizar a lista? SIM(1) NÃO(0).\n");
        scanf("%d", &controle);
        if(controle==1) {
            printLista(&l1);
        }
        printf("Você deseja continuar inserindo elementos na lista? Digite S ou N.\n");
        scanf("%*c%c", &resp);
    }
    
    system("clear || cls");

    printf("Sua lista está assim: \n");
    printLista(&l1);
    printf("\n---------RETIRANDO ELEMENTOS DA LISTA ---------\n");
    printf("Digite um número(n), retiraremos os primeiros n elementos da lista: ");
    scanf("%d", &x);
    controle=retiraElementos(&l1, x);
    if(controle==1) {
        printf("Retirado com sucesso.\n");
        printLista(&l1);
    } 
    else if(controle == 0) {
        printf("Não foi possível retirar elementos da lista.\n");
        printLista(&l1);
    }

    printf("\n---------BUSCANDO MAIOR ELEMENTO DA LISTA ---------\n");
    controle=buscaMaior(&l1);
    if(controle==1) {
        printf("Foi possível encontrar o maior número da lista.\n");
        printf("O maior elemento é %d e ele está na %da. posição.\n", l1.maior, l1.posicaoMaior);
    }
    if(controle==0) printf("Não foi possível encontrar o maior elemento.\n");

    printf("\n---------NUMERO DE PARES NA LISTA---------\n");
    controle = totParesLista(&l1);
    printf("O número de pares na lista é de: %d\n", controle);

    printf("\n---------MEDIA DOS ELEMENTOS PRESENTES NA LISTA---------\n");
    media = mediaLista(&l1);
    printf("A média dos elementos dessa lista é de: %.2f\n", media);

    printf("Você deseja limpar a tela antes de prosseguir? Digite S ou N.\n");
    scanf("%*c%c", &resp);
    if(resp == 'S' || resp == 's') system("clear || cls");

    printf("---------CRIAÇÃO DA SEGUNDA LISTA---------\n");

    criaLista(&l2);
    while(resp2 != 'N' && resp2 != 'n') {
        printf("Insira um elemento: ");
        scanf("%d", &x);
        insereElemento(&l2, x);
        printf("Você deseja visualizar a lista? SIM(1) NÃO(0).\n");
        scanf("%d", &controle);
        if(controle==1) {
            printLista(&l2);
        }
        printf("Você deseja continuar inserindo elementos na lista? Digite S ou N.\n");
        scanf("%*c%c", &resp2);
    }
    

    system("clear || cls");
    printf("%d\n", l2.ultimo);

    printf("Sua lista está assim: \n");
    printLista(&l2);
    printf("\n---------RETIRANDO ELEMENTOS DA LISTA ---------\n");
    printf("Digite um número(n), retiraremos os primeiros n elementos da lista: ");
    scanf("%d", &x);
    controle=retiraElementos(&l2, x);
    if(controle==1) {
        printf("Retirado com sucesso.\n");
        printLista(&l2);
    } 
    else if(controle == 0) {
        printf("Não foi possível retirar elementos da lista.\n");
        printLista(&l2);
    }

    printf("\n---------BUSCANDO MAIOR ELEMENTO DA LISTA ---------\n");
    controle=buscaMaior(&l2);
    if(controle==1) {
        printf("Foi possível encontrar o maior número da lista.\n");
        printf("O maior elemento é %d e ele está na %da. posição.\n", l2.maior, l2.posicaoMaior);
    }
    if(controle==0) printf("Não foi possível encontrar o maior elemento.\n");

    printf("\n---------NUMERO DE PARES NA LISTA---------\n");
    controle = totParesLista(&l2);
    printf("O número de pares na lista é de: %d\n", controle);

    printf("\n---------MEDIA DOS ELEMENTOS PRESENTES NA LISTA---------\n");
    media = mediaLista(&l2);
    printf("A média dos elementos dessa lista é de: %.2f\n", media);

    printf("Você deseja limpar a tela antes de prosseguir? Digite S ou N.\n");
    scanf("%*c%c", &resp);
    if(resp == 'S' || resp == 's') system("clear || cls");

    
    printf("\n---------LISTAS CONCATENADAS---------\n");
    l3=concatenaListas(&l1, &l2);
    printLista(&l3);

    return 0;
}