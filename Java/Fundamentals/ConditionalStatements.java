package fundamentals;

public class ConditionalStatements {

	public static void main(String[] args) {
		
		int a = 1;
		int b = 2;
		
		//If else statement
		/*	If else structure
		 	
		 	if (condition1) {
			  // block of code to be executed if condition1 is true
			} else if (condition2) {
			  // block of code to be executed if the condition1 is false and condition2 is true
			} else {
			  // block of code to be executed if the condition1 is false and condition2 is false
			}
		 	
		 */
		
		if (a < b) {
			System.out.println(b + " is greater than " + a);
		}
		else if(a == b) {
			System.out.println(a +" is equal to "+ b);
		}
		else {
			System.out.println(a + " is greater than " + b);
		}
		
		// Switch Statement
		/*	Switch statement structure
		 	
		 	switch(expression) {
			  case x:
			    // code block
			    break;
			  case y:
			    // code block
			    break;
			  default:
			    // code block
			}
			
		 */
		
		int c = 3;
		switch (c % 2) {
			case 0:
				System.out.println(c+ " is even number");
				break;
			
			case 1:
				System.out.println(c+" is odd number");
				break;
		}
	}

}
