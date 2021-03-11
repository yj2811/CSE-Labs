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


void enQueueR(QUEUE* q, int x){
	if(isFull(q)){
		printf("Overflow (Queue is full) :(\n");
	}else{
		if(q->front == -1){
			q->front = 0;
			q->rear = 0;
		}else if(q->rear == MAX-1){
			q->rear = 0;
		}else{
			q->rear = q->rear + 1;
		}

		q->x[q->rear] = x;
	}
}

void enQueueF(QUEUE* q, int x){
	if(isFull(q)){
		printf("Overflow (Queue is full) :(\n");
	}else{
		if(q->front == -1){
			q->front = 0;
			q->rear = 0;
		}else if(q->front == 0){
			q->front = MAX-1;
		}else{
			q->front = q->front-1;
		}

		q->x[q->front] = x;
	}
}

int deQueueR(QUEUE*q){
	if(isEmpty(q)){
		printf("Underflow :(\n");
		return -1;
	}else if(q->front == q->rear){
		int d = q->x[q->front];
		q->front = q->rear = -1;
		return d;
	}else if(q->rear == 0){
		int d = q->x[q->rear];
		q->rear = MAX-1;
		return d;
	}else{
		int d = q->x[q->rear];
		q->rear = (q->rear - 1);
		return d;
	}
}

int deQueueF(QUEUE*q){
	if(isEmpty(q)){
		printf("Underflow :(\n");
		return -1;
	}else if(q->front == q->rear){
		int d = q->x[q->front];
		q->front = q->rear = -1;
		return d;
	}else if(q->front == MAX-1){
		int d = q->x[q->front];
		q->front = 0;
		return d;
	}else{
		int d = q->x[q->front];
		q->front = (q->front + 1);
		return d;
	}
}


void displayq(QUEUE* q){
	int i;

	if(isEmpty(q)){
		printf("Empty queue.\n");
	}else{
		if(q->front <= q->rear){
			for(i=q->front; i<=q->rear; i = i+1){
			printf("%d\t", q->x[i]);
			}
		}else{
			while(front<=MAX-1)
			  {
			   printf("%d\t",deque[front]);
			   front++;
			  }
			  front=0;
			  while(front<=rear)
			  {
			   printf("%d\t",deque[front]);
			   front++;
			  }
		}
		
	}


}


int main(){
	QUEUE q;

	q.front = -1;
	q.rear = -1;

	int ch, x, flag=1;

	while(flag==1){
		printf("\n1.enQueueR\n 2.enQueueF\n3.deQueueR\n 4.deQueueF\n 5.Display Queue\n6.Exit\n");
		scanf("%d", &ch);

		switch(ch){
			case 1:

			printf("Enter the Element:\n");
			scanf("%d",&x); 
			enQueueR(&q,x);
			break;

			case 2:

			printf("Enter the Element:\n");
			scanf("%d",&x); 
			enQueueF(&q,x);
			break;

			case 3:

			x=deQueueR(&q); 
			printf("Removed %d from the Queue from rear.\n",x); 
			break;

			case 4:

			x=deQueueF(&q); 
			printf("Removed %d from the Queue from front.\n",x); 
			break;

			case 5:
			printf("Displaying the queue.\n");
			displayq(&q);
			break;

			case 6:

			flag=0;
			break;

			default:

			printf("Wrong choice! Try again!\n");
		}
	}

	return 0;
}