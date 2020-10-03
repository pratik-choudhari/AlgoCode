import java.util.Scanner;
import java.util.Array
public class SuffixPrefix
{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
        int n;
        // input the number of elements in the array
		System.out.println("Enter Number of Elements of the array");
        n=sc.nextInt();
		int[] Array=new int[n];
		int[] prefix=new int[n];
		int[] suffix=new int[n];
        System.out.println("Enter the elements in the array");
        //Input the elements of the array
		for(int i=0;i<n;i++)
		{
		    Array[i]=sc.nextInt();
		}
        prefix[0]=Array[0];
        //Calculate Prefix sum which is sum of current elememt and previous element(index-1) but start from index 0
		for(int i=1;i<n;i++)
		{
		    prefix[i]=prefix[i-1]+Array[i];
		}
        suffix[n-1]=Array[n-1];
        //Calculate suffix sum which is sum of current elememt and previous element(index-1) but start from end 
        //
		for(int j=n-2;j>=0;j--)
		{
		    suffix[j]=suffix[j+1]+Array[j];
        }
        //Print the prefix sum array
		System.out.print("Prefix-");
		for(int i=0;i<n;i++)
		{
		   System.out.print(prefix[i]);
		   System.out.print(" ");
		}
		System.out.println("");
		System.out.print("Suffix-");
		//print suffix sum array
		for(int i=0;i<n;i++)
		{
		   System.out.print(suffix[i]);
		   System.out.print(" ");
		}
	}
}
