#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int* arr, int n){
	int i, j, temp;
	int opcount=0;
	int flag = 0;

	for(i=0; i<n; i++){
		for(j=0; j<n-1-i; j++){
			opcount++; 
			if(arr[j+1]<arr[j]){
				flag=1;
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
		if(flag==0){
			printf("Operation Count is %d\n", opcount);
			return;
		}
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

	bubbleSort(arr, n);

	printf("After sorting:\n");

	for(int i=0; i<n; i++){
		printf("%d\t", arr[i]);
	}
}