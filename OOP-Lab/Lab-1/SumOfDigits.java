import java.util.Scanner;

public class SumOfDigits{

	static void sum(int n){
		int temp = n;
		int sum=0;

		while(temp>0){
			int k = temp%10;
			sum += k;
			temp /= 10;
		}
			System.out.println("Sum of digits is " + sum);
		
	}

	public static void main(String args[]){
		System.out.println("Enter a number:");

		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();

		sum(n);
	}
}