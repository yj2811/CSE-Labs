#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int ans[1000], min = INT_MAX, opcount=0;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void permute(int r, int matrix[][r + 1], int per[], int l){
	int i;
	if (l == r){

    opcount++;
		int sum = 0;
		for (i = 0; i <= r; i++){
			int idx = per[i];
			sum += matrix[i][idx];
		}
    printf("Combination for cost : ");
    for (i = 0; i <= r; i++)
      printf("%d ", matrix[i][per[i]]);
    printf("\nThe Cost is : %d\n", sum);
		if (sum < min){
			for (i = 0; i <= r; i++){
				int idx = per[i];
				ans[i] = matrix[i][per[i]];
			}
			min = sum;
		}

	}
	else{
		// the technique
		for (i = l; i <= r; i++){

			swap((per + l), (per + i));
			permute(r, matrix, per, l + 1);
			swap((per + l), (per + i));
		}
	}
}

int main(){
	int i, j, n;
	printf("Enter the size of the square matrix : ");
	scanf("%d", &n);
	int matrix[n][n];
	printf("Enter the matrix : \n");
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++)
			scanf("%d", &matrix[i][j]);

	}
	int per[n];
	for (i = 0; i < n; i++)
		per[i] = i;
	permute(n - 1, matrix, per, 0);
	printf("\n\n\nCombination for minimum cost : ");
	for (i = 0; i < n; i++)
		printf("%d ", ans[i]);
	printf("\nThe Minimum Cost is : %d\n", min);
	printf("Opcount = %d \n", opcount);
	return 0;
}

// #include<stdio.h>
// #include<stdlib.h>
// #include"queue.h"

// Node* newNode(int data)
// {
//     Node* temp = (Node*)(malloc(sizeof(Node)));
//     temp->data = data;
//     temp->next = NULL;
//     return temp;
// }
// Node** createGraph(int V) //like ragged matrixay
// {
//     Node** list = (Node**)(malloc(V*sizeof(Node*)));
//     for(int i = 0;i < V; i++)
//     {
//         list[i] = newNode(i);
//     }
//     return list;
// }
// Node** addEdge(Node** graph, int u, int v)
// {
//     Node* temp = graph[u];
//     while(temp->next!=NULL)
//     {
//         temp = temp->next;
//     }
//     Node* newnode = newNode(v);
//     temp->next = newnode;
//     return graph;
// }

// void bfs(Node** graph, int s, int visited[],Q* q)
// {
//     Node* temp = graph[4];
//     Enqueue(q,graph[s]);
//     while(IsEmpty(q)!=1)
//     {
//         Node* ele = Dequeue(q);
//         visited[ele->data] = 1;
//         printf("%d ",ele->data);
//         while(ele!=NULL)
//         {
//             if(visited[ele->data]==0)
//             {
//                 Enqueue(q,graph[ele->data]);
//                 visited[ele->data] = 1;
//             }
//             ele = ele->next;
//         }
//     }
// }

// void dfs(Node** graph,int s,int visited[],int push[], int pop[],int* push_idx, int* pop_idx)
// {
//     push[*push_idx]=s;
//     (*push_idx)++;
//     visited[s] = 1;
//     Node* current = graph[s];
//     printf("%d ",s);
//     current = current->next;
//     while(current) // all the children of s
//     {
//         int v = current->data;
//         if(visited[v] == 0)
//         {
//             dfs(graph,v,visited,push,pop,push_idx,pop_idx);
//         }
//         current = current->next;
//     }
//     pop[*pop_idx] = s;
//     (*pop_idx)++;
// }
// void print_adjmat(int mat[][100], int V)
// {
//     printf("The adjacency matrix (directed graph) is: \n");
//     for(int i = 0; i < V; i++)
//     {
//         for(int j =0; j < V; j++)
//         {
//             printf("%d ", mat[i][j]);
//         }
//         printf("\n");
//     }
// }
// void print_adjlist(Node** graph,int V)
// {
//     printf("The adjacency list is:\n");
//     for(int i = 0; i < V; i++)
//     {
//         Node* temp = graph[i];
//         while(temp->next != NULL)
//         {
//             printf("%d->",temp->data);
//             temp = temp->next;
//         }
//         printf("%d\n", temp->data);
//     }
// }
// int main()
// {
//     int V, E;
//     printf("Enter the number of vertices and edges\n");
//     scanf("%d %d", &V, &E);
//     printf("Enter the edges -> 0 indexed\n");
//     int matrix[100][100] = {0};
//     Node** graph = createGraph(V);
//     for(int i = 0; i < E; i++)
//     {
//         int u,v;
//         scanf("%d %d",&u,&v);
//         matrix[u][v] = 1;
//         graph = addEdge(graph,u,v);
//         graph = addEdge(graph,v,u); // undirected
//     }
//     //print adj matrix
//     print_adjmat(matrix,V);
//     //print adj list
//     print_adjlist(graph,V);

//     //dfs
//     int visited[100] = {0};
//     int push[100] = {0};
//     int pop[100] = {0};
//     int push_idx = 0;
//     int pop_idx = 0;
//     printf("DFS\n");
//     dfs(graph,0,visited,push,pop,&push_idx,&pop_idx);
//     printf("\n");
//     printf("Push sequence\n");
//     for(int i= 0; i < V; i++)
//     {
//         printf("%d ",push[i]);
//     }
//     printf("\nPop sequence\n");
//     for(int i =0;i < V; i++)
//     {
//         printf("%d ",pop[i]);
//     }
//     printf("\n");

//     //bfs
//     Q q;
// 	q.rear = -1;
// 	q.front = -1;

// 	/*for(int i = q.front; i <= q.rear; i++)
// 	{
// 		printf("%d ", (q.q[i])->data);
// 	}
// 	printf("\n%d dequeued\n", Dequeue(&q)->data);*/
// 	printf("Printing bfs\n");
// 	int visitedbfs[100]={0};
// 	bfs(graph,0,visitedbfs,&q);

// }
