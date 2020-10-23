import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class TagValues {

	public static void main (String args[]) {
		Scanner scanner = new Scanner(System.in);
		int inpLines = Integer.parseInt(scanner.nextLine());
		List<String> resList = new ArrayList<String>();
		String inpRec;
		for (int i=0;i<inpLines;i++) {
			inpRec = scanner.nextLine();
			if (tagsMatch(inpRec))
				resList.add(inpRec.substring(inpRec.indexOf(">")+1,inpRec.lastIndexOf("<")));
		}
		resList.forEach(System.out::println);
		scanner.close();
	}
	
	private static boolean tagsMatch(String s) {
		if (s.substring(s.indexOf("<")+1,s.indexOf(">")).equals(s.substring(s.lastIndexOf("</")+2,s.lastIndexOf(">"))))
			return true;
		else 
			return false;
	}
}
