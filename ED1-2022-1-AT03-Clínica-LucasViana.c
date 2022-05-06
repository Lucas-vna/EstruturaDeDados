#include <stdio.h>
#include <stdbool.h>

#define TOP 200

//---------------DEFINICOES----------------------------------------------

typedef struct NoLista *PtrNoLista;

typedef struct NoLista
{
    char dados[TOP];
    int valor;
    PtrNoLista proximo;
    PtrNoLista anterior;

} NoLista;

typedef struct NoLista nolista;

// ListaDuplamente
typedef struct
{
    int qtdeElementos;
    PtrNoLista inicio;
    PtrNoLista fim;

} ListaDupla;

typedef struct ListaDupla lista;

//----------------------------------------------------------------------

//---------------INICIA LISTA DUPLA-------------------------------------

void iniciaListaDupla(ListaDupla *lista)
{
    lista->qtdeElementos = 0;
    lista->inicio = NULL;
    lista->fim = NULL;
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

void imprimeListaDupla(ListaDupla *lista, FILE *arqsaida)
{
    // verifica se a lista esta vazi
    if (estaVaziaListaDupla(lista) == true)
    {
        printf("Lista Vazia!");
    }
    else
    {
        PtrNoLista aux;

        for (aux = lista->inicio; aux != NULL; aux = aux->proximo)
        {
            printf("%d %s\n, aux->obj.chave, aux->obj.dados");
        } // for
    }     // else
} // funcao

//----------------------------------------------------------------------

//---------------INSERE LISTA DUPLA-------------------------------------

void inserirListaDupla(ListaDupla *lista, NoLista valor)
{
    NoLista *aux = (NoLista *)malloc(sizeof(NoLista));

    aux->valor = aux->valor;

    if (lista->qtdeElementos == 0)
    {
        // inicio da lista aponta para lista aux
        lista->inicio = aux;

        // fim da lista aponta para lista aux
        lista->fim = aux;

        // aumenta a qtde de elementos
        lista->qtdeElementos++;
    } // if 1
    else if (lista->qtdeElementos == 1)
    {
        // proximo do inicio se iguala a lista aux
        lista->inicio->proximo = aux;

        // anterior do inicio se iguala a lista aux
        lista->inicio->anterior = aux;

        // fim da lista = aux
        lista->fim = aux;

        // anterior do aux aponta pro inicio da lista
        aux->anterior = lista->inicio;

        // proximo do aux aponta pro inicio da lista
        aux->proximo = lista->inicio;

        // aumenta a qtde de elementos
        lista->qtdeElementos++;
    } // if 2
    else
    {
        // anterior do inicio = aux
        lista->inicio->anterior = aux;

        // proximo do aux = inicio da lista
        aux->proximo = lista->inicio;

        // anterior do aux = fim da lista
        aux->anterior = lista->fim;

        // proximo do fim = aux
        lista->fim->proximo = aux;

        // im da lista = aux
        lista->fim = aux;

        // aumenta a qtd de elementos
        lista->qtdeElementos++;
    } // else 2
}

//----------------------------------------------------------------------

//---------------IMPRIME LISTA DUPLA------------------------------------

void imprimeListDupla(ListaDupla *lista)
{
    nolista *percorre = lista->inicio;

    printf("%s %d\n", percorre->dados, percorre->valor);
    percorre = percorre->proximo;
    while (percorre != lista->inicio)
    {
        printf("%s %d\n", percorre->dados, percorre->valor);
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
            printf("%d ", aux->valor);
            aux = aux->anterior;
        }
        printf("%d ", aux->valor);
        printf("}\n");

    } // else

} // funcao

//----------------------------------------------------------------------

//---------------IMPRIME NO ARQUIVO-------------------------------------

void imprimeNoArq(ListaDupla *lista, FILE *arqsaida)
{

    nolista *percorre;

    if (estaVaziaListaDupla(lista) == true)
    {
        printf("A lista esta vazia");
    }
    else
    {
        PtrNoLista aux;

        for (aux = lista->inicio; aux != NULL; aux = aux->proximo)
        {
            fprintf(arqsaida, "{%d %s\n}", aux->valor, aux->dados);
        } // for

    } // else

} // funcao

//----------------------------------------------------------------------

//---------------IMPRIME REVERSO LISTA DUPLA (ARQUIVO)------------------

void imprimeREVListDupla(ListaDupla *lista, FILE *arqsaida)
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
            fprintf(arqsaida, ("{%d, %s\n", aux->valor, aux->dados));
            aux = aux->anterior;
        } // while 2

    } // else

} // funcao

//----------------------------------------------------------------------

//---------------REMOVE LISTA DUPLA-------------------------------------
void removeListaDupla(ListaDupla *lista)
{
    NoLista *percorre = lista->inicio, *aux;

    while (percorre->proximo != lista->inicio)
    {
        if (percorre->dados == 0)
        {
            if (percorre == lista->inicio)
            {
                lista->inicio = percorre->proximo;
                lista->fim->proximo = lista->inicio;
                lista->inicio->anterior = lista->fim;
                lista->qtdeElementos--;
                free(percorre);
                return;

            } // if 2
            else
            {
                percorre->anterior->proximo = percorre->proximo;
                percorre->proximo->anterior = percorre->anterior;
                lista->qtdeElementos--;
                free(percorre);
                return;

            } // else
        }     // if 1

        percorre = percorre->proximo;

    } // while

    if (percorre->dados == 0 && percorre == lista->fim)
    {
        lista->inicio->anterior = lista->fim->anterior;
        lista->fim = lista->inicio->anterior;
        lista->fim->proximo = lista->inicio;
        lista->qtdeElementos--;
        free(percorre);
        return;
    } // i 3

} // funcao

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

void pesquisaListaDupla(ListaDupla *lista, int x, FILE *arqsaida)
{

    if (estaVaziaListaDupla(lista) == true)
    {
        printf("Nao possui elementos na lista");
    }

    PtrNoLista aux;
    aux = lista->inicio;

    while (aux != NULL && aux->valor)
    {
        aux = aux->proximo;
    }

    if (aux == NULL || aux->valor > x)
    {
        printf("O elemento nao foi encontrado na lista!\n");
    }
    else
    {
        fprintf(arqsaida, "{%d, %s", aux->valor, aux->dados);
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

    if (argc != 3)
    {
        printf("WARNING: qtd de parametros invalido!");
        return 0;
    }

    for (int i = 0; i < argc; i++)
    {
        printf("argv[%d] - %s, i, argv[i]");
    }

    FILE *entrada = fopen(argv[1], "r");
    FILE *saida = fopen(argv[2], "w");

    if (entrada == NULL)
    {
        printf("O arquivo de ENTRADA não pode ser aberto corretamente!\n");
        exit(1);
    }
    else
    {
        printf("O arquivo de ENTRADA pode ser aberto com sucesso!\n");
    }

    if (saida == NULL)
    {
        printf("O arquivo de SAIDA não pode ser aberto corretamente!\n");
        exit(1);
    }
    else
    {
        printf("O arquivo de SAIDA pode ser aberto com sucesso!\n");
    }

    //--------INICIA LISTA---------------------------------------------------

    ListaDupla lista;
    NoLista cadastro;

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
            fscanf(entrada, "%d,%[^\n]\n", &cadastro.valor, &cadastro.dados);

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
        imprimeNoArq(&lista, saida);
        printf("SUCESSO!!\n");
        break;

    case '2':
        imprimeREVListDupla(&lista, saida);
        printf("SUCESSO!!\n");
        break;

    case '3':
        pesquisaListaDupla(&lista, AuxDePesquisa, saida);
        printf("SUCESSO!!\n");
        break;

    default:
        printf("ERRO! Tipo de implementação não reconhecido!\n");
        break;
    }

    destruirListaDupla(&lista);
    fclose(entrada);
    fclose(saida);

    return 0;
}
