#define MAX 100

typedef struct node* NodePtr;

typedef struct{
	NodePtr Queue[MAX];
	int Front;
	int Rear;
}QUEUE;


int isEmptyQueue(QUEUE *q){
	return q->Front == -1;
}

int isFullQueue(QUEUE *q){
	return q->Rear == MAX-1;
}

void InsertQ(QUEUE *q, NodePtr x){
	//already coming as a pointer, no need to use &
	if(isFullQueue(q)){
		printf("Queue overflow\n");
		return;
	}else{
		q->Queue[++q->Rear]=x;
	}
}

NodePtr DeleteQ(QUEUE *q){
	//already coming as a pointer, no need to use &
	if(isEmptyQueue(q)){
		printf("Queue underflow\n");
		return NULL;
	}else{
		return q->Queue[q->Front++];
	}
}
