using System;
					
public class Program
{
	public static void Main()
	{
		
		int row;
		int num = 1 ;

		Console.Write("Please enter a integer :");
		
		try{
			
			row = Int16.Parse(Console.ReadLine());
			
			for (int i = 0; i < row+1; i++) {
				for (int j = 0; j < i; j++) {
					Console.Write(num + " ");
					num = num+1 ;
				}
				Console.WriteLine("");
				
			}
		}	
		
		catch (Exception e){
			Console.WriteLine(e.Message + " Please try again");
		}
		
	}
}