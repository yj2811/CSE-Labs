#include<stdio.h>

int* smaller(int* px, int* py){
	return (*px < *py ? px : py);
}

int main(){
	int a;
	int b;

	int **ptr;

	printf("Enter the two numbers:\n");
	scanf("%d %d", &a, &b);

	*ptr = smaller(&a, &b);

	printf("The smallest of the two numbers is %d.", **ptr);

}