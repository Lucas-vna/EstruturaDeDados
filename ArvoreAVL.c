#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//-------------Definindo Tipos de Dados----------------------
//NoAVL* PtrNoAvl
typedef struct NoAVL* PtrNoAVL;

typedef struct NoAVL{
    PtrNoAVL direita, esquerda;
    int chave;
    int altura;
}NoAVL;



//-------------Inicia árvore AVL-----------------------------
void iniciaArvoreAVL(PtrNoAVL *no){
    (*no) = NULL;
}

//-------------Verifica se esta Vazia------------------------
estaVaziaAroreAVL(PtrNoAVL *no){
    return((*no) == NULL);
}

//-------------Aplica Rotacoes-------------------------------
aplicaRotacoes(){
    //int atualizaAlturaAVL
    int atualizaAlturaAVL(PtrNoAVL *esquerda, PtrNoAVL *direita){
        int ae, ad, ret;

        ae = alturaArvoreAVL(&(*esquerda));
        ad = alturaArvoreAVL(&(*direita));

    }
    //void rotacao simples esquerda (+2)
    PtrNoAVL u;
    int aUdir, aUesq;
    if (fatorBalanceamento == -2)
    {
        u = (*no)->esquerda;
    }
    
    //void rotacao dupla esquerda 
    //void rotacao simples diretira
    //void rotacao dupla direita
    //void aplicar rotacao
}


//------------------------------------------
void PreOrdem(PtrNoAVL *no){
    
}

void PreOrdemPrincipal(){
    printf("Preo-ordem: ");
    PreOrdem(no);
    printf("\n");
}
//-------------Verifica a altura da Arvore-------------------
alturaArvoreAVL(){

}
//-------------Insere Valor na árvore AVL--------------------
bool insereArvoreAVL(PtrNoAVL *no, int valor){

    if ((*no) == NUL)
    {
        (*no) = malloc(sizeof(NoAVL));
        (*no)->esquerda = NULL;
        (*no)->direita = NULL;
        (*no)->chave = valor;
        (*no)->altura = 1;
    }
    
    //valor duplicado
    if((*no)->chave == valor) return false;

    //clausulas recursivas
    // valor > no->chave: chamada recursiva direita
    // valor < no->chave: chamada recursiva esquerda
    bool ret;
    if (valor > (*no)->chave)
    {
        ret = insereArvoreAVL(&(*no)->direita, valor);
    }else{
        ret = insereArvoreAVL(&(*no)->esquerda, valor);
    }

    //PODE ter desbalanceamento
    if(!ret) return false; //nao inseriu elemento, nao desbalanceou

    int AlturaEsquerda, AlturaDireita;
    AlturaEsquerda = alturaArvoreAVL(&(*no)->direita);
    AlturaDireita = alturaArvoreAVL(&(*no)->esquerda);
    fatorBalanceamento = AlturaDireita - AlturaEsquerda;

    if (fatorBalanceamento == 2 | fatorBalanceamento == -2)
    {
        aplicaRotacoes(&(*no));
    }
    

}

//------------------------------------------



int main(int argc, char const *argv[]){
    
    PtrNoAVL raiz;

    return 0;
}



