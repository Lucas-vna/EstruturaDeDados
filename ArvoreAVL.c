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



//-------------Rotacoes Simples Direita na árvore AVL--------------------

void rotacaoSimplesDireita(PtrNoAVL *no){

    PtrNoAVL u = (*no) -> esquerda;
    (*no)->esquerda = u->direita;
    u->direita = (*no);

    //atualizar a altura dos nós modificados (node, u)
    (*no)->altura = atualizaAlturaAVL((*no)->esquerda, (*no)->direita);
    u->altura = atualizaAlturaAVL(u->esquerda, u->direita);

    //autualizacao da referencia do node
    (*no) = u;

}//rotacaoSimplesDireita


void rotacaoSimplesEsquerda(PtrNoAVL *no){

    PtrNoAVL u = (*no)->direita;
    (*no)->direita = u->esquerda;
    u->esquerda = (*no);

    (*no)->altura = atualizaAlturaAVL((*no)->esquerda, (*no)->direita);
    u->altura = atualizaAlturaAVL(u->esquerda, u->direita);

    (*no) = u;

}//rotacaoSimplesEsquerda




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



//-------------ordem da Arvore-------------------

void emOrdem(PtrNoAVL *no){

    if ((*no) == NULL) return;
    {
        emOrdem(&(*no) -> esquerda);
        printf("%d", (*no) -> chave);
        emOrdem(&(*no) -> direita);
    }//if
    

}//emOrdem

void preOrdem(PtrNoAVL *no){

    if ((*no) == NULL) return;
    {
        printf("%d ", (*no) -> chave);
        preOrdem(&(*no) -> esquerda);
        preOrdem(&(*no) -> direita);  
    }//if
    

}//preOrdem

void PreOrdemPrincipal(){
    printf("Preo-ordem: ");
    PreOrdem(no);
    printf("\n");
}



//-------------Verifica a altura da Arvore-------------------

alturaArvoreAVL(PtrNoAVL *no){

    if (no == NULL)
    {
        return(0);
    }//if
    else
    {
        return((no) -> altura);
    }//else
    
}//alturaArvoreAVL



//-------------Atualiza a altura da Arvore-------------------

int atualizaAlturaAVL(PtrNoAVL esquerda, PtrNoAVL direita){

    int AlturaEsquerda = alturaArvoreAVL(esquerda);
    int AlturaDireita = alturaArvoreAVL(direita);

    if (AlturaEsquerda > AlturaDireita)
    {
        return (Altura Esquerda + 1);
    }//if
    else
    {
        return (AlturaDireita + 1);
    }//else

}//atualizaArvoreAVL



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

        insereArvoreAVL(raiz, 12);

        insereArvoreAVL(raiz, 33);

        insereArvoreAVL(raiz, 32);

        insereArvoreAVL(raiz, 2);

        insereArvoreAVL(raiz, 17);

        insereArvoreAVL(raiz, -1);

        insereArvoreAVL(raiz, -40);

        insereArvoreAVL(raiz, 26);

        insereArvoreAVL(raiz, 38);

        insereArvoreAVL(raiz, 15);

    return 0;
}
