#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

Node* newNode(int data)
{
    Node* temp = (Node*)(malloc(sizeof(Node)));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
Node** createGraph(int V) //like ragged array
{
    Node** list = (Node**)(malloc(V*sizeof(Node*)));
    for(int i = 0;i < V; i++)
    {
        list[i] = newNode(i);
    }
    return list;
}
Node** addEdge(Node** graph, int u, int v)
{
    Node* temp = graph[u];
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    Node* newnode = newNode(v);
    temp->next = newnode;
    return graph;
}

void dfs(Node** graph,int s,int visited[],int push[], int pop[],int* push_idx, int* pop_idx)
{
    push[*push_idx]=s;
    (*push_idx)++;
    visited[s] = 1;
    Node* current = graph[s];
    printf("%d ",s);
    current = current->next;
    while(current) // all the children of s
    {
        int v = current->data;
        if(visited[v] == 0)
        {
            dfs(graph,v,visited,push,pop,push_idx,pop_idx);
        }
        current = current->next;
    }
    pop[*pop_idx] = s;
    (*pop_idx)++;
}
void print_adjmat(int mat[][100], int V)
{
    printf("The adjacency matrix (directed graph) is: \n");
    for(int i = 0; i < V; i++)
    {
        for(int j =0; j < V; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
void print_adjlist(Node** graph,int V)
{
    printf("The adjacency list is:\n");
    for(int i = 0; i < V; i++)
    {
        Node* temp = graph[i];
        while(temp->next != NULL)
        {
            printf("%d->",temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
}
int main()
{
    int V, E;
    printf("Enter the number of vertices and edges\n");
    scanf("%d %d", &V, &E);
    printf("Enter the edges\n");
    int matrix[100][100] = {0};
    Node** graph = createGraph(V);
    for(int i = 0; i < E; i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        matrix[u][v] = 1;
        graph = addEdge(graph,u,v);
        graph = addEdge(graph,v,u); // undirected
    }
    //print adj matrix
    print_adjmat(matrix,V);
    //print adj list
    print_adjlist(graph,V);

    //dfs
    int visited[100] = {0};
    int push[100] = {0};
    int pop[100] = {0};
    int push_idx = 0;
    int pop_idx = 0;
    printf("DFS\n");
    dfs(graph,0,visited,push,pop,&push_idx,&pop_idx);
    printf("\n");
    printf("Push sequence\n");
    for(int i= 0; i < V; i++)
    {
        printf("%d ",push[i]);
    }
    printf("\nPop sequence\n");
    for(int i =0;i < V; i++)
    {
        printf("%d ",pop[i]);
    }
    printf("\n");


    return 0;
}
