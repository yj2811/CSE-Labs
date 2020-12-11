import java.util.Scanner;

public class LinearSearch{


	static int linearSearch(int arr[], int ele, int n){
		int pos;
		for(int i=0; i<n; i++){
			if(arr[i]==ele){
				pos = i+1;
				return pos;
			}
		}

		return -1;
	}

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
			System.out.println(arr[i]);		
		}

		System.out.println("Enter the element to be searched:");

		int ele = sc.nextInt();

		int pos = linearSearch(arr, ele, n);

		if(pos==-1){
			System.err.println("Not found");
		}else{
			System.out.println(ele + " found at " + pos);
		}
	}
}