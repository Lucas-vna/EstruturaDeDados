/**
* @file ED1-2022-1-AT02-Compilador-LucasViana.c
* @author Lucas dos Reis Viana
* @date 28 Mar 2022
* @brief
* Enunciado completo:
* FAZENDO UM COMPILADOR USANDO PILHA DINAMICA
**/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAMANHO 10

//-----------------Definir Tipos---------------------------------
typedef struct NoPilha* PtrNoPilha;

typedef struct NoPilha{
    int valor;
    PtrNoPilha proximo;
}NoPilha;

typedef struct{
    int tamanho;
    PtrNoPilha topo;
}PilhaDinamica;

//-----------------Inicia Pilha----------------------------------
void IniciaPilhaDinamica(PilhaDinamica *pd){
    pd->tamanho = 0;
    pd->topo = NULL;
}

//-----------------Tamanho Pilha---------------------------------
int TamanhoPilhaDinamica(PilhaDinamica *pd){
    return(pd->tamanho);
}

//-----------------Esta Vazia Pilha------------------------------
bool EstaVaziaPilhaDinamica(PilhaDinamica *pd){
    return(pd->tamanho == 0);
}

//-----------------Imprime Pilha---------------------------------
void ImprimePilhaDinamica(PilhaDinamica *p){
    printf("Pilha D - [");
    PtrNoPilha ptr;
    for (ptr = p->topo; ptr != NULL; ptr = ptr->proximo){
        printf("%d ", ptr->valor);
    }//for

    printf(" ]");
}

//-----------------Empilha Elemento-------------------------------
void EmpilhaElemento(PilhaDinamica *pd, int valor){
    PtrNoPilha aux;

    //criando bloco
    aux = (PtrNoPilha)malloc(sizeof(PtrNoPilha));

    //colocando o valor dentro do bloco
    aux->valor = valor;

    //novo: proximo->topo
    aux->proximo = pd->topo;

    //topo->novo
    pd->topo = aux;

    //incrementar tamanho
    pd->tamanho++;
}

//-----------------Desempilha Elemento-----------------------------
int DesempilhaElemento(PilhaDinamica *pd){
    //valor para retorno
    int v = -99;

    if (!EstaVaziaPilhaDinamica(pd)){
        PtrNoPilha aux;

        aux = pd->topo;

        v = aux->valor;

        //pd->topo = pd->proximo
        pd->topo = aux->proximo;

        //desalocar memoria
        free(aux);

        //decrementar qtde da pilha
        pd->tamanho--;
    }else{
        printf("Warning: esta vazia!\n");
    }//else

    //retornar o valor da pilha
    return(v);
}
//-----------------Destroi Pilha Dinamica--------------------------
void DestroiPilhaDinamica(PilhaDinamica *pd) {
  PtrNoPilha remover;
    
    while(pd->topo != NULL) {
        remover = pd->topo;
        pd->topo = pd->topo->proximo;
        free(remover);
    }//while
}

///-----------------Passando Eq em C para Assembly------------------
void CtoAssembly(PilhaDinamica *pd, int x){
    PtrNoPilha PilhaAux;

    IniciaPilhaDinamica(&PilhaAux);
    int vetor_temp[i];

    for (int i = pd->tamanho; i != NULL; i--){
        DesempilhaElemento(&PilhaAux);

        EmpilhaElemento();

    }
        
}

//-----------------MAIN---------------------------------------------
int main(int argc, char const *argv[]){
    
    printf("Quantidade de parametros: %d \n", argc);

    PilhaDinamica SegundaPilhaDinamica;
    IniciaPilhaDinamica(&SegundaPilhaDinamica);
    
        FILE *entrada = fopen("entrada01.txt", "r");
        FILE *saida   = fopen("saida01.txt", "w");

         //Verificar se o arquivo de entrada é válido
        if(entrada == NULL) {
            printf("O arquivo de ENTRADA nao pode ser aberto!\n");
            system ("pause");
            return(0);
        }else{
            printf("O arquivo foi aberto com sucesso!\n");
        }

        //Verificar o arquivo de saida (valido)
        if(saida == NULL) {
            printf("O arquivo de SAiDA não pode ser criado !\n");
            system ("pause");
            return(0);
        }else{
            printf("O arquivo foi criado com sucesso!\n");
        }//else

        int letra;
        while (true)
        {
            if (letra >= 'a' && letra <= 'z')
            {
                fscanf(entrada, "%c", &letra);
            }else
            {
                    if (letra == '+' || letra == '-' || 
                letra == '*' || letra == '/' ||
                letra == '^')
                {
                    fscanf(entrada, "%d", &letra);
                }//if
            }//else
            
            if (feof(entrada))
            {
                break;
            }//if   
            
        }//while
        
        //passando a equação para conversao
        while (!EstaVaziaPilhaDinamica(&SegundaPilhaDinamica))
        {
            int aux = 0;
            aux = DesempilhaElemento(&SegundaPilhaDinamica);
            CtoAssembly(saida, aux);
        }//while
        
        DestroiPilhaDinamica(&SegundaPilhaDinamica);

    fclose(entrada);
    fclose(saida);
    return 0;
}
