#include<stdio.h>
#define MAX 10
#define true 1
#define false 0

typedef struct{
	char item[MAX];
		int top;
}Stack;

int empty(Stack *s){
	if (s->top==-1) return(true);
	else
	return(false);
}

void push(Stack* s, char ch){
	if(s->top != MAX-1){
		s->item[++s->top] = ch;
	}else{
		printf("Stack is full.");
	}
}

char pop(Stack* s){
	if(!empty(s)){
		return s->item[s->top--];
	}else{
		printf("Stack is empty.\n");
	}
}



int main(){
	char expn[20], c, d;
	int i=0;
	Stack s;
	s.top = -1;

	printf("Enter the expression:\n");
	scanf("%s", expn);

	while((c=expn[i++]) != '\0'){
		if(c=='('){
			push(&s, c);
		}else if(c==')'){
			d=pop(&s);

			if(d != '('){
				printf("Invalid expression.\n");
				break;
			}
		}
	}

	if(empty(&s)){
		printf("Balanced expression.\n");
	}else{
		printf("Not a Balanced expression.\n");
	}
}