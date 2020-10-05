import java.util.Scanner;

public class SingleElement {

    public static void main(String[] args) {
       Scanner sc = new Scanner(System.in); //uses Scanner class. System.in is a standard input stream  
       System.out.print("Please enter the items seperated by a comma: ");    
       String input = sc.nextLine(); //Read entered items seperated by comma
       
       String[] values = input.split(","); 
       System.out.println(singleElement(values));
    }
      
    public static String singleElement(String[] inputs){
        int count = 0; 
        String item = "";

        for (String element : inputs) {
            for (String element1 : inputs) {
                if (element == null ? element1 == null : element.equals(element1)) {
                    count++;
                }
            }
            if (count == 1) { //count is 1 if only a single instance of the element is found in the array
                item = element;
            }
            count = 0; //reset counter
        }
        return item;
    }
    
}
