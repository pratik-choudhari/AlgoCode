using System;

namespace pascals_triangle
{
    public class Test
    {
	    public static void Main()
	    {
    	    int num, tempnum;
    	    Console.WriteLine("Enter the line number till which pascals triangle will be shown: ");
    	    tempnum = Convert.ToInt32(Console.ReadLine());
    	    num = tempnum - 1;
    	    for(int i=0;i<=num;i++)
    	    {
    	        for(int j = 0;j<=i;j++)
    	        {
    	           Console.Write("{0} ", combination(i,j));
    	        }
    	        Console.Write("\n");
    	    }
	    }
	    
	    static int factorial(int n) 
        { 
            if (n == 0) 
                return 1; 
  
            return n * factorial(n - 1); 
        } 
        static int combination(int n, int r)
        {
            int perm = factorial(n)/(factorial(n-r)*factorial(r));
            return perm;
        }
    }
}