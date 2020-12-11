import java.util.Scanner;

public class Prime{
	public static void main(String args[]){
		int n;
		Scanner sc = new Scanner(System.in);

		System.out.println("Enter the  number of elements:");

		n = sc.nextInt();

		int arr[] = new int[n]; //Dynamic allocation 

		System.out.println("Enter the elements:");

		for(int i=0; i<n; i++){
			arr[i] = sc.nextInt();
		}

		System.out.println("Printing the prime numbers in the array:");

		for(int i=0; i<n; i++){
			boolean flag = true;
			for(int j=2; j<=arr[i]/2; j++){
				if(arr[i]%j==0){
					flag = false;
				}
			}

			if(arr[i]==1){
				flag = false;
			}

			if(flag==true){
				System.out.print(arr[i] + "\t");
			}
		}

			System.out.println();
	}
}