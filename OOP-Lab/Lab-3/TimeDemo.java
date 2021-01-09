import java.util.Scanner;
import java.lang.Math;

class Time{
	public int hh, mm, ss;
	public String id;

	Scanner sc = new Scanner(System.in);

	public Time (String id) {
		this.hh = this.mm = this.ss = 0;
		this.id = id;
	}

	// Initializing with total number of seconds.
	public Time (int ss) {
		initWithSeconds(ss);
	}
	public void initWithSeconds (int ss) {
		this.ss = ss;
		this.hh = this.ss / 3600;
		this.ss -= 3600 * this.hh;
		this.mm = this.ss / 60;
		this.ss -= 60 * this.mm;
	}
	
	// Get the total number of seconds in the sender.
	public int seconds () {
		return (this.ss + this.mm * 60 + this.hh * 3600);
	}

	// Input
	public void input () {
		System.out.println("\tEnter \'" + this.id + "\': ");
		System.out.print("\tEnter hours   (hh) : ");
		this.hh = sc.nextInt();
		System.out.print("\tEnter minutes (mm) : ");
		this.mm = sc.nextInt();
		System.out.print("\tEnter seconds (ss) : ");
		this.ss = sc.nextInt();
		System.out.println();
		
		// Reinitializing incase the user inputs values > 60 for minutes and seconds
		this.initWithSeconds(this.seconds());
	}

	public String toString(){
		return (this.id + " is  " + this.hh + ":" +  this.mm + ":" +  this.ss);
	}

	// Add: initalize with the total number of seconds constructor
	public static Time add (Time t1, Time t2) {
		Time sum = new Time(t1.seconds() + t2.seconds());
		sum.id = t1.id + " + " + t2.id; 
		return sum;
	}
	
	// Substract: initalize with the total number of seconds constructor
	public static Time substract (Time t1, Time t2) {
		Time difference = new Time(Math.abs(t1.seconds() - t2.seconds()));
		difference.id = t1.id + " - " + t2.id; 
		return difference;
	}
	
	public static Time biggerTime (Time t1, Time t2) {
		Time t5;

		if (t1.seconds() > t2.seconds())
			t5 = new Time(t1.seconds());
		else
			t5 = new Time(t2.seconds());

		t5.id = "Bigger Time";
		return t5;
	}

}

class TimeDemo{
	public static void main(String args[]){

		Time t1 = new Time ("T1");
		t1.input();
		
		Time t2 = new Time ("T2");
		t2.input();

		Time t3 = Time.add(t1, t2);

		Time t4 = Time.substract (t1, t2);
		
		Time t5 = Time.biggerTime (t1, t2);

		System.out.println(t1);
		System.out.println(t2);
		System.out.println(t3);
		System.out.println(t4);
		System.out.println(t5);

	}
}