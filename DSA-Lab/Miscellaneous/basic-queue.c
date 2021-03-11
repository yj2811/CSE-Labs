#include<stdio.h>
#include<stdlib.h>
#define UNDERFLOW -999
#define MAX 10
#define true 1
#define false 0

typedef struct{
	int arr[MAX];
	int front;
	int rear;

}Queue;

int isEmpty(Queue* q){
	if(q->front == -1) return true;
	else return false;
}

int isFull(Queue *q){
	if(q->rear == MAX -1) return true;
	else return false;
}

void insertq(Queue *q, int x){
	if(isFull(q)){
		printf("Overflow\n");
	}else{
		q->arr[++q->rear] = x;
		if(q->front == -1){
			q->front=0;
		}
	}
}

int deleteq(Queue *q){
	if(isEmpty(q)){
		printf("UNDERFLOW\n");
		return UNDERFLOW;
	}else if(q->front == q->rear){
		int d = q->arr[q->front];
		q->front = q->rear = -1;
		return d;
	}else{
		return q->arr[q->front++];
	}
}

void displayq(Queue q){
	int i;
	if(isEmpty(&q)){
		printf("Empty queue.\n");
	}else{
		for(i=q.front; i<=q.rear; i++){
			printf("%d\n", q.arr[i]);
		}
	}
}

int main(){
	Queue q;

	q.front = -1;
	q.rear = -1;

	int ch, x, flag=1;


	while(flag==1){
		printf("1. Insert Queue\n2. Delete Queue\n3. Display Queue\n4. Exit\n");
		scanf("%d", &ch);

		switch(ch){
			case 1:

			printf("\nEnter the Element:");
			scanf("%d",&x); 
			insertq(&q,x);
			break;

			case 2:

			x=deleteq(&q); 
			printf("\nRemoved %d from the Queue\n",x); 
			break;

			case 3:
			displayq(q);
			break;

			case 4:

			flag=0;
			break;

			default:

			printf("\n Wrong choice! Try again!");
		}
	}
}

// Practice:


// copy func:

// temp mein data lo 
// end mein return temp

// if null return  null

// 	temp->lchild = copy(root->lchild);
// 	temp->rchild = copy(root->rchild);

// BST
// null
// item>
// item<
// no dup. recursive.

// BST Search
// null, root, recursive, rootl, rootr

// iterative also







