#include <stdio.h>
#include <stdbool.h>

// PrtNoLista
typedef struct NoLista *PtrNoLista;

// NoLista (alterado)
typedef struct NoLista
{
    int elemento;
    PtrNoLista proximo;
    PtrNoLista anterior;
} NoLista;

// ListaDuplamente
typedef struct
{
    int qtdeElementos;
    PtrNoLista inicio;
} ListaDupla;

// INICIA LISTA DUPLA
void iniciaListaDupla(ListaDupla *lista)
{
    lista->qtdeElementos = 0;
    lista->inicio = NULL;
}

// ESTA VAZIA LISTA DUPLA
bool estaVaziaListaDupla(ListaDupla *lista)
{
    return (lista->inicio == NULL);
}

// TAMANHO LISTA DUPLA
int tamanhoListaDupla(ListaDupla *lista)
{
    return (lista->qtdeElementos);
}

// IMPRIME LISTA DUPLA
void imprimeListaDupla(ListaDupla *lista)
{
    PtrNoLista percorre;
    printf("Lista = {");
    for (percorre = lista->inicio; percorre != NULL; percorre = percorre->proximo)
    {
        // elem (no lista) -> percorre
        printf("%d ", percorre->elemento);
    }
    printf("}\n");
}

//----------------------------------------------
// Insercao Lista Dupla
// input: lista, valor
//----------------------------------------------
void inserirListaDupla(PtrNoLista *lista, int valor)
{

    // criar um novo ptr NoLista (Novo)
    PtrNoLista novo;

    // alocar a memoria do Novo
    novo = malloc(sizeof(NoLista));

    // copiar o valor para o Novo
    novo->elemento = valor;

    // Novo = [NoLista = valor, ant, prox]

    //    1o caso: lista ta vazia:
    if (estaVaziaListaDupla(lista) == true)
    {

        // Inicio aponta para Novo
        lista->inicio = novo;

        // Proximo do Novo é NULL
        novo->proximo = NULL;

        // Anterior do Novo é NULL
        novo->anterior = NULL;
    } // if 1

    // 2o caso: inserir um elemento < elemento no inicio
    if (novo->elemento < lista->inicio)
    {

        // Anterior do Novo é NULL
        novo->anterior = NULL;

        // Proximo do Novo é o Inicio
        novo->proximo = lista->inicio;

        // Anteror do Inicio é o Novo
        lista->inicio->anterior = novo;

        // Inicio aponta para Novo
        lista->inicio->novo;
    }
    else
    {
        // 3o caso: percorrer e encontrar a posicao de inserção
        // Percorrer e encontrar o ponto de insercao (Aux)
        PtrNoLista aux = lista->inicio;

        // enqto o valor for menor do que o valor presente no auxiliar proximo, avança para o proximo nó
        while (valor < aux->proximo)
        {
            aux->proximo->proximo;
        }
        
        // parada: aux, cujo aux proximo tem um valor que é maior que o valor que a gente quer inserir
        

    }

    // Posicao de inserção: Logo após o auxiliar
    // Novo: que é o novo elemento
    // Aux: depois de quem a gente vai inserir

    // Proximo do Novo recebe o proximo do auxiliar (NULL ou não NULL)
    // Se o Proximo do Aux != NULL:
    // Anterior do Proximo do Aux é o Novo
    // Anterior do Novo aponta para o Aux
    // Proximo do Aux aponta para Novo

    // incrementa a qtde de elementos dentro da lista
}

//----------------------------------------------
//----------------------------------------------

int main(int argc, char *argv[])
{

    ListaDupla lista;

    iniciaListaDupla(&lista);

    imprimeListaDupla(&lista);

    printf("\n\n\n\n\nFuncionou\n");

    return 0;
}
