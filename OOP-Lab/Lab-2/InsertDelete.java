import java.util.Scanner;

public class InsertDelete{

	static void printArray(int arr[], int n){
		System.out.println("Printing the array:");

		for(int i=0; i<n; i++){
			System.out.println(arr[i]);		
		}
	}


	static void insert(int arr[], int n){
		Scanner sc = new Scanner(System.in);
		int a[] = new int[n+1];

		System.out.println("Enter the element and the position:");

			int ele = sc.nextInt();
			int p = sc.nextInt();

			while(p>n || p<0){
				System.err.println("Index out of bounds error, try again.\n Enter the new position:");
				p = sc.nextInt();
			}

		for(int i=0; i<n+1; i++){
			if(i<p-1){
				a[i] = arr[i];
			}else if(i==p-1){
				a[i] = ele;
			}else{
				a[i]= arr[i-1];
			}
		}

		printArray(a, n+1);

	}

	static void delete(int arr[], int n){
		Scanner sc = new Scanner(System.in);
		int a[] = new int[n-1];

		System.out.println("Enter the position of the element to be deleted:");

			int p = sc.nextInt();

		while(p>n || p<0){
			System.err.println("Index out of bounds error, try again.\n Enter the new position:");
			p = sc.nextInt();
		}

		for(int i=0; i<n-1; i++){
			if(i<p-1){
				a[i] = arr[i];
			}else{
				a[i] = arr[i+1];
			}
		}

		printArray(a, n-1);

	}


	public static void main(String args[]){
		int n, p, ele;
		Scanner sc = new Scanner(System.in);

		System.out.println("Enter the  number of elements:");

		n = sc.nextInt();

		int arr[] = new int[n]; //Dynamic allocation 

		System.out.println("Enter the elements:");

		for(int i=0; i<n; i++){
			arr[i] = sc.nextInt();
		}

		printArray(arr, n);

		System.out.println("Enter 1 for insertion or 0 for deletion:");

		int d = sc.nextInt();

		while(d==1 || d==0){
			switch(d){
				case 1:

				insert(arr,n);

				break;

				case 0:

				delete(arr,n);

				break;

				default: {
					System.exit(0);
				}
			}

			System.out.println("Enter 1 for insertion or 0 for deletion:");

			d = sc.nextInt();

		}

	}

}











































