//HASH -> vetor de itens de hash
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define TAMANHO 10;

//--------------------Especificacoes----------------------------------

typedef struct {

    int chave;
    char nome [20];
    char poder [20];

}itemHash;

typedef struct{
    
    itemHash* vetor[TAMANHO];
    int contador;

}TabelaHashEndDireto;


//--------------------------------------------------------------------



//--------------------Inicializacao-----------------------------------

void iniciaHash(TabelaHashEndDireto *tabela){

    //percorre o vetor e distribui NULL
    for (int i = 0; i < TAMANHO; i++)
    {
        tabela->vetor[i] = NULL;
    }
    else
    {
        tabela->contador = 0;
    }
    

}

//--------------------------------------------------------------------



//--------------------Impressao---------------------------------------

void ImprimeItemHash(itemHash *item){

    if (item == NULL)
    {
        printf("^^ NULL | \n");
    }
    else
    {
        printf(" %s | %d");
    }
    

}

void ImprimeTabelaHashEndDireto(TabelaHashEndDireto *tabela){

    printf("===================\n");
    printf("        HASH       \n");
    printf("===================\n");

    for (int i = 0; i < TAMANHO; i++)
    {
        printf(" %d |", i);
        ImprimeTabelaHashEndDireto(tabela->vetor[i]);
    }
    

}

//--------------------------------------------------------------------



//--------------------Remocao-----------------------------------------

void RemoverTabelaHashEndDireto(TabelaHashEndDireto *tabela, int chave){

    if (chave >= TAMANHO || chave < 0)
    {
        printf("WARNING!");
        return;
    }//if 1
    
    if (tabela->vetor[chave] != NULL)
    {
        tabela->vetor[chave] = NULL;
        tabela->contador--;
    }//if 2
    

    tabela->vetor[chave] = NULL;

}

//--------------------------------------------------------------------



//--------------------Inserir-----------------------------------------

void InsereTabelaHashEndDireto(TabelaHashEndDireto *tabela, itemHash *item){

    if (tabelas->vetor[item->chave] == NULL)
    {
        tabela->vetor[item->chave] = item;
        tabela->contador++;
    }
    else
    {
        printf("WARNING!");
    }

}

//--------------------------------------------------------------------



//--------------------Consulta----------------------------------------

itemHash* ConsultarTabelaHashEndDireto(TabelaHashEndDireto *tabela, ){



}

//--------------------------------------------------------------------



//--------------------Destroi-----------------------------------------

void DestroiTabelaHashEndDireto (){

    iniciaHash(DestroiTabelaHashEndDireto);

 /*   itemHash *desaloca;

    for (int i = 0; i < TAMANHO; i++)
    {
        if (tabela->vetor[i] != NULL)
        {
            desaloca = tabelas->vetor
        }
        
    }*/
    

}

//--------------------------------------------------------------------



//--------------------------------------------------------------------

int main(int argc, char const *argv[]){
    
    TabelaHashEndDireto table;

        iniciaHash(&table);
        ImprimeTabelaHashEndDireto(&table);

        itemHash h1 = {0, "Lucas, aprender a matéria durante a prova"}
        InsereTabelaHashEndDireto(&table, &h1);
        ImprimeItemHash(&table);

        itemHash(retorno);

    return 0;
}
 
