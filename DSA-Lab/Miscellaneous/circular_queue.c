#include<stdio.h>

#define MAX 10
#define true 1
#define false 0

typedef struct{
	int x[MAX];
	int front;
	int rear;

} QUEUE;


int isFull(QUEUE* q){
	if((q->front == q->rear + 1) || (q->front == 0 && q->rear == MAX-1)){
		return true;
	}else{
		return false;
	}
}

int isEmpty(QUEUE* q){
	if(q->front == -1){
		return true;
	}else{
		return false;
	}
}

void enQueue(QUEUE* q, int x){
	if(isFull(q)){
		printf("Overflow (Queue is full) :(\n");
	}else{

		q->rear = (q->rear+1)%MAX;
		q->x[q->rear] = x;
		if(q->front == -1){
			q->front = 0;
		}
	}
}

int deQueue(QUEUE*q){
	if(isEmpty(q)){
		printf("Underflow :(\n");
		return -1;
	}else if(q->front == q->rear){
		int d = q->x[q->front];
		q->front = q->rear = -1;
		return d;
	}else{
		int d = q->x[q->front];
		q->front = (q->front + 1)%MAX;
		return d;
	}
}

void displayq(QUEUE* q){
	int i;

	if(isEmpty(q)){
		printf("Empty queue.\n");
	}else{
		for(i=q->front; i<=q->rear; i = (i+1)%MAX){
			printf("%d\t", q->x[i]);
		}
		
	}
}


int main(){
	QUEUE q;

	q.front = -1;
	q.rear = -1;

	int ch, x, flag=1;

	while(flag==1){
		printf("\n1. enQueue\n2. deQueue\n3. Display Queue\n4. Exit\n");
		scanf("%d", &ch);

		switch(ch){
			case 1:

			printf("Enter the Element:\n");
			scanf("%d",&x); 
			enQueue(&q,x);
			break;

			case 2:

			x=deQueue(&q); 
			printf("Removed %d from the Queue\n",x); 
			break;

			case 3:
			printf("Displaying the queue.\n");
			displayq(&q);
			break;

			case 4:

			flag=0;
			break;

			default:

			printf("Wrong choice! Try again!\n");
		}
	}

	return 0;
}