#include<stdio.h>

int main(){
	int n;
	int xcoeff=0, ycoeff=0;
	int arr[20][2];

	printf("Enter the number of polynomials:\n");
	scanf("%d", &n);

	printf("Enter the polynomials:\n");
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i][0]);
		scanf("%d", &arr[i][1]);
	}

	for(int i=0; i<n; i++){
		printf("%dx + ", arr[i][0]);
		printf("%dy\n", arr[i][1]);
	}

	printf("Adding the polynomials:\n");
	for(int i=0; i<n; i++){
		xcoeff += arr[i][0];
		ycoeff += arr[i][1];
	}

	printf("Result: %dx + %dy\n", xcoeff, ycoeff);

	// printf("Multiplying the polynomials:\n");
	// ???

}