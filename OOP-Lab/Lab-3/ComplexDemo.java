import java.util.Scanner;
import java.lang.Math;

class Complex{
	private double a;
	private double b;
	private String id;
	
	public Complex (String id) {
		this.a = 0.0;
		this.b = 0.0;
		this.id = id;
	}
	
	public void setReal (double a) {
		this.a = a;
	}
	public void setImaginary (double b) {
		this.b = b;
	}
	
	//For display, override the toString method
	public String toString(){
		return ( this.id + " = " +  this.a + " + " +  this.b + "i ");
	}

	//Add and subtract
	public static Complex add(Complex c1, Complex c2){
		Complex c = new Complex("C1 + C2");
		c.setReal(c1.a + c2.a);
		c.setImaginary(c1.b + c2.b);
		return c; 
	}

	public static Complex subtract(Complex c1, Complex c2){
		Complex c = new Complex("C1 - C2");
		c.setReal(Math.abs(c1.a - c2.a));
		c.setImaginary(Math.abs(c1.b - c2.b));
		return c; 
	}
	
}

class ComplexDemo{
	public static void main(String args[]){

		Scanner sc = new Scanner (System.in);

		Complex c1 = new Complex("C1");
		Complex c2 = new Complex("C2");

		c1.setReal(sc.nextInt());
		c1.setImaginary(sc.nextInt());

		c2.setReal(sc.nextInt());
		c2.setImaginary(sc.nextInt());

		System.out.println(c1);
		System.out.println(c2);

		Complex sum = Complex.add(c1, c2);
		System.out.println(sum);

		Complex diff = Complex.subtract(c1, c2);
		System.out.println(diff);

	}
}