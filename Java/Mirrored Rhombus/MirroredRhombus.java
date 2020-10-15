import java.util.*;

class MirroredRhombus
{
    //function to print the mirrored rhombus
    public static void printRhombus(int n)
    {
        	for(int i=n-1;i>=0;i--)
            {
	            for(int j=n-i;j<n;j++)
                
                {
                    System.out.print(" ");
                }
                for(int j=1;j<=n;j++)
                
                {
                    System.out.print("*");
                }
                   
                System.out.println();
                       
             }             
 

                
    }


 
    public static void main(String[] args)
    {
             
	    Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number of test cases.");
        int t = sc.nextInt();
        while(t-->0) //for running the program for multiple test cases
        {
            System.out.println("Enter the size."); 
	        int n=sc.nextInt();
            printRhombus(n);
        }
	    
    }
 

}