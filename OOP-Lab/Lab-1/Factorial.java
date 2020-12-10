import java.util.Scanner;

public class Factorial{

	static int fact(int n){
		if(n==1){
			return 1;
		}

		return n*fact(n-1);

	}

	public static void main(String args[]){
		System.out.println("Enter the value of N and R:");

		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int r = sc.nextInt();

		int ans = fact(n);

		System.out.println("The factorial of the n is: " + ans);

		int nCr = fact(n)/(fact(r)*fact(n-r));

		System.out.println("The value of nCr is: " + nCr);
	}
}