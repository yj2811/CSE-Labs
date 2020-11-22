#include<stdio.h>
#include<stdbool.h>

void Lsearch(int arr[], int n, int element){

	bool found = false;
	int pos;

	for(int i=0; i<n; i++){
			if(arr[i] == element){
				found = true;
				pos = i;
				break;
		}
	}

	if(found){
		printf("%d is found in position %d.", element, pos+1);
	}else{
		printf("%d is not found.", element);
	}
}

int main(){

	int n, element;

	printf("Enter the value of n:\n");
	scanf("%d", &n);

	int arr[n];

	printf("Enter the values of the array:\n");

	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	printf("Enter the value of the element:\n");
	scanf("%d", &element);

	Lsearch(arr, n, element);

}
