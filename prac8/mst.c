#include <stdio.h>
#include <stdlib.h>

struct Edge {
  int src, dest, weight;
};

struct Subset {
  int parent, rank;
};

int find(struct Subset subsets[], int i);

void Union(struct Subset subsets[], int x, int y);

int compareEdges(const void *a, const void *b);

void KruskalMST(struct Edge edges[], int V, int E);

int main() {
  int V, E;
  scanf("%d %d", &V, &E);
  struct Edge edges[E];
  for (int i = 0; i < E; ++i) {
    scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
  }
  KruskalMST(edges, V, E);
  return 0;
}

int find(struct Subset subsets[], int i) {
  if (subsets[i].parent != i)
    subsets[i].parent = find(subsets, subsets[i].parent);
  return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y) {
  int xroot = find(subsets, x);
  int yroot = find(subsets, y);
  if (subsets[xroot].rank < subsets[yroot].rank)
    subsets[xroot].parent = yroot;
  else if (subsets[xroot].rank > subsets[yroot].rank)
    subsets[yroot].parent = xroot;
  else {
    subsets[yroot].parent = xroot;
    subsets[xroot].rank++;
  }
}

int compareEdges(const void *a, const void *b) {
  return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

void KruskalMST(struct Edge edges[], int V, int E) {
  struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));
  for (int v = 0; v < V; ++v) {
    subsets[v].parent = v;
    subsets[v].rank = 0;
  }
  qsort(edges, E, sizeof(edges[0]), compareEdges);
  printf("Minimum Spanning Tree:\n");
  for (int i = 0, e = 0; e < V - 1 && i < E; ++i) {
    int x = find(subsets, edges[i].src);
    int y = find(subsets, edges[i].dest);
    if (x != y) {
      printf("(%d, %d) - %d\n", edges[i].src, edges[i].dest, edges[i].weight);
      Union(subsets, x, y);
      ++e;
    }
  }
  free(subsets);
}
