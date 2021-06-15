#include<stdio.h>
#include<stdlib.h>

#define MAX 50
typedef struct Node
{
    int data;
    struct Node* next;

}Node;

typedef struct
{
	int rear;
	int front;
	Node* q[MAX];
}Q;

void Enqueue(Q* q, Node* ele);
Node* Dequeue(Q* q);
int IsFull(Q* q);
int IsEmpty(Q* q);

int IsEmpty(Q* q)
{
	if(q->rear == -1 && q->front == -1)
	{
		return 1;
	}
	else
		return 0;
}
int isFull(Q* q)
{
	if(q->rear == MAX-1)
		return 1;
	else
		return 0;
}

void Enqueue(Q* q, Node* ele)
{
	if(isFull(q))
		return;
	if(IsEmpty(q))
	{
		//q->rear = 0;
		q->front = 0;
	}
	q->rear = q->rear+1;
	q->q[q->rear] = ele;
}
Node* Dequeue(Q* q)
{
	if(IsEmpty(q))
		return NULL;
	else
	{
		Node* ele = q->q[q->front];
		q->front =  q->front+1;
		return ele;
	}
}
int count_nodes(Q* q)
{
    /*printf("\n%d=count\n", (q->rear-q->front)+1);
    printf("Elements\n");
    for(int i = q->front; i <= q->rear; i++)
    {
        printf("%d ",q->q[i]->data);
    }
    printf("\n");*/
    return (q->rear-q->front)+1;
}
