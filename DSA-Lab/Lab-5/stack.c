#include<stdio.h>
#define MAX 10
#define UNDERFLOW '\0'
#define true 1
#define false 0

typedef struct{
	char item[MAX];
		int top;
}STACK;

int isEmpty(STACK *s){
	if (s->top==-1) return true;
	else return false;
}

int isFull(STACK *s){
	if(s->top == MAX-1){
		return true;
	}else return false;
}

void push(STACK* s, char ch){
	if(!isFull(s)){
		s->item[++s->top] = ch;
	}else{
		printf("Stack is full.\n");
	}
}

char pop(STACK* s){
	if(!isEmpty(s)){
		return s->item[s->top--];
	}else{
		printf("Stack is empty.\n");
		return UNDERFLOW;
	}
}

void display(STACK *s){
	int i;
	for(i=0; i<s->top; i++){
		printf("%c\n", s->item[i]);
	}
}

int main(){

	int i=0;
	STACK s;
	s.top = -1;
	char choice = '3';

	while (choice == '1' || choice == '2' || choice == '3') {

		printf("Enter 1 for Push, 2 for Pop, 3 for Display and anything else for exit:\n");
		scanf("%c", &choice);

		if (choice == '1') {
			char item;
			printf("\n\tEnter element to be pushed: ");
			scanf("%c", &item);
			push(&s, item);
			
		}
		else if (choice == '2') {
			char item = pop(&s);
			if (item != UNDERFLOW) {
				printf("\n\tPopped item = %c\n", item);
				
			}
		}
		else if (choice == '3') {
			printf("\nCurrent Stack: ");
			display(&s);
		}
		else
			break;
		
	}

}