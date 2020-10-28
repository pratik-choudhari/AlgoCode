  import java.util.Scanner;
 
/** Class Fenwick Tree **/
public class FenwickTree
{    
    /** Function to update tree **/
    private void update(int[] arr, int pos, int val) 
    {
        int len = arr.length;
        for (; pos < len; pos |= (pos + 1)) 
            arr[pos] += val;
    }
    /** Function to query **/
    private int query(int[] arr, int pos) 
    {
        int sum = 0;
        for (; pos >= 0; pos = (pos & (pos + 1)) - 1) 
            sum += arr[pos];
 
        return sum;
    }
 
    public static void main(String[] args) 
    {
        Scanner scan = new Scanner( System.in );        
        System.out.println("Fenwick Tree Test\n");
        /** Accept number of elements **/
        System.out.println("Enter number of integer elements");
        int n = scan.nextInt();
        /** Create integer array on n elements **/
        int arr[] = new int[ n ];
 
        FenwickTree ft = new FenwickTree();
 
        /** update or find sum **/
        char ch;
        do    
        {
            System.out.println("\nFenwick Tree Operations\n");
            System.out.println("1. update ");
            System.out.println("2. query");
 
            int choice = scan.nextInt();            
            switch (choice)
            {
            case 1 : 
                System.out.println("Enter position and value to update");
                ft.update(arr, scan.nextInt(), scan.nextInt() );                     
                break;                          
            case 2 : 
                System.out.println("Enter position to find sum till nth element");
                try
                {
                    System.out.println("Sum = "+ ft.query(arr, scan.nextInt()) );
                }
                catch (Exception e)
                {
                    System.out.println("\nError! Out of bounds\n");
                }
                break;                         
            default : 
                System.out.println("Wrong Entry \n ");
                break;   
            }
 
            System.out.println("\nDo you want to continue (Type y or n) \n");
            ch = scan.next().charAt(0);                        
        } while (ch == 'Y'|| ch == 'y');                                     
    }    
}
