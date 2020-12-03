#include<stdio.h>
#include<stdlib.h>

int findSmallest(int *arr, int n){
	int smallest = *arr;

	for(int i=0; i<n; i++){
		if(*(arr+i) < smallest){
			smallest = *(arr+i);
		}
	}

	return smallest;
}

int main(){
	int n;
	int *arr;

	printf("Enter the number of elements in the array:\n");
	scanf("%d", &n);

	arr = (int*)calloc(n, sizeof(int));

	for(int i =0; i<n; i++){
		scanf("%d", (arr+i));
	}

	printf("The smallest number in the array: %d\n", findSmallest(arr,n));

}