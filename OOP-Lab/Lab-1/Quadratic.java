import java.util.Scanner;
import java.lang.Math;

public class Quadratic{
	public static void main(String args[]){
		double a, b, c;
		double d;

		double root1, root2, img;

		System.out.println("Enter the values of a, b and c:");

		Scanner sc = new Scanner(System.in);

		a = sc.nextDouble();
		b = sc.nextDouble();
		c = sc.nextDouble();

		d = b*b -4*a*c;

		int k = (d>0) ? 1 : (d<0)? 3 : 2;


		switch(k){

			case 1:
			// If discriminant is positive
			root1 = (-b + Math.sqrt(d))/ (2*a);
			root2 = (-b - Math.sqrt(d))/ (2*a);

			System.out.println("Two distinct and real roots: "+ root1 + " and " + root2);

			break;

			case 2:

			// If discriminant is zero
			root1 = -b/(2*a);

			System.out.println("Two equal and real roots: " + root1 + " and " + root1);

			break;

			case 3:

			// If discriminant is negative
			root1 = root2 = -b/(2*a);
			img = Math.sqrt(-d)/(2*a);

			System.out.println("Two distinct complex roots exist: " + root1 +" + " + img + "i and " + root2 +" - " + img);

			break;

		}
	}
}

