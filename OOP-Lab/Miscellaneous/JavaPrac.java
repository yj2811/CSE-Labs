import java.util.Scanner;

class Employee{
	int a;
	int b;

	public static Employee getEmployee(){
		Employee e = new Employee();
		e.a = 1;
		e.b = 2;

		return e;

	}
}

public class JavaPrac{
	public static void main(String args[]){

		Employee e1 = new Employee();
		Employee e2 = e1. getEmployee();
		System.out.println(e2.a + " " +  e2.b);
	}
}