import java.util.*;

public class ScalerProduct {

    public static void main (String args[]) {
        
        int n, sum1 = 0, sum2 = 0;
        
        // Size of arrays taken by user.
        Scanner s = new Scanner(System.in);
        System.out.println("Enter no. of elements you want in array:");
        n = s.nextInt();
        
        int [] arr1 = new int[n];
        Integer [] arr2 = new Integer[n];
        
        // Array 1 elements taken by user.
        System.out.println("Array 1:");
        for(int i = 0; i < n; i++)
        {
            arr1[i] = s.nextInt();
        }
        
        // Array 2 elements taken by user.
        System.out.println("Array 2:");
        for(int i = 0; i < n; i++)
        {
            arr2[i] = s.nextInt();
        }
        
        // Array 1 and Array 2 sorted in ascending and descending order respectively.
        Arrays.sort(arr1);
        Arrays.sort(arr2, Collections.reverseOrder());
        // Minimum Scalar Product is calculated and stored in sum1.
        for (int j = 0; j < n; j++) {
            sum1 += arr1[j]*arr2[j];
        }
        
        // Array 2 sorted in ascending order, Maximum Scalar Product is calculated and stored in sum2.
        Arrays.sort(arr2);
        for (int j = 0; j < n; j++) {
            sum2 += arr1[j]*arr2[j];
        }
        
        // Minimum and Maximum Scalar Product is shown to the user.
        System.out.println("Minimum Scalar Product is " + sum1);
        System.out.println("Maximum Scalar Product is " + sum2);
    }

}
 