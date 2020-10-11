import java.util.*;
import java.io.*; 

public class StringOperations {

    public static void main(String[] args){

      String[] menulist = new String[10];
      int i;
      int n = 0;
      String inputstr;
      int status = 1;
      Scanner in = new Scanner(System.in);
      Scanner in2 = new Scanner(System.in);

      menulist[0] = "String Length";
      menulist[1] = "Count number of vowels";
      menulist[2] = "Check if the string is Palindrome";
      menulist[3] = "String Length";
      menulist[4] = "Remove Vowels from the string";
      menulist[5] = "Calculate the frequency of characters in the string";
      menulist[6] = "Remove spaces from the string";
      menulist[7] = "Capitalize the first and last character of each word in the string";
      menulist[8] = "Count the sum of numbers in a string";
      menulist[9] = "Concatenate with another input string";

      System.out.println("Select the string operation you would like to perform by entering the number assigned the operation");
      System.out.println("------------------------------");   
      for (i = 0; i < menulist.length; i++) { 
      // accessing each element of array
      System.out.println(i + ".  " + menulist[i]); 
        } 
      System.out.println("------------------------------");   
       // get  menu selection input 
      
      while (status==1) {
      n = in.nextInt();
      if (n<0 || n>9){      
        System.out.println("Please neter a valid number between 0 and 9");
        n = in.nextInt();}
      status = 0;
      }

      System.out.println("The operation requested is : "+ menulist[n] );

      System.out.println("------------------------------");  
      System.out.println("Please enter the string : "); 
      inputstr = in2.nextLine(); // get  input string 
      System.out.println("------------RESULT------------------");if (n==0)
      {
        System.out.println(menulist[n]+" : "+inputstr.length()); 
      } 

      in.close ();
      in2.close ();
    }
}
