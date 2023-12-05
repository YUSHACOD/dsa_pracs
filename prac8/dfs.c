#include <stdbool.h>
#include <stdio.h>

#define MAX_VERTICES 100

bool adjacency_matrix[MAX_VERTICES][MAX_VERTICES];

bool visited[MAX_VERTICES];

int vertices;

void dfs(int vertex) {
  int i;
  visited[vertex] = true;
  printf("%d ", vertex);
  for (i = 0; i < vertices; i++) {
    if (adjacency_matrix[vertex][i] && !visited[i]) {
      dfs(i);
    }
  }
}

int main(int argc, char *argv[]) {
  int i, j;
  printf("Enter the number of vertices: ");
  scanf("%d", &vertices);
  printf("Enter the adjacency matrix:\n");
  for (i = 0; i < vertices; i++) {
    for (j = 0; j < vertices; j++) {
      int t;
      scanf("%d", &t);
      adjacency_matrix[i][j] = (t == 1) ? (1) : (0);
    }
  }
  printf("DFS: ");
  dfs(0);
  printf("\n");
  return 0;
}
