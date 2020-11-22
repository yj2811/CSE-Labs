#include<stdio.h>

void swap(int arr[], int a, int b){
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void selectionSort(int arr[], int n){

	int min, i, j;

	for(i=0; i<n-1; i++){
		min = i;
		for(j=i+1; j<n; j++){
			if(arr[j] < arr[min]){
				min = j;
			}
		}

		if(min != i){
			swap(arr, i, min);
		}
	}
}

int main() {

	int n;

	printf("Enter the value of n:\n");
	scanf("%d", &n);

	int arr[n];

	printf("Enter the elements of the array:\n");

	for(int i=0; i<n; i++){

		scanf("%d", &arr[i]);
	}

	selectionSort(arr, n);

	printf("The sorted array using selection sort is:\n");

	for(int i=0; i<n; i++){
		printf("%d\n", arr[i]);
	}

}