// C# program to check if a number is Harshad Number or not 

using System; 

public class HN { 

	// method to check Harshad Number 
	static bool checkHarshad(int n) 
	{ 

		// calculate sum of digits 
		int sum = 0; 
		for (int temp = n; temp > 0; temp /= 10) 
			sum += temp % 10; 

		// Return true if sum of digits is 
		// multiple of n 
		return (n % sum == 0); 
	} 

	// Driver program to test above functions 
	public static void Main() 
	{ 
		Console.WriteLine("\nEnter number: "); 
		int n = Convert.ToInt32(Console.ReadLine());
		Console.WriteLine(checkHarshad(n) ? "Yes" : "No"); 
	} 
} 
