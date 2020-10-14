import java.util.Scanner;

class max_array_sum
{ 
    /*Function to return max sum such that no two elements 
      are adjacent */
    int FindMaxSum(int arr[], int n) 
    { 
        int incl = arr[0]; 
        int excl = 0; 
        int excl_new; 
        int i; 
  
        for (i = 1; i < n; i++) 
        { 
            /* current max excluding i */
            excl_new = (incl > excl) ? incl : excl; 
  
            /* current max including i */
            incl = excl + arr[i]; 
            excl = excl_new; 
        } 
  
        /* return max of incl and excl */
        return ((incl > excl) ? incl : excl); 
    } 
  
    // Driver program to test above functions 
    public static void main(String[] args) 
    { 
        max_array_sum sum = new max_array_sum(); 
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of array elements : ");
        int n = sc.nextInt();
        int arr[] = new int[n];
        System.out.print("Enter array : ");
        for(int i=0;i<n;i++)
            arr[i] = sc.nextInt();
        System.out.println("Maximum subset sum : " + sum.FindMaxSum(arr,n)); 
    } 
}