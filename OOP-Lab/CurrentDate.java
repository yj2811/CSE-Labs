import java.util.*

class InvalidDayException extends Exception{
	InvalidDayException(){
		System.out.println("Invalid day.");
	}
}

class InvalidMonthException extends Exception{
	InvalidMonthException(){
		System.out.println("Invalid month.");
	}
}

class CurrentDate{
	int day;
	int month; 
	int year;


	void createDate(){

	}

	void displayDate(){

	}

	public static void main(String args[]){
		CurrentDate currentDate = new CurrentDate();
		
	}

}