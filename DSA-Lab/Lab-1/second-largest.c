#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

void secondLargest(int* arr, int n){

	if(n<2){
		printf("Invalid input");
	}

	int first, second, i;

	first = second = INT_MIN;

	for(i=0; i<n; i++){
		if(arr[i]>first){
			second = first;
			first = arr[i];
		}else if(arr[i]>second){
			second = arr[i];
		}
	}

	printf("The second largest element is: %d\n", second);

}



int main(){
	int n;
	int *arr;

	printf("Enter the size of array:\n");
	scanf("%d", &n);

	arr = (int*)calloc(n, sizeof(int));

	printf("Enter the elements of the array:\n");

	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	secondLargest(arr, n);
}