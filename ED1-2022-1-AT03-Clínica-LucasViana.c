#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define TOP 200

FILE *arqsaida;

//---------------DEFINICOES----------------------------------------------

typedef struct NoLista *PtrNoLista;

typedef struct{

    char dados[TOP];
    int valor;

}Objeto;

typedef struct NoLista
{
    Objeto obj;
    PtrNoLista proximo;
    PtrNoLista anterior;

} NoLista;

typedef struct NoLista nolista;

// ListaDuplamente
typedef struct
{
    int qtdeElementos;
    PtrNoLista inicio;

} ListaDupla;

typedef struct ListaDupla lista;

//----------------------------------------------------------------------

//---------------INICIA LISTA DUPLA-------------------------------------

void iniciaListaDupla(ListaDupla *lista)
{
    lista->qtdeElementos = 0;

    PtrNoLista sentinela = malloc(sizeof(nolista));

    sentinela->obj.valor = -999;

    sentinela->proximo = sentinela;
    sentinela->anterior = sentinela;
    
    lista->inicio = sentinela;
}

//----------------------------------------------------------------------

//---------------ESTA VAZIA LISTA DUPLA---------------------------------

bool estaVaziaListaDupla(ListaDupla *lista)
{
    return (lista->inicio == NULL);
}

//----------------------------------------------------------------------

//---------------TAMANHO LISTA DUPLA------------------------------------

int tamanhoListaDupla(ListaDupla *lista)
{
    return (lista->qtdeElementos);
}

//----------------------------------------------------------------------

//---------------IMPRIME LISTA DUPLA------------------------------------

void imprimeListaDupla(ListaDupla *lista)
{
    PtrNoLista aux;
    // verifica se a lista esta vazi
    if (estaVaziaListaDupla(lista) == true)
    {
        printf("Lista Vazia!");
    }
    else
    {
        //PtrNoLista aux;

        for (aux = lista->inicio; aux != NULL; aux = aux->proximo)
        {
            printf("%d %s\n", aux->obj.valor, aux->obj.dados);
        } // for
    }// else
}//funcao

//----------------------------------------------------------------------

void inserir_no_inicio(ListaDupla *lista, Objeto x){

    nolista *novo = malloc(sizeof(nolista)); 

    if (novo)
    {
        novo->obj = x;
        novo->proximo = lista->inicio;
        novo->anterior = lista->inicio;
        lista->inicio->proximo = novo;
        lista->inicio->anterior = novo;

        lista->qtdeElementos++;
    }
    else
    {
        printf("WARNING! Erro ao alocar memoria! \n");
    }//else
    
}//fucao

//---------------INSERE LISTA DUPLA-------------------------------------

bool inserirListaDupla(ListaDupla *lista, Objeto x)
{
    PtrNoLista aux;
    
    PtrNoLista novo;
    novo = (PtrNoLista)malloc(sizeof(nolista));

    if (novo)
    {
        novo->obj = x;
        
        if (lista->inicio == NULL)
        {
            inserir_no_inicio(lista, x);

        }
        else if(x.valor < lista->inicio->proximo->obj.valor){
           
            novo->proximo = lista->inicio->proximo;
            novo->anterior = lista->inicio;
            lista->inicio->proximo = novo;
            novo->proximo->anterior = novo;

            lista->qtdeElementos++;

        }
        else {
            aux = lista->inicio;
            
            while (aux->proximo != lista->inicio && x.valor > aux->proximo->obj.valor)
            {
                aux = aux->proximo;

            }    

            novo->proximo = aux->proximo;
            novo->anterior = aux;
            aux->proximo->anterior = novo;
            aux->proximo = novo;

            lista->qtdeElementos++;
            //}//while
            
        }//else
        
    }//if 1
    else{
        printf("Erro ao alocar memoria! \n");
    }//else

}//funcao

//----------------------------------------------------------------------

//---------------IMPRIME LISTA DUPLA------------------------------------

void imprimeListDupla(ListaDupla *lista)
{
    nolista *percorre = lista->inicio;

    printf("%s %d\n", percorre->obj.dados, percorre->obj.valor);
   
    percorre = percorre->proximo;
   
    while (percorre != lista->inicio)
    {
        printf("%s %d\n", percorre->obj.dados, percorre->obj.valor);
        percorre = percorre->proximo;

    } // while
}

//-----------------------------------------------------------------------

//---------------IMPRIME REVERSO LISTA DUPLA-----------------------------

void imprimeReverso(ListaDupla *lista)
{

    if (estaVaziaListaDupla(lista) == true)
    {
        printf("Alista esta vazia!");
    } // if
    else
    {

        PtrNoLista aux;
        aux = lista->inicio;

        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        printf("{");

        while (aux->anterior != NULL)
        {
            printf("%d ", aux->obj.valor);
            aux = aux->anterior;
        }
        printf("%d ", aux->obj.valor);
        printf("}\n");

    } // else

} // funcao

//----------------------------------------------------------------------

//---------------IMPRIME NO ARQUIVO-------------------------------------

void imprimeNoArq(ListaDupla *lista)
{

    if (estaVaziaListaDupla(lista))
    {
        printf("A lista esta vazia");
    }
    else
    {
        PtrNoLista aux;
        printf("tamanho = %d", lista->qtdeElementos);
        for (aux = lista->inicio->proximo; aux->obj.valor != -999; aux = aux->proximo)
        {
            fprintf(arqsaida, "{%d %s\n", aux->obj.valor, aux->obj.dados);
            printf("{%d %s\n", aux->obj.valor, aux->obj.dados);
        } // for

    } // else

} // funcao

//----------------------------------------------------------------------

//---------------IMPRIME REVERSO LISTA DUPLA (ARQUIVO)------------------

void imprimeREVListDupla(ListaDupla *lista)
{

    if (estaVaziaListaDupla(lista) == true)
    {
        printf("Lista Vazia!");
    }
    else
    {
        PtrNoLista aux;
        aux = lista->inicio;

        while (aux->proximo != NULL)
        {
            aux = aux->proximo;

        } // while 1

        while (aux != NULL)
        {
            fprintf(arqsaida, ("{%d, %s\n", aux->obj.valor, aux->obj.dados));
            aux = aux->anterior;

        } // while 2

    } // else

} // funcao

//----------------------------------------------------------------------

//---------------REMOVE LISTA DUPLA-------------------------------------

/*void removeListaDupla(ListaDupla *lista)
{
    NoLista *percorre = lista->inicio, *aux;

    while (percorre->proximo != lista->inicio)
    {
        if (percorre->obj.dados == 0)
        {
            if (percorre == lista->inicio)
            {
                lista->inicio = percorre->proximo;
                lista->fim->proximo = lista->inicio;
                lista->inicio->anterior = lista->fim;
                lista->qtdeElementos--;
                free(percorre);
                return 0;

            } // if 2
            else
            {
                percorre->anterior->proximo = percorre->proximo;
                percorre->proximo->anterior = percorre->anterior;
                lista->qtdeElementos--;
                free(percorre);
                return 0;

            } // else
        }     // if 1

        percorre = percorre->proximo;

    } // while

    if (percorre->obj.dados == 0 && percorre == lista->fim)
    {
        lista->inicio->anterior = lista->fim->anterior;
        lista->fim = lista->inicio->anterior;
        lista->fim->proximo = lista->inicio;
        lista->qtdeElementos--;
        free(percorre);
        return;
    } //if 3

} // funcao
*/

//----------------------------------------------------------------------

//---------------LIBERA LISTA DUPLA-------------------------------------

void liberaListDupla(ListaDupla *lista)
{
    nolista *percorre = lista->inicio->proximo;
    nolista *proximo;
    
    lista->inicio = NULL;

    while (percorre->proximo != NULL)
    {
        proximo = percorre->proximo;
        free(percorre);
        proximo = percorre;

    } // while

    free(1);
} // funcao

//----------------------------------------------------------------------

//---------------PESQUISA LISTA DUPLA-------------------------------------

void pesquisaListaDupla(ListaDupla *lista, int x)
{

    if (estaVaziaListaDupla(lista) == true)
    {
        printf("Nao possui elementos na lista");
    }

    PtrNoLista aux;
    aux = lista->inicio;

    while (aux != NULL && aux->obj.valor)
    {
        aux = aux->proximo;
    }

    if (aux == NULL || aux->obj.valor > x)
    {
        printf("O elemento nao foi encontrado na lista!\n");
    }
    else
    {
        fprintf(arqsaida, "{%d, %s", aux->obj.valor, aux->obj.dados);
    } // else

} // funcao

//----------------------------------------------------------------------

//---------------DESTROI LISTA DUPLA------------------------------------

bool destruirListaDupla(ListaDupla *lista)
{

    PtrNoLista aux;
    PtrNoLista aux2;

    if (estaVaziaListaDupla(lista) == true)
    {
        return false;
    }
    else
    {
        aux2 = lista->inicio;
        printf("destroi lista\n");
        while (aux2 != NULL)
        {
            aux = aux2;
            aux2 = aux2->proximo;
            free(aux);
            lista->qtdeElementos--;
        } // while

    } // else

} // funcao

//----------------------------------------------------------------------

//---------------MAIN---------------------------------------------------

int main(int argc, char *argv[])
{

    printf("Numero de parametros fornecidos: %d\n", argc);

    for (int i = 0; i < argc; i++)
    {
        printf("argv[%d] - %s", i, argv[i]);
    }

    FILE *entrada = fopen(/*argv[]*/"entradaLDC.txt", "r");
    arqsaida = fopen(/*argv[2]*/"saidaLDC.txt", "w");

    if (entrada == NULL)
    {
        printf("O arquivo de ENTRADA não pode ser aberto corretamente!\n");
        return 1;
    }
    else
    {
        printf("O arquivo de ENTRADA pode ser aberto com sucesso!\n");
    }

    if (arqsaida == NULL)
    {
        printf("O arquivo de SAIDA não pode ser aberto corretamente!\n");
        return 1;
    }
    else
    {
        printf("O arquivo de SAIDA pode ser aberto com sucesso!\n");
    }

    //--------INICIA LISTA---------------------------------------------------

    ListaDupla lista;
    Objeto cadastro;

    iniciaListaDupla(&lista);

    char x;
    char tipoArq;
    int AuxDePesquisa = 0;

    while (feof(entrada) == 0)
    {
        // pegar o char 1 do arquivo
        x = fgetc(entrada);

        if (x == '{')
        {

            // se tiver { -> pegar o ID (valor) e o restante da linha como string
            fscanf(entrada, "%d,%[^\n]\n", &cadastro.valor, cadastro.dados);

            inserirListaDupla(&lista, cadastro);

        } // if
        else
        {

            if (x == '1' || x == '2' || x == '3')
            {
                tipoArq = x;
                printf("Tipo do Arquivo: %c\n", tipoArq);

            } // if

            if (tipoArq == '3')
            {
                fscanf(entrada, "%d", &AuxDePesquisa);
                printf("Aux de Pesquisa = %d\n", AuxDePesquisa);
            } // if2

        } // else

    } // while

    switch (tipoArq)
    {
    case '1':
        imprimeNoArq(&lista);
        printf("Impressao em ordem crescente!!\n");
        break;

    case '2':
        imprimeREVListDupla(&lista);
        printf("SUCESSO!!\n");
        break;

    case '3':
        pesquisaListaDupla(&lista, AuxDePesquisa);
        printf("SUCESSO!!\n");
        break;

    default:
        printf("ERRO! Tipo de implementação não reconhecido!\n");
        break;
    }

    destruirListaDupla(&lista);
    fclose(entrada);
    fclose(arqsaida);

    return 0;
}
