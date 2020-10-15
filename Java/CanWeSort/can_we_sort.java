import java.lang.*;
import java.io.*;
import java.util.*;
 
class can_we_sort{
     
// Function for finding if it possible 
// to obtain sorted array or not     
public static boolean fun(int[] arr, int n,
                                     int k)
{
    Vector<Integer> v = new Vector<Integer>();
 
    // Iterate over all elements until K 
    for(int i = 0; i < k; i++)
    {
        
       // Store elements as multiples of K 
       for(int j = i; j < n; j += k)
       {
          v.add(arr[j]);
       }
        
       // Sort the elements 
       Collections.sort(v);
        
       int x = 0;
        
       // Put elements in their 
       // required position 
       for(int j = i; j < n; j += k)
       {
          arr[j] = v.get(x);
          x++;
       }
       v.clear();
    }
 
    // Check if the array becomes 
    // sorted or not 
    for(int i = 0; i < n - 1; i++)
    {
       if (arr[i] > arr[i + 1])
       {
           return false;
       }
    }
    return true;
}
 
// Driver code 
public static void main (String args[])
{
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int k = sc.nextInt();
    int[] arr = new int[n];
    
    for(int i=0;i<arr.length;i++){
            int val = sc.nextInt();
            arr[i] = val;
            
    }
    
    
	System.out.println("output:");
 
    if (fun(arr, n, k))
    {
        System.out.println("True");
    }
    else
    {
        System.out.println("False");
    }
}
}
 