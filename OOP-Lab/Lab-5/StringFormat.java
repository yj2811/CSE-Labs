import java.util.*;

class StringFormat{
	static String addCommas (String s){
		String newString = "";
		int k = 0;

		for(int i=s.length()-1; i>=0; i--){
			char ch = s.charAt(i);
			if((++k)%3==0 && i>0){
				newString = "," + ch + newString;
			}else{
				newString = ch + newString;
			}
		}

		return newString;
	}

	public static void main (String args[]) {
		Scanner sc = new Scanner (System.in);
		System.out.print("\nEnter a number: ");
		String string = sc.nextLine();
		System.out.println("\nOriginal: " + string + "\nModified: " + addCommas(string));
	}
}