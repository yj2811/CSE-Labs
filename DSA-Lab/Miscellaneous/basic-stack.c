#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#define UNDERFLOW -999
#define true 1
#define false 0

typedef struct{
	int arr[MAX];
		int top;
}Stack;

int isEmpty(Stack *s){
	if(s->top == -1) return true;
	else return false;
}

int isFull(Stack *s){
	if(s->top == MAX-1) return true;
	else return false;
}

void push(Stack *s, int ele){
	if(!isFull(s)){
		s->arr[++s->top] = ele;
	}else{
		printf("Overflow.\n");
	}
}

int pop(Stack *s){
	if(!isEmpty(s)){
		return s->arr[s->top--];
	}else{
		printf("Stack is empty\n");
		return UNDERFLOW;
	}
}

void display(Stack *s){
	int i;
	for(int i=0; i<=s->top; i++){
		printf("%d\n", s->arr[i]);
	}
}

int main(){
	int i=0;
	Stack *s = (Stack*)malloc(sizeof(Stack));

	s->top = -1;

	char choice = '3';

	while(choice == '1' || choice == '2' || choice == '3'){


		printf("Enter 1 for Push, 2 for Pop, 3 for Display and anything else for exit:\n");
		fflush(stdin);
		scanf("%c", &choice);


		if (choice == '1') {
			int item;
			printf("\n\tEnter element to be pushed: ");
			scanf("%d", &item);
			push(s, item);
			
		}
		else if (choice == '2') {
			int item = pop(s);
			if (item != UNDERFLOW) {
				printf("\n\tPopped item = %d\n", item);
				
			}
		}
		else if (choice == '3') {
			printf("\nCurrent Stack: ");
			display(s);
		}
		else
			break;
	}
}