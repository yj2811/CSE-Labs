import java.util.Scanner;
class UGStudent{
	int reg;
	double cgpa;
	public UGStudent(int reg,double cgpa){
		this.reg=reg;
		this.cgpa=cgpa;
	}
}
class Matrix{
	int r;
	int c;
	Scanner sc=new Scanner(System.in);
	private UGStudent a[][];
	public Matrix(int r,int c) {
		this.r = r;
		this.c = c;
		a= new UGStudent[r][c];
	}
	public void input() {
		for(int i=0;i<a[r-1].length;i++) {
			System.out.println("Enter reg number for student "+(i+1)+" :");
			int r=sc.nextInt();
			for(int j=0;j<a.length;j++) {
				System.out.println("Enter CGPA for year "+(j+1));
				double cg=sc.nextDouble();
				a[j][i]=new UGStudent(r,cg);
			}			
		}
	}
	public UGStudent[] getRow(int i) {
		return a[i];
	}
	public void display() {
		for(int i=0;i<a[r-1].length;i++) {
			int j=0;
			System.out.println("Details for student with registration number : "+a[j][i].reg);
			for(j=0;j<a.length;j++)
				System.out.print(a[j][i].cgpa+" ");
			System.out.println();
		}
	}		
}
class RowAvg implements Runnable{
	private UGStudent ar[];
	private double avg;
	public RowAvg(UGStudent ar[]) {
		this.ar=ar;
		avg=0.0;
	}
	public double getRowAvg() throws TooLowAvgCgpaException{
		if(avg>4)
		return avg;
		else
			throw new TooLowAvgCgpaException();
	}
	public void run() {
		for(int i=0;i<ar.length;i++) {
			avg+=ar[i].cgpa;
		}
		avg/=ar.length;
	}	
}
class TooLowAvgCgpaException extends Exception{
	public TooLowAvgCgpaException() {
		super("The average CGPA is less than 4");
	}
	public String toString(){
		return "The average CGPA is less than 4";
	}
}
public class Cgpacompute {

	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		// TODO Auto-generated method stub
		System.out.println("Enter number of students and year : ");
		int c=sc.nextInt();
		int r=sc.nextInt();
		Matrix mat= new Matrix(r,c);
		mat.input();
		mat.display();
		Thread t[]=new Thread[r];
		RowAvg r1[]=new RowAvg[r];
		for(int i=0;i<r;i++) {
			r1[i]= new RowAvg(mat.getRow(i));
			t[i]= new Thread(r1[i]);
			t[i].start();
		}
		int check=0;
		double average=0.0;
		try {
			for(int i=0;i<r;i++) {
				t[i].join();
				average+=r1[i].getRowAvg();
				System.out.println("The Average CGPA for year "+(i+1)+" : "+r1[i].getRowAvg());
				}	
		}
		catch(InterruptedException|TooLowAvgCgpaException exc) {
			System.out.println(exc);
			check=-1;
		}
		if(check==0) {
			average/=r;
			System.out.println("The overall Average CGPA : "+average);
		}		
	}
}