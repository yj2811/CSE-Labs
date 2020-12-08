import java.util.Scanner;

public class Largest{

	static int largestOfThree(int n1, int n2, int n3){
		int ans;

		ans = (n1>n2)?((n1>n3)?n1:n3):((n2>n3)?n2:n3);

		return ans;
	}

	public static void main(String args[]){
		int n1, n2, n3, ans;

		System.out.println("Enter the 3 numbers:");

		Scanner sc = new Scanner(System.in);

		n1 = sc.nextInt();
		n2 = sc.nextInt();
		n3 = sc.nextInt();

		// Calling a static method from same class, no need for object.
		ans = largestOfThree(n1, n2, n3);

		System.out.println("The largest number is:" + ans);

	}

 }