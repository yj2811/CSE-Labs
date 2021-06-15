#include<stdlib.h>
#include<stdio.h>

int main(){
	int a, b;
	printf("Enter the two numbers for GCD:\n");
	scanf("%d %d", &a, &b);

	int ans = GCDMS(a, b);
	printf("The GCD of %d and %d is %d.", a, b, ans);
}

int GCDMS(int a, int b){
	if(a<b){
		GCDMS(b,a);
	}

	int fact=2;
	int gcd=1;
	int z=b;
	
	for(fact=2; fact<=z; fact++){
		while((a%fact==0) && (b%fact==0)){
			gcd= gcd*fact;
			b = b/fact;
			a = a/fact;
			if(a==0 || b==0){
				return 0;
			}
		}
	}
	return gcd;
}