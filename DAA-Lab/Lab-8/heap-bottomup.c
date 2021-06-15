#include<stdio.h>
int opcount =0;

void heapify(int h[], int n){
	int i, k, v, heapify, j;

	for(i=n/2; i>=1; i--){
		k=i;
		v=h[k];
		heapify=0;

		while(heapify==0 && 2*k <= n){
			opcount++;
			j = 2*k;
			if(j<n){
				if(h[j]<h[j+1]) j++;
			}
			if(v>=h[j]) heapify = 1;
			else{
				h[k] = h[j];
				k=j;
			}
		}
		h[k] = v;
	}

	return;
}

int main(){
	int h[20], i, n;
	printf("Enter the number of elements:\n");
	scanf("%d", &n);

	printf("Enter the elements\n");
	for(int i=1; i<=n; i++){
		scanf("%d", &h[i]);
	}

	heapify(h, n);
	printf("The heap created:\n");

	for(int i=1; i<=n; i++){
		printf("%d  ", h[i]);
	}
	printf("\nOpcount: %d\n", opcount);
	printf("=\n");
}