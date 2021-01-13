#include<stdio.h>

int count = 0;

int TOH(int n, int a, int b, int c){

	if(n!=0){
		count++;
		TOH(n-1, a, c, b);
		printf("Transferring disk %d from rod %d to rod %d using rod %d.\n", n, a, c, b);
		TOH(n-1, b, a, c);
	
	}
	return count;
}

int main(){
	int n;
	printf("Enter the number of disks:\n");
	scanf("%d", &n);

	int count = TOH(n, 1, 2, 3);

	printf("Total moves: %d.\n", count);
}