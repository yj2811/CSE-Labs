#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int opcount1=0;
int opcount2=0;
int opcount3=0;

int* Sieve(int n){
	int p, j, *A, *L;
	A = (int*)malloc(sizeof(int)* 1024);
	L = (int*)malloc(sizeof(int)* 9);

	for(int p=2; p<=n; p++){
		A[p] = p;
	}

	for(int p=2; p*p<n; p++){
		opcount1++;
		if(A[p] != 0){
			j = p*p;
			while(j<=n){
				A[j] = 0;
				j = j+p;
			}
		}
	}

	int i=0;
	for(p=2; p<=n; p++){
		if(A[p]!=0){
			L[i] = A[p];
			i++;
		}
	}
	// Returns the first 9 prime numbers
	return L;
}

int* Divide(int m, int* Prime){
	int* PrimeFactor, i;
	PrimeFactor = (int*)malloc(sizeof(int)*4);


	for (int i = 0; i < 4; i++){
		PrimeFactor[i] = -1;
	}

	opcount2=0;
	i=0;
	int j=0;
	while(m>0 && Prime[j] != 0 && i<4){
		opcount2++;
		while(m%Prime[j] == 0 && i<4){
			PrimeFactor[i] = Prime[j];
			i++;
			m = m/Prime[j];
		}
		j++;
	}
	return PrimeFactor; 
}

int MSGCD(int m, int n){
	int *PrimesM, *PrimesN, *PrimeFactorsM, *PrimeFactorsN, *CommonFactors;

	PrimesM = (int*) malloc(sizeof(int) * 9);

	PrimesN = (int*) malloc(sizeof(int) * 9);

	PrimeFactorsM = (int*) malloc(sizeof(int) * m);

	PrimeFactorsN= (int*) malloc(sizeof(int) * n); 

	CommonFactors = (int*) malloc(sizeof(int) * 3);

	PrimesM = Sieve(m);
	PrimesN = Sieve(n);


	for (int i = 0; i < 9; i++){

		printf("Prime Number=%d\n", PrimesM[i]); 
	}

	PrimeFactorsM = Divide (m, PrimesM);

	// 4 prime factors.

	for (int i = 0; i < 4; i++){

		printf("Prime Factor of M=%d\n", PrimeFactorsM[i]); 
	}
	
	PrimeFactorsN = Divide(n, PrimesN);

	for (int i = 0; i < 4; i++){
		printf("Prime Factor of N=%d\n", PrimeFactorsN[i]); 
	}
	int k=0;
	opcount3=0;
	for(int i=0, j=0; i<4 && j<4;){
		opcount3++;
		if(PrimeFactorsM[i] > PrimeFactorsN[j]) j++;
		if(PrimeFactorsM[i] < PrimeFactorsN[j]) i++;
		else if(PrimeFactorsM[i] == PrimeFactorsN[j]){
			CommonFactors[k] = PrimeFactorsM[i];
			k++;
			i++;
			j++;
		}
	}
	for(int i=0; i<4; i++){
		printf("CommonFactors = %d\n", CommonFactors[i]);
	}

	int gcd = 1;
	for(int i=0; i<k; i++){
		gcd*= CommonFactors[i];
	}

	if(opcount3 > opcount2 && opcount3 > opcount1){
		printf("Opcount3 = %d\n", opcount3);
	}else if(opcount2 > opcount3 && opcount2 > opcount1){
		printf("Opcount2 = %d\n", opcount2 + opcount1);
	}else printf("Opcount1 = %d\n", opcount1);

	return gcd;
}

int main(){
	int m, n;
	printf("Enter the value of m and n: \n");
	scanf("%d %d", &m, &n);
	printf("Ans = %d\n", MSGCD(m,n));
}