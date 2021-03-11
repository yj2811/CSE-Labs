#include<stdio.h>

#define MAX 20
#define true 1
#define false 0

typedef struct{
	int x[MAX];
	int front;
	int rear;

} QUEUE;

void insertq(QUEUE*, int);
int deleteq(QUEUE*);
void displayq(QUEUE);

int isFull(QUEUE* q){
	if(q->rear == MAX){
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

void insertq(QUEUE* q, int x){
	if(isFull(q)){
		printf("Overflow :(\n");
	}else{
		q->x[++q->rear] = x;
		if(q->front == -1){
			q->front = 0;
		}
	}
}

int deleteq(QUEUE*q){
	if(isEmpty(q)){
		printf("Underflow :(\n");
	}else if(q->front == q->rear){
		int d = q->x[q->front];
		q->front = q->rear = -1;
		return d;
	}else{
		return q->x[q->front++];
	}
}

void displayq(QUEUE q){
	int i;
	if(isEmpty(&q)){
		printf("Empty queue.\n");
	}else{
		for(i=q.front; i<=q.rear; i++){
			printf("%d\n", q.x[i]);
		}
	}
}


int main(){
	QUEUE q;

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

	return 0;
}