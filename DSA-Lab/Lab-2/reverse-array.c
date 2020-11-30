#include<stdio.h>

int main(){
	int n;

	int arr[20];

	printf("Enter the number of elements in the array:\n");
	scanf("%d", &n);


	//Using pointers

	int* pwalk;
	int* pend;

	printf("Enter the elements:\n");
	for(pwalk=arr, pend=arr+n; pwalk<pend; pwalk++){
		scanf("%d", pwalk);
	}

	printf("Printing the elements of the array:\n");
	for(pwalk=arr, pend=arr+n; pwalk<pend; pwalk++){
		printf("%d", *pwalk);
	}
	printf("\n");

	for(pwalk=arr, pend=arr+n-1; pwalk < pend; pwalk++, pend--){
		int temp = *pwalk;
		*pwalk = *pend;
		*pend = temp;
	}

	printf("Printing the elements of the array after reversing:\n");
	for(pwalk=arr, pend=arr+n; pwalk<pend; pwalk++){
		printf("%d", *pwalk);
	}
	printf("\n");

}


