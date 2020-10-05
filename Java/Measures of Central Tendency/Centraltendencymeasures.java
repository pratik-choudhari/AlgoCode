//For a given set of numbers calculate the Mean, Median and Mode
//Input: 8 9 4 6 7 25 44 6 8 15
//Output: Mean: 13.2
//Median: 8
//Mode: 8, 6
import java.util.*;
class CentralTendency
{
    void mean(int arr[],int n)
    {   
        float mean = 0;
        int sum = 0;
        for(int i = 0;i<n;i++)
            sum += arr[i];
        mean = sum/(float)n; //mean formula
        System.out.println("The mean of given data is "+mean);
    }
    void median(int arr[],int n)
    {
        //bubble sort logic begins
        for(int i = 0;i<n-1;i++)
        {   
            for(int j=0;j<n-i-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
           
        }
        //added printing just for checking
        // System.out.println("The sorted array is ");
        // for(int i=0;i<n;i++)
        // {
        //     System.out.println(arr[i]);
        // }
        //sorting logic ends
        float median;
        if(n%2==1)
        {
            median = arr[n/2];
        }
        else
        {
            median  = (float)(arr[n/2]+arr[(n/2)-1])/2;
        }
        System.out.println("The median is "+median);
    }
    void mode(int arr[],int n) 
    {
        int maxValue = 0, maxCount = 0;
        //maxValue has mode
        for (int i = 0; i < arr.length; ++i) 
        {
            int count = 0;
            for (int j = 0; j < arr.length; ++j) 
            {
                if (arr[j] == arr[i])
                    ++count;
            }
            if (count > maxCount) 
            {
                maxCount = count;
                maxValue =arr[i];
            }
    }
    System.out.println("The mode is "+maxValue);
}
}
class Prog2
{
    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        int n;
        int arr[];
        System.out.println("Enter number of elements");
        n = sc.nextInt();
        arr = new int[n];
        for(int i=0;i<n;i++)
        {
            arr[i] = sc.nextInt();
        }
        CentralTendency ct = new CentralTendency(); //object created
        ct.mean(arr,n);
        ct.median(arr,n);
        ct.mode(arr,n);
    }
}
