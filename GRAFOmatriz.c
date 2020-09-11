#include "GRAFOmatriz.h"

/********** TAD GRAFO **********/

/* Cria matriz [ l ] [ c ] vazia */
int **MATRIZint(int l, int c){
  int i, j;
  int **adj = (int **) malloc(l * sizeof(int*));
  for(i = 0 ; i < l ; i ++){
    adj[i] = (int*) malloc(c * sizeof(int));
    for(j = 0 ; j < l ; j++)
      adj[i][j] = 0;
  }
  return adj;
}

/* Cria um grafo vazio de n vertices */
Grafo GRAFOcria(int n){
  Grafo G = (Grafo) malloc(sizeof(struct grafo));
  G->n = n;
  G->m = 0;
  G->adj = MATRIZint(n,n);
  return (G);
}

/* Funcao para inserir uma aresta em um grafo */
void GRAFOinsereA(Grafo G, Aresta e){
  G->adj[e.v][e.w] = 1;
  G->adj[e.w][e.v] = 1;
  G->m ++;
}

/* Funcao para remover uma aresta de um grafo */
void GRAFOremoveA(Grafo G, Aresta e){
  G->adj[e.v][e.w] = 0;
  G->adj[e.w][e.v] = 0;
  G->m --;
}

/* Funcao para imprimir um grafo */
void GRAFOimprime(Grafo G) {
  int i, j;
  for (i = 0; i < G->n; i++){
    for (j = 0; j < G->n; j++){
      printf("%d\t", G->adj[i][j]);
    }
    printf("\n");
  }
}

/* Funcao para destruir um grafo */
void GRAFOdestroi(Grafo G){
  int i, j;
  for(i = 0; i < G->n; i++){
    free(G->adj[i]);
  }
  free(G);
}

/* Funcao para exibir os graus dos vertices de um grafo */
void GRAFOgrau(Grafo G){
  int i, j, cont = 0;
  for (i = 0; i < G->n; i++){
    for (j = 0; j < G->n; j++){
      if (G->adj[i][j] == 1)
        cont ++;
      }
      printf("Vertice %d: grau %d\n", i, cont);
      cont = 0;
  }
}

/********** CONSTRUTORES **********/

/* Grafo completo */
Grafo GRAFOconstroiCompleto(int n){
    int i, j;
    Grafo G = GRAFOcria(n);
    for (i = 0; i < n; i++){
    	for (j = i + 1; j < n; j++){
    	    Aresta e;
    	    e.v = i;
          e.w = j;
    	    GRAFOinsereA(G, e);
    	}
    }
    return G;
}

/* Grafo ciclo */
Grafo GRAFOconstroiCiclo(int n){
    int i;
    Grafo G = GRAFOcria(n);
    for (i = 0; i < n; i++){
      Aresta e;
      e.v = i;
      e.w = i+1;

      if (i == n-1)
        e.w = 0;

      GRAFOinsereA(G, e);
    }
    return G;
}
