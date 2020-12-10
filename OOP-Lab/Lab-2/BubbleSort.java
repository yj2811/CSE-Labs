import java.util.Scanner;

public class BubbleSort{

	static void bubbleSortA(int arr[], int n){

		for(int i=0; i<n-1; i++){
			int swap = 0;
			for(int j=0; j<n-i-1; j++){

				if(arr[j+1]<arr[j]){

					swap = 1;

					int temp = arr[j+1];
					arr[j+1] = arr[j];
					arr[j] = temp;
				}
			}

			if(swap==0){
				break;
			}
		}

		System.out.println("Printing the sorted array:");

		for(int i=0; i<n; i++){
			System.out.println(arr[i]);		}
	}

static void bubbleSortD(int arr[], int n){

		for(int i=0; i<n-1; i++){
			int swap = 0;
			for(int j=0; j<n-i-1; j++){

				if(arr[j+1]>arr[j]){

					swap = 1;

					int temp = arr[j+1];
					arr[j+1] = arr[j];
					arr[j] = temp;
				}
			}

			if(swap==0){
				break;
			}
		}

		System.out.println("Printing the sorted array:");

		for(int i=0; i<n; i++){
			System.out.println(arr[i]);		}
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

		bubbleSortA(arr, n);
		bubbleSortD(arr, n);
	}
}