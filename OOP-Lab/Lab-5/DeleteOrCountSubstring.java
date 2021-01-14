import java.util.*;

class DeleteOrCountSubstring{
	public static String DeleteSubstring(String s1, String s2){
		return s1.replaceAll(s2,"");
	}

	public static int CountSubstring(String s1, String s2){
		int count = 0;
		int fromIndex = 0;

		while((fromIndex = s1.indexOf(s2, fromIndex)) != -1){
			System.out.println("Found at: " + fromIndex);
			count++;
			fromIndex++;
		}

		return count;
	}

	public static void main(String args[]){
		String s1, s2;
		Scanner sc = new Scanner(System.in);

		System.out.println("Enter the main string:");
		s1 = sc.nextLine();

		System.out.println("Enter the substring:");
		s2 = sc.nextLine();

		System.out.println("Enter 1 for deletion and 2 for counting occurences of the substring:");
		char ch = sc.next().charAt(0);

		if(ch=='1'){
			System.out.println("The new string is:" + DeleteSubstring(s1,s2));
		}else if(ch=='2'){
			System.out.println("The count is: " + CountSubstring(s1,s2));
		}
	}
}