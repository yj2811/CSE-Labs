import java.util.Scanner;

class BankAccount{
	String name;
	int AccNo;
	String AccType;
	int balanceAmount;
	static float roi;

	BankAccount(){
		System.out.println("Inside the default constructor:");
		this.name = "YJ";
		this.AccNo = 12345;
		this.AccType = "Savings";
		this.balanceAmount = 1000000000;
		this.roi = 5;
	}

	BankAccount(String name, int AccNo, String AccType, int balanceAmount){
		System.out.println("Inside the parameterized constructor:");
		this.name = name;
		this.AccNo = AccNo;
		this.AccType = AccType;
		this.balanceAmount = balanceAmount;
	}

	void depositAmount(int m){
		this.balanceAmount += m;
	}

	void withdrawAmount(int m){
		if(m > this.balanceAmount){
			System.out.println("Not enough money to withdraw.");
		}else{
			this.balanceAmount -= m;
		}
	}

	void display(){
		System.out.println("Bank account details: " + this.name + "\n" + this.AccNo + "\n" + this.AccType + "\n" + this.balanceAmount + "\n" + this.roi);
	}

	static void displayRate(){
		System.out.println(roi);
	}

}

class BankDemo{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);

		BankAccount b1 = new BankAccount();
		System.out.println("Enter name of account holder");
		String nam = new String();
		nam = sc.next();
		System.out.println("Enter account number");
		int acn;
		acn = sc.nextInt();

		sc.nextLine();

		System.out.println("Enter account type. Savings or Current?");
		String act = new String();
		act = sc.next();
		System.out.println("Enter account balance");
		int bal;
		bal = sc.nextInt();
		BankAccount b2 = new BankAccount(nam, acn, act, bal);

		b1.display();
		b2.display();

		int deposit, withdraw, flag;
		System.out.println("1 to deposit, 2 to withdraw");
		flag = sc.nextInt();
		if (flag == 1)
		{
			System.out.println("Enter money you want to deposit:");
			deposit = sc.nextInt();
			b2.depositAmount(deposit);
			b2.display();
		}
		if (flag == 2)
		{
			System.out.println("Enter money you want to withdraw:");
			withdraw = sc.nextInt();
			b2.withdrawAmount(withdraw);
			b2.display();
		}
	}
}



