using System;

namespace nPrCode
{
    public class Test
    {
	    public static void Main()
	    {
    	    int n,r;
    	    Console.WriteLine("Enter no. of people: ");
    	    n = Convert.ToInt32(Console.ReadLine());
    	    Console.WriteLine("Enter no. of chairs: ");
    	    r = Convert.ToInt32(Console.ReadLine());
    	    int permute;
    	    permute = factorial(n)/factorial(n-r);
    	    Console.WriteLine("Hence the number of permutations: ");
    	    Console.WriteLine(permute);
	    }
	    
	    static int factorial(int n) 
        { 
            if (n == 0) 
                return 1; 
  
            return n * factorial(n - 1); 
        } 
    }
}