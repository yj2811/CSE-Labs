// Knapsack using brute force
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int Knapsack(int *val, int *wt, int n, int c){
	int subsetNum = (1<<n);
	int maxSequence = 0;
	int maxVal = 0;
	int opcount = 0;

	for(int i=0; i<subsetNum; i++){
		int totalWeight  = 0;
		int totalValue = 0;
		opcount++;
		for(int j=0; j<n; j++){
			
			if((i&(1<<j)) != 0){
				totalWeight += wt[j];
				totalValue += val[j];
			}
		}

		if(totalWeight <= c && totalValue > maxVal){
			maxVal = totalValue;
			maxSequence = i;
		}
	}

	printf("Opcount = %d\n", opcount);
	return maxSequence;
}

int main(){
	int n, c;
	int val[10];
	int wt[10];

	printf("Enter the number of items:\n");
	scanf("%d", &n);

	printf("Enter the values (array)\n");
	for(int i=0; i<n; i++){
		scanf("%d", &val[i]);
	}

	printf("Enter the weights (array)\n");
	for(int i=0; i<n; i++){
		scanf("%d", &wt[i]);
	}

	printf("Enter the capacity:\n");
	scanf("%d", &c);
	int knaps=0;

	knaps = Knapsack(val, wt, n, c);
	printf("Knaps = %d\n", knaps);

	for(int i=0; i<n; i++){
		if((knaps & (1<<i)) != 0){
			printf("Item %d with value %d\n", i+1, val[i]);
		}
	}
}