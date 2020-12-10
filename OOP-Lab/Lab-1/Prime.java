import java.util.Scanner;

public class Prime{

	static boolean isPrime(int n){
		boolean ans = true;
		for(int i=2; i<n; i++){
			if(n%i==0){
				ans = false;
				return ans;
			}
		}

		return ans;
	}

	public static void main(String args[]){

		System.out.println("Enter the number:");

		Scanner sc = new Scanner(System.in);

		int num = sc.nextInt();

		if(isPrime(num)){
			System.out.println(num + " is a prime number.");
		}else{
			System.out.println(num + " is not a prime number.");
		}

		System.out.println("Enter N:");

		int n = sc.nextInt();

		System.out.println("The first " + n + " prime numbers are:" );

		int count=0;
		int p=2;

		while(count<=n){
			
			if(isPrime(p)){
				count++;
				System.out.println(p);
			}

			p++;
		}

	}
}