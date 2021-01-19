import java.util.GregorianCalendar;
import java.util.Scanner;
import java.text.*;

public class Person {

	private String name;
	private GregorianCalendar DOB;

	public Person () {
		name = "";
		DOB = new GregorianCalendar ();
	}
	
	public void setName (String n) {
		name = n;
	}
	
	public void setDOB (GregorianCalendar dob) {
		DOB = dob;
	}

	public String getName () {
		return name;
	}

	public GregorianCalendar getDOB ()  {
		return DOB;
	}
	
	public void inputFields () {
		Scanner sc = new Scanner (System.in);
		
		System.out.print ("Enter name: ");
		name = sc.nextLine ();
		
		System.out.print ("Enter dob (yyyy/mm/dd): ");
		DOB = new GregorianCalendar (sc.nextInt(), sc.nextInt() - 1, sc.nextInt());
	}
	
	public void display () {
		SimpleDateFormat dateFormat = new SimpleDateFormat("MM/dd/yyyy");
		System.out.println ("\n\nName: " + name + "\nDOB: " + dateFormat.format(DOB.getTime()));
	}
	
}