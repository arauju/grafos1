#include "GRAFOlista.h"

/********** Lista de adjacencia **********/

/* A função NovoNo() recebe um vértice v e o endereço
prox de um nó e devolve o endereço a de um novo nó
tal que a->v == v e a->prox == prox */
Link NovoNo(int v, Link prox){
  Link a = (Link) malloc(sizeof(struct No));
  a->w = v;
  a->prox = prox;
  return a;
}

/* Cria um grafo vazio de n vertices */
Grafo GRAFOcria(int n){
  int i;
  Grafo G = malloc(sizeof(Grafo));

  G->n = n;
  G->m = 0;
  G->adj = malloc(sizeof(n * sizeof(Link)));
  for (i = 0 ; i < n ; i++)
    G->adj[i] = NULL;
  return G;
}

/* Funcao para inserir uma aresta em um grafo */
void GRAFOinsereA(Grafo G, Aresta e){
  if (G->adj[e.v] == NULL){
    Link aux1 = NovoNo(e.w, NULL);
    G->adj[e.v] = aux1;
    Link aux2 = NovoNo(e.v, NULL);
    G->adj[e.w] = aux2;
    G->m++;
  } else {
    Link aux5 = G->adj[e.v];
    Link aux6 = NovoNo(e.w, aux5);
    G->adj[e.v] = aux6;
    Link aux3 = G->adj[e.w];
    Link aux4 = NovoNo(e.v, aux3);
    G->adj[e.w] = aux4;
    G->m ++;
  }
}

/* Funcao para remover uma aresta de um grafo */
void GRAFOremoveA(Grafo G, Aresta e){


}

/* Funcao para imprimir um grafo */
void GRAFOimprime(Grafo G) {
  int i;
  for (i = 0; i < G->n; i++){
    if (G->adj[i] == NULL){
      printf("NULL\n");
    } else {
      printf("%d\t", i);
      Link aux1 = G->adj[i];
      while (aux1 != NULL){
        printf("%d\t", aux1->w);
        aux1 = aux1->prox;
      }
      printf("\n");
    }
  }
}

/* Funcao para destruir um grafo */
void GRAFOdestroi(Grafo G){

}

/* Funcao para exibir os graus dos vertices de um grafo */
void GRAFOgrau(Grafo G){

}


/********** CONSTRUTORES **********/

/* Grafo completo */
Grafo GRAFOconstroiCompleto(int n){
    int i, j;
    Grafo G = GRAFOcria(n);
    for (i = 0; i < n; i++){
        for (j = i+1; j < n; j++){
            Aresta e;
            e.v = i;
            e.w = j;
            GRAFOinsereA(G, e);
            printf("djfsid\n");
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

        if (i == n-1) e.w = 0;

        GRAFOinsereA(G, e);
    }
    return G;
}
