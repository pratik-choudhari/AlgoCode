package fundamentals;

public class Loops {

	public static void main(String[] args) {
		
		//for loop
		
		/*For loop structure
		  for(initialization; Boolean_expression; update){
		  		//your code
		  }*/
		for(int i = 1; i <= 5; i++) {
			System.out.println("For loop iteration no: "+i);
		}
		
		//while loop
		
		/*	while loop structure
		 	
		 	while( Boolean_expression ){
		 		//your code
		 	}
		 */
		int i = 1;
		while(i <= 5) {
			System.out.println("while loop iteration no: "+i);
			i++;
		}
		
		// Do while loop
		
		/*	Do while loop structure
		 	
		 	do{
		 	
		 		//your code
		 		 
		 	}while( Boolean_expression );
		 	
		 */
		i = 1;
		do {
			System.out.println("Do while loop iteration no: "+i);
			i++;
		}while(i <= 5);

	}

}
