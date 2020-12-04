#include<stdio.h>
#include<stdlib.h>

int main(){
	int rows, cols, i;
	int** table;

	printf("Enter the number of rows:\n");
	scanf("%d", &rows);

	table = (int**)calloc(rows+1, sizeof(int*));

	for(i=0; i<rows; i++){
		printf("Enter size of row %d:\n", i+1);
		scanf("%d", &cols);

		table[i] = (int*)calloc(cols+1, sizeof(int));

		printf("Enter elements of row %d:\n", i+1);

		for(int j=1; j<=cols; j++){
			scanf("%d", &table[i][j]);
		}

		table[i][0] = cols;
		printf("Size of row number %d is %d.\n",i+1, table[i][0]);
	}

	table[i] = NULL;

	// Printing the elements of the matrix

	for(i=0; i<rows; i++){
		printf("Displaying elemnts of row %d:\n", i+1);

		for(int j=0; j<=*table[i]; j++){
			printf("%d\t", table[i][j]);
		}

		printf("\n");
	}

	// Do not forget to deallocate the memory

	for(int i=0; i<rows; i++){
		free(table[i]);
	}
}