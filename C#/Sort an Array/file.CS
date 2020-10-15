// C# program to print first half in ascending order and the second half in descending order 

using System; 
  
class ABC { 
      
    // function to print half of the array in ascending order and the other half in descending order 
    static void printOrder(int[] arr, int n) 
    { 
          
        // sorting the array 
        Array.Sort(arr); 
      
        // printing first half in ascending order 
        for (int i = 0; i < n / 2; i++)  
            Console.Write(arr[i] + " "); 
      
        // printing second half in descending order 
        for (int j = n - 1; j >= n / 2; j--) 
            Console.Write(arr[j] + " "); 
    } 
      
    // Driver code 
    public static void Main() 
    { 
        int[] arr = { 5, 4, 6, 2, 1, 3, 8, 9, 7 }; 
        int n = arr.Length; 
          
        printOrder(arr, n); 
    } 
} 
