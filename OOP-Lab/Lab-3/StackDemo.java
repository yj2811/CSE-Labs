import java.util.Scanner;

class Stack{
	int stack[];
	int tos;
	final int UNDERFLOW = -2147483648; // Minimum value of integer type

	//Initializing stack with size
	public Stack(int size){
		tos = -1;
		stack = new int[size];
	}

	//Initializing stack without size
	public Stack(){
		tos = -1;
		stack = new int[0];
	}

	//Full and empty checkers
	public boolean isFull(){
		if(tos == stack.length - 1){
			return true;
		}

		return false;
	}

	public boolean isEmpty(){
		if(tos == -1){
			return true;
		}
		return false;
	}

	//Push and pop
	public void push(int ele){
		if(!this.isFull()){
			stack[++tos] = ele;
		}else{
			System.err.println("Stack overflow");
		}
		
	}

	public int pop(){
		if(!this.isEmpty()){
			return stack[tos--];
		}else{
			System.err.println("Stack underflow");
			return UNDERFLOW;
		}
	}

	// No need for this way
	// public void display(Stack s){

	// }

	//This way
	public void display(){
		System.out.println("Displaying the stack:");
		for(int i=0; i<=tos; i++){
			System.out.println(stack[i]);
		}
	}

}

class StackDemo{
	public static void main(String args[]){
		int size;
		Scanner sc = new Scanner(System.in);

		System.out.println("Enter the size of the stack:");
		size = sc.nextInt();

		Stack s = new Stack(size);

		char choice;

		do{
			System.out.println("1. Push an element.\n2. Pop an element.\n3. Display current stack.\nAnything else for exit.\nEnter your choice:");
			choice = sc.next().charAt(0);

			if (choice == '1') {
				System.out.println("Enter element to be pushed: ");
				int item = sc.nextInt();
				s.push(item);
				s.display();
			}
			else if (choice == '2') {
				int item = s.pop();
				System.out.println("Popped item: " + item);
				s.display();
			}
			else if (choice == '3') {
				s.display();
			}
		} while(choice == '1' || choice == '2' || choice == '3');
	}
}