#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	int *arr;

	printf("Enter the number of elements in the array:\n");
	scanf("%d", &n);

	arr = (int*)calloc(n, sizeof(int));

	for(int i =0; i<n; i++){
		scanf("%d", (arr+i));
	}

	printf("Printing array in forward direction:\n");

	for(int i=0; i<n; i++){
		printf("%d\t",*(arr+i));
	}

	printf("\n");

	printf("Printing array in backward direction:\n");

	for(int i=0; i<n; i++){
		printf("%d\t", *(arr + n - 1 - i));
	}

	printf("\n");

}