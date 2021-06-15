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

void bfs(Node** graph, int s, int visited[],Q* q)
{
    Node* temp = graph[4];
    Enqueue(q,graph[s]);
    while(IsEmpty(q)!=1)
    {
        Node* ele = Dequeue(q);
        visited[ele->data] = 1;
        printf("%d ",ele->data);
        while(ele!=NULL)
        {
            if(visited[ele->data]==0)
            {
                Enqueue(q,graph[ele->data]);
                visited[ele->data] = 1;
            }
            ele = ele->next;
        }
        int k = count_nodes(q);
        if(k==0)
            break;
    }
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



    //bfs
    Q q;
	q.rear = -1;
	q.front = -1;

	printf("Printing bfs: \n");
	int visitedbfs[100]={0};
	bfs(graph,0,visitedbfs,&q);
    printf("\n");

    return 0;
}