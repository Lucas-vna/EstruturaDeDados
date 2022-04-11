#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



//-----------------Definir Tipo Abstrato---------------------------
typedef struct NoArvore* PtrNoArvore;

typedef struct NoArvore{
    int chave;
    PtrNoArvore direita;
    PtrNoArvore esquerda;
}NoArvore;

//-----------------Inicia Arvore Binaria---------------------------
void IniciaArvoreBi(PtrNoArvore no*){
    //*no = NULL
    (*no) = NULL;
}

//-----------------Esta Vazia--------------------------------------
bool EstaVaziaArvoreBi(PtrNoArvore *no){
    return ((*no) == NULL);
}

//-----------------Esta Cheia--------------------------------------


//-----------------Adiciona Elemento-------------------------------
bool AdicionaElementoArvoreBi(PtrNoArvore *no, int valor){
    
    //se (*no) == NULL
    if ((*no) == NULL){
        
        //(*no) = malloc(sizeof(NoArvore))
        (*no) = malloc(sizeof(NoArvore));
        
        //atualizar direita/esquerda
        (*no)->direita = NULL;
        (*no)->esquerda = NULL;
        
        //(*no) = elemento = x;
        (*no)->chave = valor;

        //return true
        return (true);
    }

    //se (*no)->elemento.chave == x.chave
    if ((*no)->chave == valor){
        
        //return (false);
        return (false);
    }

    //se (*no)->elemento.chave->x.chave
    if (valor > (*no)->chave){
        //valor > no->chave -> ir pra subarvore direita
        return(AdicionaElemento(&(*no)->direita, valor));

    }else{
        //valor < no->chave -> ir pra subarvore esquerda
        return(AdicionaElemento(&(*no)->esquerda), valor);
    }   
}//funcao

//-----------------Função Auxiliar--------------------------------
//funcao auxiliar (procura maximo na subarvore esquerda)
PtrNoArvore ProcuraMaiorElemento(PtrNoArvore *no){ 
        
        //no -> no.esquerda            
        while ((*no)->direita != NULL){
            (*no) = (*no)->direita;
        }//while

        PtrNoArvore ret = (*no);
        (*no) = ret->esquerda;
        return(ret);

}

//-----------------Remove Elemento--------------------------------
bool RemoveElementoArvoreBi(PtrNoArvore *no, int valor){ 
    
    //pode nao encontrar o valor (NULL) -> return false
    //nao remove
    if((*no) == NULL) return false;

    //encontrado o valor a ser removido
    if((*no)->chave == valor){ 
        
        //caso 1 (folha): no -> NULL
        if((*no)->direita == NULL && (*no)->esquerda == NULL){
            (*no) = NULL;
        }

        //caso 2 (subarvore.esquerda existe): no = no.esquerda
        else if ((*no)->esquerda != NULL && (*no)->direita = NULL){
            (*no) = (*no)->esquerda;
        }

        //caso 3 (subarvore.direita existe): no = no.direita
        else if ((*no)->esquerda = NULL && (*no)->direita != NULL){
            (*no) = (*no)->direita
        }else{
            //caso 4 (temos as duas subarvores):
            //caso A: maior elemento da subarvore esquerda (funcao auxiliar)
            temp = ProcuraMaiorElemento(&(*no)->esquerda);
        }

            //caso B: menor elemento da subarvore direita (funcao auxiliar)
            free(temp);
            return true;
    }//if

        //clausulas recursivas
        if (valor > (*no)->chave){
            //valor > no->chave : vai pra direita na arvora
            return (RemoveElementoArvoreBi(&(*no)->direita, valor));
        }else{
            //valor > no->chave : vai pra direita na arvora
            return (RemoveElementoArvoreBi(&(*no)->esquerda, valor));
        }//if 2

}

//-----------------Pre Ordem---------------------------------------
void PreOrdemArvoreBi(PtrNoArvore *no){
    
    if ((*no) == NULL){
        return;
        printf("%d ", (*no)->chave);
        PreOrdemArvoreBi(&(*no)->diretira);
        PreOrdemArvoreBi(&(*no)->esquerda);
    }//if
}

//-----------------Em Ordem---------------------------------------
void EmOrdemArvoreBi(PtrNoArvore *no){
    
    if ((*no) == NULL){
        return;
        EmOrdemArvoreBi(&(*no)->esquerda);
        printf("%d ", (*no)->chave);
        EmOrdemArvoreBi(&(*no)->direita);
    }//if
}

//-----------------Pos Ordem---------------------------------------
void PosOrdemArvoreBi(PtrNoArvore *no){
   
    if ((*no) == NULL){
        return;
        PosOrdemArvoreBi();
        PosOrdemArvoreBi();
    }//if
    
}

//-----------------Pesquisa Elemento-------------------------------
bool ProcuraElemento(PtrNoArvore *no, int valor){

    //nao achou o elemento
    if ((*no)->chave == NULL){
        return false;
    }//if2

    //achou o elemento
    if ((*no)->chave = valor){
        return true;
    }//if1
    
    if (valor > (*no)->chave){
        return(ProcuraElemento(&(*no)->direita, valor))
    }else{
        return(ProcuraElemento(&(*no)->esquerda, valor))
    }//else

}//funcao

//destruit arvore
//maixmo (interativa/recursiva)
//minimo (interativa/recursiva)

//-----------------Main--------------------------------------------
int main(int argc, char const *argv[]){
    
    PtrNoArvore raiz;

    IniciaArvoreBi(&raiz);

    if (EstaVaziaArvoreBi(&raiz)){
        printf("Arvore etsa vazia!");
    }else{
        printf("Arvore contem elementos");
    }
    
    int inserir[] = {10, 5, 17, 13, 48, 10, 10, -10};
    for (int i = 0; i < 8; i++){
        AdicionaElementoArvoreBi(&raiz, inserir[i]);
    }

    printf("Pre Ordem: ");
    PreOrdemArvoreBi(&raiz);
    printf("\n");

    int consulta[] = {17, 13, -11, 2};
    for (int k = 0; k < 4; k++){
        if (ProcuraElemento()){
            
        }
    }
    
    //caso folha
    RemoveElementoArvoreBi(&raiz, -10);
    printf("Pre ordem: ");
    PreOrdemArvoreBi(&raiz);
    printf("\n");

    //caso 4 (ambas subarvores)
    RemoveElementoArvoreBi(&raiz, 17);
    printf("Pre ordem: ");
    PreOrdemArvoreBi(&raiz);
    printf("\n");


    RemoveElementoArvoreBi(&raiz, 13);
    printf("Pre ordem: ");
    PreOrdemArvoreBi(&raiz);
    printf("\n");

    RemoveElementoArvoreBi(&raiz, 48);
    printf("Pre ordem: ");
    PreOrdemArvoreBi(&raiz);
    printf("\n");

    //apenas a subarvore da esquerda
    RemoveElementoArvoreBi(&raiz, 10);
    printf("Pre ordem: ");
    PreOrdemArvoreBi(&raiz);
    printf("\n");

    printf("------------------------------\n\n\n\n\n\n\n\n");

    return 0;
}
