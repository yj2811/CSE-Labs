import java.util.Scanner;

class Counter{
	static int count = 0;

	static void showCount(){
		System.out.println("Number of static objects right now are " +count);
	}

	Counter(){
		count++;
	}
}

class CounterDemo{
	public static void main(String args[]){
		Counter c1 = new Counter();
		Counter.showCount();
		Scanner userEntry = new Scanner(System.in);
		char f;
		System.out.println("Do you want to keep adding classes? y/n");
		f = userEntry.next().charAt(0);
		while (f == 'y')
		{
			Counter c = new Counter();
			Counter.showCount();
			System.out.println("Do you want to keep adding classes? y/n");
			f = userEntry.next().charAt(0);
		}
	}
}
