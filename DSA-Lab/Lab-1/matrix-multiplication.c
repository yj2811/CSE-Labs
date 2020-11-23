#include<stdio.h>
#include<stdlib.h>




void printMatrix(int**matrix, int rows, int cols){


	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}



void matrixMultiplication(int** matrix1, int** matrix2, int rows1, int cols1, int rows2, int cols2){
	
	int **result;

	if(cols1 != rows2){
		printf("Invalid multiplication");

	}else{

	

		result = (int**)calloc(rows1, sizeof(int*));

		for(int i=0; i<cols2; i++){
			result[i] = (int*)calloc(cols2, sizeof(int*));
		}

		for(int i=0; i<rows1; i++){
			for(int j=0; j<cols2; j++){
				for(int k=0; k<cols1; k++){
					result[i][j] += matrix1[i][k] * matrix2[k][j];
				}
			}
		}

	

		printf("Printing result of multiplication:\n");

		for(int i=0; i<rows1; i++){
			for(int j=0; j<cols2; j++){
				printf("%d\t", result[i][j]);
			}
				printf("\n");
		}
	}
	
}



int main(){
	int rows1, cols1, rows2, cols2, i, j;

	int **matrix1;
	int **matrix2;
	

	printf("Number of rows for Matrix 1:\n");
	scanf("%d", &rows1);

	printf("Number of columns for Matrix 1:\n");
	scanf("%d", &cols1);

	printf("Number of rows for Matrix 2:\n");
	scanf("%d", &rows2);

	printf("Number of columns for Matrix 2:\n");
	scanf("%d", &cols2);

	matrix1 = (int**)calloc(rows1, sizeof(int*));
	matrix2 = (int**)calloc(rows2, sizeof(int*));



	printf("Scaning elements of Matrix 1:\n");

	for(i=0; i<rows1; i++){
		matrix1[i] = (int*)calloc(cols1, sizeof(int));

	}

	printf("Enter the elements for Matrix 1:\n");

	for(i=0; i<rows1; i++){
		for(j=0; j<cols1; j++){
			scanf("%d", &matrix1[i][j]);
		}

	}

	printf("Scanning elements of Matrix 2:\n");

	for(i=0; i<rows2; i++){
		matrix2[i] = (int*)calloc(cols2, sizeof(int));

	}

	printf("Enter the elements for Matrix 2:\n");

	for(i=0; i<rows2; i++){
		for(j=0; j<cols2; j++){
			scanf("%d", &matrix2[i][j]);
		}

	}


	printf("Printing Matrix 1:\n");
	printMatrix(matrix1, rows1, cols1);

	printf("Printing Matrix 2:\n");
	printMatrix(matrix2, rows2, cols2);


	
	printf("Multiplying the matrices:");
	matrixMultiplication(matrix1, matrix2, rows1, cols1, rows2, cols2);


}