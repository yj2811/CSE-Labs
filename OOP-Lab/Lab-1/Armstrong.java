import java.util.Scanner;

public class Armstrong{
	static void isArmstrong(int n){
		int temp = n;
		int sum=0;

		while(temp>0){
			int k = temp%10;
			sum += k*k*k;
			temp /= 10;
		}

		if(sum==n){
			System.out.println("Armstrong");
		}else{
			System.out.println("Not Armstrong");
		}
	}
	public static void main(String args[]){

		System.out.println("Enter a number:");

		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();

		isArmstrong(n);
	}
}