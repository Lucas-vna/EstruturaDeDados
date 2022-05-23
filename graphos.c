#include <stdbool.h>
#include <stdbool.h>
#include <stdlib.h>

// TIPOS

typedef struct{

    int *matriz; //por 0 e 1
    int vertices; //wtd de vertices
    int arestas;
    bool dirigido;

} GrafoMatriz;

//inicializacao

void iniciaGrafoMatriz(GrafoMatriz *g, int V, bool dir){

    int i, j;

        //**matriz
        g->matriz = malloc(V * sizeof(int));
        for (i = 0; i < V; i++)
        {
            g->matriz[i] = malloc(V * sizeof(int));
        }//for
        
        //vertices
        g->vertices = V;
        
        //arestas
        g->arestas = 0; 
        
        //dirigido ou nao
        g->dirigido = dir;

        //alocando 0 para geral
        for (i = 0; i < V; i++){
            for (j = 0; j < V; j++)
            {
                g->matriz[i][j] = 0; 

            }//for interno
        }//for externo
    


// impressao

void imprimeGrafoMatriz(GrafoMatriz *g){

    int i, v, j;

        V = g->vertices;


}



//inserir arestas

void insereArestaGrafosMatriz(GrafoMatriz *g, int v1, int v2){

    g->matriz[v1][v2] = 1;

    if (!g->dirigido)
    {
        g->matriz[v1][v2] = 1;
    }
    else
    {

        g->arestas++;

    }

}



//remocao

void removeArestasGrafosMatriz(GrafoMatriz *g, int v1, int v2){



}

}//function


int main(int agrc, const char *argv[]){

    GrafoMatriz g;

    iniciaGrafoMatriz(&g, 6, true);

    imprimeGrafoMatriz(&g);

    printf("----------------------\n");



    printf("----------------------\n");

    return 0;
}
