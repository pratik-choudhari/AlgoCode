import java.util.*;
class SelectionSort
{
    void selsort(int arr[])
    {
        int n = arr.length;
        int i,j,k;
        int min_index;
        
        for(i=0;i<n-1;i++)
        {
            min_index = i;
            for(j=i+1;j<n;j++)
            {
                if(arr[j]<arr[min_index])
                    min_index = j;
            }
            int temp = arr[min_index];
            arr[min_index] = arr[i];
            arr[i] = temp;
        }
        System.out.println("The sorted array is:-");
        for(i=0;i<n;i++)
        {
            System.out.println(arr[i]);
        }
    }
}
class Prog1
{
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int arr[];
        int n;
        System.out.println("Enter number of elements in array:-");
        n = sc.nextInt();
        arr = new int[n];
        for(int i = 0;i<n;i++)
        {
            System.out.println("Enter element "+i);
            arr[i]= sc.nextInt();
        }
        SelectionSort s = new SelectionSort();
        s.selsort(arr);
    }
}
