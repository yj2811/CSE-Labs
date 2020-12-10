import java.util.Scanner;

public class ArrayReadDisplay{
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

		System.out.println("Printing the array:");

		for(int i=0; i<n; i++){
			System.out.println(arr[i]);		}
	}
}