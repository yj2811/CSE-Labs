#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int opcount1;
int opcount2;
int opcount3;

int EuclidGCD(int m, int n){
	int r;
	int opcount=0;
	while(n != 0){
		opcount++;
		r = m%n;
		m=n;
		n=r;
	}

	printf("Operation count Euclid's Method = %d\n", opcount);
	return m;
}

int consecutiveIntegerGCD(int m, int n){
	int t = m > n ? n : m;
	int opcount = 0;
	while(t>0){
		if(m%t == 0){
			if(n%t == 0){
				printf("Operation count Consecutive Integer Method = %d\n", opcount);
				return t;
			}
		}
		t = t-1;
		opcount++;
	}
}



int Sieve(int x, int* x_arr, int opcount)
{
  int i;
  for(i=0; i<x; i++)
    x_arr[i]=0;

  x_arr[0]=-1;
  x_arr[1]=-1;

  for(i=2; i<x; i++)
  {
    if(x_arr[i]==0)
    {
      int mult;
      for(mult=i*i; i*mult<x; mult++)
      {
        x_arr[i*mult]=1;
        opcount++;
      }
    }
  }

  return opcount;
}

unsigned int MiddleSchoolGCD(int m, int n)
{
  int *m_arr=calloc(m, sizeof(int));
  int *n_arr=calloc(n, sizeof(int));
  int i;
  int opcount_sieve=0;
  int opcount_factorisation=0;
  int opcount_GCD=0;
  int gcd=1;
  int opcount;

  opcount_sieve = Sieve(m, m_arr, opcount_sieve);
  opcount_sieve = Sieve(n, n_arr, opcount_sieve);

  for(i=2; i<m; i++)
    if(m_arr[i]==0)
    {
      opcount_factorisation++;
      m_arr[i]=(m%i!=0)?1:0;
    }

  for(i=2; i<n; i++)
    if(n_arr[i]==0)
    {
      opcount_factorisation++;
      n_arr[i]=(n%i!=0)?1:0;
    }

  printf("Prime factors of %d: ", m);
  for(i=2; i<m; i++)
  {
    if(m_arr[i]==0)
      printf("%d ", i);
  }
  printf("\n");

  printf("Prime factors of %d: ", n);
  for(i=2; i<n; i++)
  {
    if(n_arr[i]==0)
      printf("%d ", i);
  }
  printf("\n");

  int ii;
  for(i=2; i<m; i++)
  {
    for(ii=i; ii<n; ii++)
    {
      if(m_arr[i]==n_arr[ii]&&m_arr[i]==0)
        if(i==ii)
        {
          gcd*=i;
          opcount_GCD++;
        }
    }
  }

  if (opcount_sieve >= opcount_factorisation)
  {
    if (opcount_sieve >= opcount_GCD)
        opcount=opcount_sieve;
    else
        opcount=opcount_GCD;
  }
  else
  {
    if (opcount_factorisation >= opcount_GCD)
        opcount=opcount_factorisation;
    else
        opcount=opcount_GCD;
  }
  
  printf("Middle School Operation count=%d\n", opcount);
  return(gcd);
}

int main(){
	int a, b;
	printf("Enter the two numbers for GCD:\n");
	scanf("%d %d", &a, &b);

	int ans1 = EuclidGCD(a, b);
	printf("The GCD of %d and %d using Euclid's algorithm is %d.", a, b, ans1);

	int ans2 = consecutiveIntegerGCD(a, b);
	printf("The GCD of %d and %d using Consecutive Integer algorithm is %d.", a, b, ans2);

	int ans3 = MiddleSchoolGCD(a,b);
	printf("The GCD of %d and %d using Middle School algorithm is %d.", a, b, ans3);

}

