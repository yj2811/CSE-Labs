import java.util.Scanner;

class Mixer {
	int arr[], n;
	Scanner sc = new Scanner (System.in);
	
	public Mixer (int n) {
		this.n = n;
		this.arr = new int[n];
	}
	
	public void accept() {
		System.out.print("Number of elements: ");
		this.n = sc.nextInt();
		this.arr = new int[n]; // Dynamically alloting
		for (int i = 0; i < n; ++i) {
			this.arr[i] = sc.nextInt();
			
			//Input in ascending order
			if (i != 0) {
				while (this.arr[i-1] >= this.arr[i]) {
					System.out.println("The elements should be in strictly ascending order. Enter a[" + i + "] again : ");
					this.arr[i] = sc.nextInt();
				}
			}
		}
	}
	
	// Merge the contents
	public Mixer mix(Mixer A) {
		Mixer newMixer = new Mixer (A.n + this.n);
		int i;
		for (i = 0; i < this.n; ++i)
			newMixer.arr[i] = this.arr[i];
		for (i = 0; i < A.n; ++i)
			newMixer.arr[this.n+i] = A.arr[i];
		return newMixer;
	}
	
	// Display the array
	public void display() {
		for (int i = 0; i < this.n; ++i)
			System.out.println(this.arr[i]);
	}
}

public class MixerDemo {
	public static void main(String [] args) {
		Mixer A = new Mixer(0);
		Mixer B = new Mixer(0);
		
		System.out.println("Array 1:");
		A.accept();
		
		System.out.println("Array 2:");
		B.accept();
		
		Mixer C = A.mix(B); // Format
		
		System.out.println("Array 1: ");
		A.display();
		
		System.out.println("Array 2: ");
		B.display();
		
		System.out.println("Array 1+2: ");
		C.display();
	}
}