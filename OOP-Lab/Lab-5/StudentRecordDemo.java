import java.util.*;
import java.text.*;

class StudentRecord {
    
    int regNo;
    String fullName;
    GregorianCalendar dateJoined;
    short semester;
    float gpa;
    float cgpa;
    
    StudentRecord () {
        regNo = 0;
        fullName = "";
        dateJoined = new GregorianCalendar();
        semester = 0;
        gpa = 0.f;
        cgpa = 0.f;
    }
    
    StudentRecord (StudentRecord s) {
        this.regNo = s.regNo;
        this.fullName = s.fullName;
        this.dateJoined = s.dateJoined;
        this.semester = s.semester;
        this.gpa = s.gpa;
        this.cgpa = s.cgpa;
    }
    
    public void display () {
        SimpleDateFormat dateFormat = new SimpleDateFormat("MM/dd/yyyy"); 
        System.out.println("Name :" + fullName + "\t     Reg No :" + regNo + "\tDate Joined :" + dateFormat.format(dateJoined.getTime()) + "\t   Semester :" + semester + "\t        GPA :" + gpa + "\t       CGPA :" + cgpa);
    }
    
    public void input () {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Name: ");
        fullName = sc.nextLine();
        System.out.println("Enter Date Joined (yyyy mm dd): ");
        dateJoined = new GregorianCalendar(sc.nextInt(), sc.nextInt()-1, sc.nextInt());
        System.out.println("Enter Semester: ");
        semester = sc.nextShort();
        System.out.println("Enter GPA: ");
        gpa = sc.nextFloat();
        System.out.println("Enter CGPA: ");
        cgpa = sc.nextFloat();
        System.out.println();
    }
}

class StudentRecords {
    
    StudentRecord studentRecords[];
    int size;
    
    public StudentRecords (int size) {
        this.size = size;
        this.studentRecords = new StudentRecord[size];
    }
    
    public void inputAll () {
        for (int i = 0; i < size; ++i) {
            System.out.println("Student " + (i+1) + " :");
            studentRecords[i] = new StudentRecord();
            studentRecords[i].input();
            SimpleDateFormat dateFormat = new SimpleDateFormat("yy");
            String regNo = dateFormat.format(studentRecords[i].dateJoined.getTime());
            regNo += String.format( "%02d", i+1);
            studentRecords[i].regNo = Integer.parseInt(regNo);
        }
    }
    
    public void displayAll () {
        for (StudentRecord stud: studentRecords)
            stud.display();
    }
    
    public void list (String str) {
        for (StudentRecord stud: studentRecords) {
            if (stud.fullName.contains(str))
                stud.display();
        }
    }
    
    public void list (char ch) {
        for (StudentRecord stud: studentRecords) {
            if (stud.fullName.indexOf(ch) == 0)
                stud.display();
        }
    }
    
    public void shortenName () {
        for (StudentRecord stud: studentRecords) {
            String newName = "";
            String lastName = "";
            StringTokenizer st = new StringTokenizer (stud.fullName);
            while (st.hasMoreTokens()) {
                lastName = st.nextToken();
                newName += lastName.charAt(0) + ". ";
            }
            newName = newName.substring(0, newName.length() - 3) + lastName;
            stud.fullName = newName;
        }
    }
    
    public void sort (String wrt) {
        for (int i = 0; i < size - 1; ++i) {
            int min = i;
            for (int j = i + 1; j < size; ++j) {
                if (wrt.equals("semester") && (studentRecords[j].semester < studentRecords[min].semester))
                    min = j;
                if (wrt.equals("cgpa") && (studentRecords[j].cgpa < studentRecords[min].cgpa))
                    min = j;
                if (wrt.equals("fullName") && (studentRecords[j].fullName.compareTo(studentRecords[min].fullName)) < 0)
                    min = j;
            }
            if (min != i) {
                StudentRecord temp = studentRecords[i];
                studentRecords[i] = studentRecords[min];
                studentRecords[min] = temp;
            }
        }
    }
}

public class StudentRecordDemo {
    
    public static void main (String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of records: ");
        int size = sc.nextInt();
        
        StudentRecords studentRecords = new StudentRecords (size);
        studentRecords.inputAll();
		sc.nextLine();
        
        char choice;
        do {
            System.out.print("\n1. Display Records." + 
							"\n2. Sort wrt Name." +
							"\n3. Sort wrt Semester." +
							"\n4. Sort wrt CGPA." +
							"\n5. List all Students whose name begins with a character." +
							"\n6. List all Students whose name contains a string." +
							"\n7. Change the names of all students to shortened form." +
							"\nAnything else for exit." +
							"\n\n Enter choice: ");
            choice = sc.next().charAt(0);
			sc.nextLine();
            
            switch (choice) {
                case '1': studentRecords.displayAll();
                    break;
                case '2': studentRecords.sort("fullName");
                        System.out.println("\nSotred wrt Name.\n");
                        studentRecords.displayAll();
                    break;
                case '3': studentRecords.sort("semester");
                        System.out.println("\nSotred wrt Semester.\n");
                        studentRecords.displayAll();
                    break;
                case '4': studentRecords.sort("cgpa");
                        System.out.println("\nSotred wrt CGPA.\n");
                        studentRecords.displayAll();
                    break;
                case '5': System.out.print("\n\tEnter the character: ");
                        char ch = sc.next().charAt(0);
                        studentRecords.list(ch);
                    break;
                case '6': System.out.print("\n\tEnter the string: ");
                        String subs = sc.nextLine();
                        studentRecords.list(subs);
                    break;
                case '7': studentRecords.shortenName();
                        System.out.println("\n\tShortened Name.\n");
                        studentRecords.displayAll();
                    break;
                default: break;
            }
            
        } while ("1234567".indexOf(choice) != -1);
    }
}