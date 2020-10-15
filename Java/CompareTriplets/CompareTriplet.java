import java.util.Scanner;

public class CompareTriplet {

	public static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {

		int personA[] = { 0, 0, 0 };
		int personB[] = { 0, 0, 0 };
		int scoreA = 0, scoreB = 0;
		
		//Taking user input
		System.out.println("Enter person A's rating: ");
		for (int i = 0; i < 3; i++) {
			personA[i] = sc.nextInt();
		}

		System.out.println("Enter person B's rating: ");
		for (int i = 0; i < 3; i++) {
			personB[i] = sc.nextInt();
		}
		
		//calculating score
		for(int i = 0; i < 3; i++) {
			if(personA[i] == personB[i])continue;
			else if(personA[i] > personB[i]) scoreA++;
			else if(personA[i] < personB[i]) scoreB++;
		}
		
		//printing score
		int score [] = {scoreA, scoreB};
		System.out.println("Score is: ["+score[0]+","+score[1]+"]");

	}
	
}