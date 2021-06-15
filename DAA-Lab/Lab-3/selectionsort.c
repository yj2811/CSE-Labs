#include<stdio.h>
#include<stdlib.h>

void selectionSort(int* arr, int n){
	int i, j, min, temp;
	int opcount=0;
	for(i=0; i<n-1; i++){
		min = i;
		for(j=i+1; j<n; j++){
			opcount++; // increment opcount for every comparison
			if(arr[j]<arr[min]){
				min = j;
			}
		}

		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}

	printf("Operation Count is %d\n", opcount);
}

int main(){
	int n;
	int *arr;
	printf("Enter the number of elements:\n");
	scanf("%d", &n);
	arr = (int*)calloc(n, sizeof(int));
	printf("Enter the elements of the array:\n");
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	selectionSort(arr, n);

	printf("After sorting:\n");

	for(int i=0; i<n; i++){
		printf("%d\t", arr[i]);
	}
}