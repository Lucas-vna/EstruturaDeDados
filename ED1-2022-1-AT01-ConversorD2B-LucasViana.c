/**
* @file ED1-2022-1-AT01-ConversorD2B-LucasViana.c
* @author Lucas dos Reis Viana
* @date 23 Mar 2022
* @brief
* Enunciado completo:
* CONVERSOS DE DECIMAL PARA BINARIO USANDO PILHA ESTATICA
**/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#define TAMANHO 20

typedef struct{
  int vetor[TAMANHO];
  int topo;
}PilhaEstatica;

//------------Inicializando Pilha-----------------------------------------------
void IniciaPilha(PilhaEstatica *pilha){
  pilha->topo = -1;
}

//------------Verificando se a pilha esta vazia---------------------------------
bool EstaVazia(PilhaEstatica *pilha){
  return(pilha->topo == -1);
}

//------------Verificando se a pilha esta cheia---------------------------------
bool EstaCheia(PilhaEstatica *pilha){
  return(pilha->topo == (TAMANHO-1));
}

//------------Verificando o tamanho da Pilha------------------------------------
int TamanhoPilha(PilhaEstatica *pilha){
  return(pilha->topo+1);
}

//------------Adicionando valores na pilha--------------------------------------
void AdicionaPilha(PilhaEstatica *pilha, int x){
  if (EstaCheia(pilha)) {
    printf("Pilha esta cheia!\n");
  }else{
    pilha->topo++;
    pilha->vetor[pilha->topo] = x;
  }//else
}

//------------Retirando valores da pilha----------------------------------------
int RetiraPilha(PilhaEstatica *pilha){
  int aux;
    if (EstaVazia(pilha) == 1) {
      printf("Pilha ja esta vazia!\n");
    }else{
      aux = pilha->vetor[pilha->topo];
      pilha->topo--;
      return aux;
    }//else
}

//-----------Imprime Pilha------------------------------------------------------
void ImprimePilha(PilhaEstatica *pilha){
  printf("Pilha - [");
  for (int i = 0; i <= pilha->topo; i++) {
    printf("|%d|", pilha->vetor[i]);
  }//for
  printf("]\n");
}

//-----------Converter Decimal 2 Binario----------------------------------------
void D2BPilhaEstatica(FILE *ArqSaida, int y){
  int resto;
  PilhaEstatica PilhaAux;

  //inicia pilha auxiliar
  IniciaPilha(&PilhaAux);

  //empilhar caso valor = 0
  if (y == 0) {
    AdicionaPilha(&PilhaAux, 0);
  }//if

  //obter o resto (%2), dividir por 2 e adicionar valores a pilha
  while (y > 0) {
    resto = y % 2;
    AdicionaPilha(&PilhaAux, resto);
    y = y / 2;
  }

  while (!EstaVazia(&PilhaAux)) {
    fprintf(ArqSaida, "%d", RetiraPilha(&PilhaAux));
  }//while
  fprintf(ArqSaida, "\n");
}

//-----------MAIN---------------------------------------------------------------
int main(int argc,char const *argv[]) {


  printf("======= Conversao de Decimal para Binario =======\n");

  printf("Quantidade de parametros: %d \n", argc);

  if (argc != 3) {
    printf("\nWARNING: Parametros invalidos!\n");
    return 0;
  }//if

  for (int i = 0; i < argc; i++) {
    printf("argv[%d] = %s\n", i, argv[i]);
  }//for

  PilhaEstatica SegundaPilhaEstatica;
  IniciaPilha(&SegundaPilhaEstatica);

  FILE *entrada = fopen("entrada01.txt", "r");
  FILE *saida   = fopen("saida01.txt", "w");

  //Verificar se o arquivo de entrada é válido
  if(entrada == NULL) {
    printf("O arquivo de ENTRADA não pode ser aberto!\n");
    system ("pause");
    exit(1);
  }else{
    printf("O arquivo foi aberto com sucesso!\n");
  }

  //Verificar o arquivo de saida (valido)
  if(saida == NULL) {
    printf("O arquivo de SAiDA não pode ser criado !\n");
    system ("pause");
    exit(1);
  }else{
    printf("O arquivo foi criado com sucesso!\n");
  }//else

  int valor;
  //obtendo os valores do arquivo
  while(true){
  //pegando os numeros do arquivo
    fscanf(entrada, "%d", &valor);
    //verificando o final do arquivo
    /*if(feof(entrada)){
      break;
    }*/

    //condiçao para empilhar o numero
    if(valor >= 0){
      AdicionaPilha(&SegundaPilhaEstatica, valor);
      printf("%d \n", valor);

    }else{
      printf("\n");
      for(int z = 0; z < 80; z++){
      printf("#");
    }//for
      printf("\n");
      printf("Erro: O valor do numero do arquivo nao e inteiro positivo!\n");
      return 0;
    }//else
    if(feof(entrada)){
      break;
    }//if

  }//while

  //passando os valores da pilha estatica para a conversão
     while (!EstaVazia(&SegundaPilhaEstatica)) {
       int aux;
       aux = RetiraPilha(&SegundaPilhaEstatica);
       D2BPilhaEstatica(saida, aux);
     }//while

  fclose(entrada);
  fclose(saida);

  system ("pause");
  return 0;
}



//PiLHA
//1.iniciar pilha
//2.verificar se está vazia/cheia
//3.imprime a pilha
//4.verificar o tamanho da pilha
//5.adicioonar valores na pilha


//system("pause");
//system("cls");
