/*

Problem statement:
Given a number N, input N elements and the task is to perform the following operations all together:

Find the Smallest Number
Find Largest Element
Find the sum of all array elements
Find Frequency of elements
Count Distinct Elements
Count Repeating Elements
Count of Even elements
Count of odd elements

Sample Input: 
12
16 5 8 9 20 4 3 7 8 5 3 2

Sample Output: 

Smallest Number: 2
Largest Number: 20
Sum of Array elements= 90
Frequency of elements= 16-1 2-1 3-2 20-1 4-1 5-2 7-1 8-2 9-1 
Count of distinct elements= 6
Count of repeating elements= 3
Count of Even Elements= 6
Count of Odd Elements= 6

*/

package operations;
import java.util.*;
public class OperationsOnArray {
	public static int smallestNumberInArray(int []a,int n)
	{
		int min=Integer.MAX_VALUE;
		for(int i=0;i<n;i++)
		{
			if(a[i]<min)
				min=a[i];
		}
		return min;
	}
	public static int largestNumberInArray(int []a,int n)
	{
		int max=Integer.MIN_VALUE;
		for(int i=0;i<n;i++)
		{
			if(a[i]>max)
				max=a[i];
		}
		return max;
	}
	public static int sum(int []a,int n)
	{
		int sum=0;
		for(int i=0;i<n;i++)
			sum+=a[i];
		return sum;
	}
	public static void frequencyOfElements(int []a,int n)
	{
		HashMap<Integer,Integer>h=new HashMap<>();
		for(int i=0;i<n;i++)
		{
			if(h.get(a[i])==null)
				h.put(a[i], 1);
			else
				h.put(a[i],h.get(a[i])+1);
		}
		System.out.print("Frequency of elements= ");
		for(Map.Entry i : h.entrySet())
		{
			Integer key = (Integer)i.getKey(); 
	        int value = ((int)i.getValue()); 
	        System.out.print(key + "-" + value+" "); 
	    } 
		System.out.println();
	}
	public static int countRepeatedElements(int []a,int n)
	{
		int c=0;
		HashMap<Integer,Integer>h=new HashMap<>();
		for(int i=0;i<n;i++)
		{
			if(h.get(a[i])==null)
				h.put(a[i], 1);
			else
				h.put(a[i],h.get(a[i])+1);
		}
		for(Map.Entry i : h.entrySet())
		{
			Integer key = (Integer)i.getKey(); 
	        int value = ((int)i.getValue()); 
	        if(value>1)
	        	c++;
	     
	    } 
		return c;
	}
	public static int countDistinctElements(int[]a,int n)
	{
		int c=0;
		HashMap<Integer,Integer>h=new HashMap<>();
		for(int i=0;i<n;i++)
		{
			if(h.get(a[i])==null)
				h.put(a[i], 1);
			else
				h.put(a[i],h.get(a[i])+1);
		}
		for(Map.Entry i : h.entrySet())
		{
			Integer key = (Integer)i.getKey(); 
	        int value = ((int)i.getValue()); 
	        if(value==1)
	        	c++;
	     
	    } 
		return c;
	}
	public static int countEven(int []a,int n)
	{
		int noOfEvenNumbers=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]%2==0)
				noOfEvenNumbers++;
		}
		return noOfEvenNumbers;
	}
	public static int countOdd(int []a,int n)
	{
		int noOfOddNumbers=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]%2!=0)
				noOfOddNumbers++;
		}
		return noOfOddNumbers;
	}
	public static void main(String args[])
	{
		Scanner s=new Scanner(System.in);
		System.out.println("Enter how many numbers you want to have:");
		int n=s.nextInt();
		int []a=new int[n];
		System.out.println("Enter the array elements:");
		for(int i=0;i<n;i++)
			a[i]=s.nextInt();
		System.out.println("Smallest Number: "+smallestNumberInArray(a,n));
		System.out.println("Largest Number: "+largestNumberInArray(a,n));
		System.out.println("Sum of Array elements= "+sum(a,n));
    	frequencyOfElements(a,n);
		System.out.println("Count of distinct elements= "+countDistinctElements(a,n));
		System.out.println("Count of repeating elements= "+countRepeatedElements(a,n));
		System.out.println("Count of Even Elements= "+countEven(a,n));
		System.out.println("Count of Odd Elements= "+countOdd(a,n));
	}

}
