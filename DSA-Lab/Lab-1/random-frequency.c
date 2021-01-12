#include<stdio.h>
#include<stdlib.h>

int main(){

	int n;

	printf("Enter the size of the array:\n");
	scanf("%d", &n);

	int arr[n];
	int freq[n];
	int count;

	for(int i=0; i<n; i++){
		arr[i] = rand()%200 - 100;
		freq[i] = -1;
	}

	for(int i=0; i<n; i++){
		printf("%d\n", arr[i]);
	}

	for(int i=0; i<n; i++){
		count = 1;
		

		// If frequency of the current element is not yet counted.
		if(freq[i] != 0){
			

			for(int j = i+1; j<n; j++){
			if(arr[i] == arr[j]){

			count++;
			freq[j] = 0; // Making sure not to count the frequency of the same element again.

				}
			
			}

			freq[i] = count;
		}
	}

	printf("Frequency of all elements in the array:\n");
	for(int i=0; i<n; i++){
		if (freq[i] != 0){
			printf("Frequency of %d is: %d\n", arr[i], freq[i]);
		}
	}


}

