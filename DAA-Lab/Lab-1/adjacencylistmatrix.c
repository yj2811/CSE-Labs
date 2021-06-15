#include <stdio.h>
#include <stdlib.h>

// a normal node of a linked list
struct AdjListNode {
    int dest;
    struct AdjListNode* next; 
};

// a linked list with head for identification
struct AdjList {
    struct AdjListNode *head; 
};

// graph with number of vertices and array of linked lists
struct Graph {
    int V;
    struct AdjList* array; 
};

// creates a new node for a particular linked list in the array of linked lists
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode =(struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// initialises a graph for v vertices
struct Graph* createGraph(int V) {
    int  i;
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
    for (i = 0; i < V; ++i)
    graph->array[i].head = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    // first place
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // second place
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode; 

}

void printGraph(struct Graph* graph) {
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v); 
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;  
        }
        printf("\n"); 
    }
}
//int N, M;
void createAdjMatrix(int arr[][2],int N,int M,int Adj[][N + 1]) {
    int i,j;
    for (i= 0; i < N ; i++)
        for (j = 0; j < N ; j++)
            Adj[i][j] = 0;

    for (i = 0; i < M; i++) {
        int x = arr[i][0];
        int y = arr[i][1]; 
        Adj[x][y] = 1;
        Adj[y][x] = 1;
    } 
}


void printAdjMatrix(int N,int Adj[][N + 1]) {
    int i,j;
    for (i = 0; i < N ; i++)
    { 
        for (j = 0; j < N ; j++)
            printf("%d ", Adj[i][j]); printf("\n");
    } 
}
int main() {
    int N,m,i;

    printf("\nEnter no. of vertices: ");
    scanf("%d",&N);
    printf("\nEnter no. of edges: ");
    scanf("%d",&m);
    int arr[m][2] ;
    for(i=0;i<m;i++){
        printf("\nEnter source and destination for edge %d (0 indexed please):",i+1);
        scanf("%d %d",&arr[i][0],&arr[i][1]);
    }

    int M = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n",M);
    int Adj[N + 1][N + 1];
    createAdjMatrix(arr,N,M,Adj);
    printAdjMatrix(N,Adj);
    struct Graph* graph = createGraph(N);
    for(i=0;i<m;i++){
        addEdge(graph,arr[i][0],arr[i][1]);
    }
    printGraph(graph);
    return 0;

}