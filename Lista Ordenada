#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#define TAMANHO 

//-------------------------------------------------------------|
typedef struct NoLista* PtrNoLista;

//--------------No de Lista------------------------------------|
typedef struct NoLista{
    int elemento;
    PtrNoLista proximo;
}NoLista;

//--------------Lista------------------------------------------|
typedef struct{
    PtrNoLista inicio;
    int qtde;
}ListaOrdenada;

//--------------Inicia Lista-----------------------------------|
void IniciaListaOrdenada(ListaOrdenada *l){
    l->inicio = NULL;
    l->qtde = 0;
}

//--------------Esta vazia-------------------------------------|
bool EstaVaziaListaOrdenada(ListaOrdenada *l){
    return(l->inicio == NULL);
}

//--------------Esta Cheia-------------------------------------|


//--------------Tamanho----------------------------------------|
bool TamanhoListaOrdenada(ListaOrdenada *l){
    return(l->qtde);
}

//--------------Maximo(ultimo)---------------------------------|


//--------------Minimo(primeiro)-------------------------------|
int PrimeiroElementoListOrdenada(ListaOrdenada *l){

}

//--------------Proximo----------------------------------------|


//--------------Anterior---------------------------------------|


//--------------Destuir Lista----------------------------------|
void DestroiListOrdenada(ListaOrdenada *l){
    PtrNoLista aux;
    while (TamanhoLista(l) != 0){
        aux = l->inicio;
        printf("Removendo: %d \n", aux->elemento);

        l->inicio = l->inicio->proximo;
        
        free(aux);

        l->qtde--;
    }
    
}

//--------------Inserir elemento-------------------------------|
void InsereElemento(ListaOrdenada *l, int x){
    //criar ponteiro para um NOVO no
    PtrNoLista novo;
    
    //alocar memorio do NOVO no
    novo = malloc(sizeof(NoLista));
   
    //copiar o valor X para o NOVO no
    novo->elemento = x;
   
    //situacoes
        //A: 1a insercao
        //B: elemento < primeiro elemento da lista
        //C: elemento
    //se situacao = A/B
    if (EstaVaziaListaOrdenada(1) || novo->elemento < l->inicio){
        //proximo do NOVO aponto para o inicio da lista
        novo->proximo = l->inicio;

        //inicio aponta para NOVO no
        l->inicio = novo;
    }else{
        //se nao = C
        //percorrer lista e encontrar posicao de insercao
        PtrNoLista aux = l->inicio;
        
        //while para qnd proximo do aux == NULL ou prox do aux (valor >elemento)
        while (aux->proximo != NULL && aux->proximo->elemento <= x){
            aux = aux->proximo;
        }//while

        //AUX: uma posicao antes do NOVO elemento
        //1. proximo do NOVO aponta para o proximo aux
        novo->proximo = aux->proximo;
        
        //2. ux aponta para o NOVO no
        aux->proximo = novo;
    }//else

    //qtde++
    l->qtde++;
}//void

//--------------Remover elemento-------------------------------|
bool RemoveElemento(ListaOrdenada *l, int valor){
    PtrNoLista aux;
    
    //A - lista vazia
    //B - Valor < que o primeiro elemento da lista
    if (EstaVaziaListaOrdenada(l) || valor < l->inicio->elemento){
        return false;
    }

    //C - valor = primeiro elemento da lista
    if (valor == l->inicio->elemento){
        //cria um aux
        aux = l->inicio;
       
        //inicio recebe proximo do inicio
        l->inicio = l->inicio->proximo;

        //libera memoria do aux
        free(aux);

        //qtde decrementada
        l->qtde--;

        //retorna verdade
        return(true);
    }

    //D - percorrer a lista
    aux = l->inicio;
    while (aux->proximo != NULL && aux->proximo->elemento < valor){
        aux = aux->proximo;
    }
    
    //proximo aux (contem na teoria) a posicao onde valo deveria existir
    //aux-<proximo == NULL (falso)
    //aux->proximo->elemento != valor (falso)
    //D1 - não achou o numero
    if (aux->proximo == NULL || aux->proximo->elemento != valor){
        return false;
    }

    //aux->proximo->elemento == valor
    //D2 achou o numero
        //criar outra variavel de ptr
        PtrNoLista remove;
        
        //ptr apontar para o proximo do aux
        remove = aux->proximo;
        
        //proxiom do aux recebe o proximo do proximo do aux
        aux->proximo = aux->proximo->proximo;
        
        //desloca memoria do ptr
        free(remove);
        
        //qtde--
        l->qtde--;

        //retorna verdadeiro
        return true;
}

//--------------Pesquisar elemento-----------------------------|
bool PesquisaElemento(ListaOrdenada *l, int valor, int *contador){
    //percorrer a lista e encontrar ou não o elemento
    PtrNoLista aux;

    for (aux = l->inicio; aux != NULL; aux = aux->proximo){
        if (aux->elemento == valor){
            return true;
        }
        
        if (aux->elemento > valor){
            return false;
        }   
    }
    return false;
}

//--------------Imprime Lista----------------------------------|
void ImprimiLista(ListaOrdenada *l){
    printf("Lista = [");
    PtrNoLista temp;
    for (temp = l->inicio; temp!= NULL; temp = temp->proximo){
        printf("%d", temp->elemento);
    }
    printf(" ]\n");
}

//--------------MAIN-------------------------------------------|
int main(int argc, char const *argv[]){

    ListaOrdenada lista;

        IniciaListaOrdenada(&lista);
        
        if (EstaVaziaListaOrdenada(&lista)){
            printf("Salve, ta vazia sim!");
        }
        
        printf("Tamanho = %d\n", TamanhoListaOrdenada(&lista));

        int cont1 = 0;
        int busca[] = {};

        for (int i = 0; i < 5; i++){
            cont1 = 0;
            if(PesquisaElemento(&lista, 0, &cont1)){
                printf("Valor foi encontrado");
            }else{
                printf("Valor nao foi encontrado");
            }
        }
        

        
printf("\n\n\\n\n\n\n\n\n");
return 0;
}
