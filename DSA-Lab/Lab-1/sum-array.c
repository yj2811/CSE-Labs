#include<stdio.h>
#include<stdlib.h>

double add(n){

	double sum;

	double *ptr;

	ptr = (double*)calloc(n, sizeof(double));

	printf("Enter the elements of the array:");

	for(int i=0; i<n; i++){
		scanf("%lf", (ptr + i));
	}

	for(int i=0; i<n; i++){
		sum += *(ptr + i);
	}

	return sum;

}

int main() {

	int n;
	double sum;

	printf("Enter the size of the 1D array:\n");
	scanf("%d", &n);

	sum = add(n);

	printf("The sum of the array is: %lf\n", sum);

}