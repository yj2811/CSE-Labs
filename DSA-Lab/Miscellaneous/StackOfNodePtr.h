#define MAX 100

typedef struct node* NodePtr;

typedef struct{
	NodePtr Stack[MAX];
	int top;
}STACK;

int isEmptyStack(STACK *s){
	if(s->top == -1)
		return 1;
	else
		return 0;
}

int isFullStack(STACK *s){
	if(s->top == MAX-1){
		return 1;
	}else{
		return 0;
	}
}

void Push(STACK *s, NodePtr x){
	//already coming as a pointer, no need to use &
	if(isFullStack(s)){
		printf("Stack overflow\n");
		return;
	}else{
		s->Stack[++s->top]=x;
	}
}

NodePtr Pop(STACK *s){
	//already coming as a pointer, no need to use &
	if(isEmptyStack(s)){
		printf("Stack underflow\n");
		return NULL;
	}else{
		return s->Stack[s->top--];
	}
}