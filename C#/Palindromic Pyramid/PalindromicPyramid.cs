using System;
					
public class Program
{
	public static void Main()
	{
		
		int row;
		Console.Write("Please enter a integer :");
		
		try{
			
			row = Int16.Parse(Console.ReadLine());

			for (int i = 1; i < row+1; i++) {
				for(int j = 1; j <= (i); j++){
					Console.Write(j + " ");
				}	
				for(int k = (i-1); k >= 1; k--){
					Console.Write(k + " ");

				}
				Console.WriteLine("");
				
			}
			
			
		}	
		
		catch (Exception e){
			Console.WriteLine(e.Message + " Please try again");
		}
		
	}
}
