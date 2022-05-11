//HASH -> vetor de itens de hash
#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 10

//---------------
// TAD
// 1. Item de Hash (Heroi)
// chave, nome, poder
typedef struct {
  int chave;
  char nome[20];
  char poder[50];
} ItemHash;

// 2. Tabela Hash com Endereçamento Direto
// vetor M, onde cada posicao é um heroi
typedef struct {
  ItemHash* vetor[TAMANHO];
  int contador;
} TabelaHashEndDireto;

//---------------

// inicializada
void iniciaTabelaHashEndDireto(TabelaHashEndDireto *tabela) {
  // percorrer o vetor, atribuir NULL
  // contador = 0
  for(int i = 0; i < TAMANHO; i++) {
    tabela->vetor[i] = NULL;
  }
  tabela->contador = 0;
}

//---------------
// Impressao
//---------------
void imprimirItemHash(ItemHash *item) {
  if(item == NULL) {
    printf(" ~~ NULL |\n");
  } else {
    printf(" %s | %s |\n", item->nome, item->poder);
  }
}

void imprimirTabelaHashEndDireto(TabelaHashEndDireto *tabela) {
  printf("-----------\n");
  printf("    Hash   \n");
  printf("-----------\n");
  for(int i=0; i < TAMANHO; i++) {
    printf(" %d |", i);
    imprimirItemHash(tabela->vetor[i]);
  }
  printf("-----------\n");
}

//---------------
//---------------

// destruir
void destruirTabelaHashEndDireto(TabelaHashEndDireto *tabela) {
  iniciaTabelaHashEndDireto(tabela);
}

// inserir
void inserirTabelaHashEndDireto(TabelaHashEndDireto *tabela, ItemHash *item){
  if(item == NULL || item->chave >= TAMANHO || item->chave < 0) {
    printf("Warning: item vazio ou chave inválida!\n");
    return;
  }

  if(tabela->vetor[item->chave] == NULL) {
    //  vetor[x.chave] = x
    tabela->vetor [item->chave] = item;
    tabela->contador++;
  } else {
    printf("Warning: posição já ocupada!\n");
  }
}

// consultar
ItemHash* consultarTabelaHashEndDireto(TabelaHashEndDireto *tabela, int chave) {
  // >= tamanho e < 0
  if(chave >= TAMANHO || chave < 0 || tabela->vetor[chave] == NULL) {
    return NULL;
  }
  return(tabela->vetor[chave]);
}

// remocao
void removerTabelaHashEndDireto(TabelaHashEndDireto *tabela, int chave) {
  // >= tamanho e < 0
  if(chave >= TAMANHO || chave < 0) {
    printf("Warning: chave inválida!\n");
    return;
  }
  if(tabela->vetor[chave] != NULL) {
    tabela->vetor[chave] = NULL;
    tabela->contador--;
  }
}

// TODO: HOMEWORK
// tamanho (elementos)
// vazia ou nao
// cheia ou nao

//---------------
//---------------

int main(int argc, char *argv[]) {
  
  TabelaHashEndDireto table;
  iniciaTabelaHashEndDireto(&table);

  printf("======\n");
  ItemHash h1 = {0,"gabriel", "trancar chave dentro do carro"};
  inserirTabelaHashEndDireto(&table, &h1);
    
  ItemHash h2 = {8,"matheus", "estudar e não aprender nada"};
  inserirTabelaHashEndDireto(&table, &h2);
    
  ItemHash h3 = {5,"mantova", "sono infinito"};
  inserirTabelaHashEndDireto(&table, &h3);
  imprimirTabelaHashEndDireto(&table);

  removerTabelaHashEndDireto(&table, 50);
  removerTabelaHashEndDireto(&table, -50);
  ItemHash *retorno = consultarTabelaHashEndDireto(&table, 5);
  removerTabelaHashEndDireto(&table, 5);
  imprimirTabelaHashEndDireto(&table);
  imprimirItemHash(retorno);
  destruirTabelaHashEndDireto(&table);
  imprimirTabelaHashEndDireto(&table);

  return 0;
}
