import java.util.Scanner;


class Matrix{
	String id;
	int m, n;
	int mat[][];

	public Matrix(int m, int n){
		this.m = m;
		this.n = n;
		this.mat = new int[m][n];
	}

	public Matrix(String id){
		this.id = id;
		this.m = 0; 
		this.n = 0;
		this.mat = new int[m][n];
	}

	public void input(){

		Scanner sc = new Scanner(System.in);

		System.out.println("Enter the dimensions of the matrix " + id + ":");

		this.m = sc.nextInt();
		this.n = sc.nextInt();
		this.mat = new int[m][n];


		System.out.println("Enter the elements of the matrix row wise:");

		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				this.mat[i][j] = sc.nextInt();
			}
		}
	}

	public void printMatrix(){

		System.out.println("Printing matrix " + id + ":");

		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				System.out.print(mat[i][j] + "\t");
			}
			System.out.print("\n");
		}

		System.out.println();
	}

	public static Matrix add(Matrix a, Matrix b){
		Matrix c = new Matrix(a.m, a.n);
		if(a.m == b.m && a.n == b.n){
			for(int i=0; i<a.m; i++){
				for(int j=0; j<a.n; j++){
					c.mat[i][j] = a.mat[i][j] + b.mat[i][j];
				}
			}
		}else{
			System.err.println("Dimension error.");
		}
		return c;
	}
}


public class MatrixAddition{


	public static void main(String args[]){
		Matrix A = new Matrix("A");
		Matrix B = new Matrix("B");

		A.input();
		B.input();

		A.printMatrix();
		B.printMatrix();

		Matrix C = Matrix.add(A,B);
		C.id = "A+B";

		C.printMatrix();
	}
}