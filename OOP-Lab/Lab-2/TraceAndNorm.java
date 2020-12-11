import java.util.Scanner;
import java.lang.Math;

public class TraceAndNorm{

	public static int trace(int mat[][], int m, int n){

		int trace=0;

		if(m==n){
			for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				if(i==j){
					trace += mat[i][j];
				}
			}
		}

		return trace;
	} else{
		return -1;
	}

		
	}

	public static double norm(int mat[][], int m, int n){

		int sum=0;

		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){

				sum += mat[i][j];
			}
		}

		return Math.sqrt(sum);
	}


	public static void main(String args[]){
		int m, n;
		System.out.println("Enter the dimensions of the matrix: ");

		Scanner sc = new Scanner(System.in);

		m = sc.nextInt();
		n = sc.nextInt();

		int mat[][] = new int[m][n];

		System.out.println("Enter the elements of the matrix row wise:");

		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				mat[i][j] = sc.nextInt();
			}
		}

		System.out.println("Printing matrix:\n");

		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				System.out.print(mat[i][j] + "\t");
			}
			System.out.print("\n");
		}

		System.out.println();

		System.out.println("The trace of the matrix is: " + trace(mat, m, n));
		System.out.println("The norm of the matrix is: " + norm(mat, m, n));


	}
}