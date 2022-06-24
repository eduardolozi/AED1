#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define nTimes 8
#define N_MAX 128

typedef struct TipoItem {
    char *nome;
    int gf, gs; //gols feitos e gols sofridos
    int pts; //pontos
    int* id; //cada time irá ter um numero de identificação
    
} TipoItem;

typedef struct identidade {
    unsigned short int idT; //essa variável irá servir para armazenar a id do time, que antes ficava em um vetor
} identidade;

typedef struct No {
    TipoItem time; //usando uma estrutura de dados feita por apontadores para colocar os times
    struct No *prox;
    TipoItem timeVet[nTimes]; //usando uma estrutura de dados vetorial para colocar os times
} No;

typedef struct Lista {
    identidade idTimes[nTimes]; //vetor que terá a id dos times, será útil na aplicação da Busca Binária
    No listaVet; //lista que armazena o vetor de times da struct anterior
    No *inicio;
    No *fim;
    int tam, rodada;
    int jfeitos[nTimes*(nTimes-1)];
    int contj;
} Lista;    


//FUNÇÕES DE ALOCAÇÃO E DESALOCAÇÃO DE MEMÓRIA:
void init(Lista *lista);
void libera(Lista *lista);


//FUNÇÕES DE IMPRESSÃO DE TABELAS:
void imprimeTabela(Lista lista); //imprime uma tabela de classificação, do campeão ao lanterna
void imprimeTabelaGF(Lista lista); //imprime uma tabela de ordem decresente dos times em relação aos Gols Feitos
void imprimeTabelaGS(Lista lista); //imprime uma tabela de ordem decresente dos times em relação aos Gols Sofridos


//FUNÇÕES QUE CRIAM A LÓGICA DO CAMPEONATO:
int insereTime(Lista *lista, char *nomeTime);
int conferenome (Lista *lista, char *teste);
//as que tem a sinalizaçao antes eu nao usei.
/* - > */ void vitoria (Lista *lista, int time); //adiciona 3 pontos ao time
/* - > */ void empate (Lista *lista, int time); //adiciona ponto 1 ao time
/* - > */ void atgols (Lista *lista, int time, int gf, int gs); //atualiza valores de gols do time
/* - > */ int conferejogo (Lista *lista, int a, int b); // ve se os times ja nao se enfrentaram
void atpartida (Lista *lista, int id1, int gid1, int id2, int gid2); //recebe uma partida e atualiza as structs dos respectivos times
void atrodada (Lista *lista); // coleta os placares da rodada e envia para a funcao de atualizar partida
void stringing_to_int(int *id, char * string ); // string to int -> Usamos para criar uma identidade para o time
int somaId(int *id, int lenVet);// vai fazer que a id, antes em um vetor, agora vire um número.
void tabela (Lista *lista); //vai atualizar a tabela de acordo com os resultados da rodada


//FUNÇÕES DE BUSCA:
//nas funçoes de busca usaremos o vetor de times(a estrutura de dados feita atraves de vetor), pois a implementação é mais simples de ser executada em relaçao ao TAD feito em apontadores.
void buscaSeqTime(Lista lista, char *nomeTime); //vai buscar o nome do time e mostrar seu histórico de GF, GS e Pts
void buscaBinTime(Lista lista, char *nomeTime); //vai buscar o nome do time e mostrar seu histórico de GF, GS e Pts


//FUNÇÕES DE ORDENAÇÃO:
void quickSortGF(Lista *lista, int esq, int dir); //vai ordenar os times em relação aos Gols Feitos
void insertionSortGS(Lista *lista, int tam); //vai ordenar os times em relação aos Gols Sofrifos
