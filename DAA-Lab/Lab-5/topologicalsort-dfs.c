#include<stdio.h>
#include<stdlib.h>


int *visited;
int n, k =0;
int *pop_sequence;
int **adjacency_matrix;


void dfs(int **adjacency_matrix, int vertex){
  visited[vertex] = 1;
  for(int i = 0; i < n; i++){
    if(adjacency_matrix[vertex][i] == 1){
      if(visited[i] == 0){
        dfs(adjacency_matrix, i);
      }
    }
  }
  pop_sequence[k] = vertex;
  k++;
}
int main(){
  printf("\nEnter the number of vertices of the graph:\n");
  scanf("%d", &n);

  int **adjacency_matrix= (int**)calloc(n, sizeof(int*));
  int i;

  for (i = 0; i < n; ++i){
    adjacency_matrix[i] = (int*)calloc(n,sizeof(int));
  }

  visited = (int*)calloc(n,sizeof(int));

  pop_sequence = (int*)calloc(n,sizeof(int));

  printf("Enter the values in the adjacency_matrix\n");
  for ( i = 0; i < n; ++i){
    visited[i]=0;
    for (int j = 0; j < n; ++j){
      scanf("%d", &adjacency_matrix[i][j]);
    }
  }

  for (i = 0; i < n; ++i){
    if(visited[i] == 0){
      dfs(adjacency_matrix, i);
    }
  }

  printf("\n");
  printf("The Topological Sort is\n: ");
  for (i = k-1; i >= 0 ; i--){
    printf("%d   ", pop_sequence[i]);
  }

  return 0;
}
