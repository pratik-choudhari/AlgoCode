// Java program to find maximum number of handshakes. 
  
import java.util.Scanner;

class maximum_no_of_handshakes
{ 
    //Maximum number of handshakes = nC2 = n*(n-1)/2
    static int maxHandshake(int n) 
    { 
        return (n*(n-1))/2; 
    } 
      
    // Driver code 
    public static void main (String[] args) 
    { 
        Scanner sc= new Scanner(System.in);
        System.out.print("Enter the number of people : ");
        int n = sc.nextInt();
        System.out.println("Max. no. of handshakes = " + maxHandshake(n)); 
    } 
} 