//For a given number n, find the maximum number of distinct prime factors for numbers in range [1,n]
//Example
//Input: 100
//Output: 3
//Explanation: 30, 42 has 3 prime factors, no other number has more than 3 distinct prime factors in range [1, 100]
//@author - sushant19-99


import java.io.*;

public class Charlie_Prime_Factors
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter value of N for the upper range limit");
        int n=Integer.parseInt(br.readLine());      //taking input from user for value of N
        int ans=MaxPrimeFactors(n);
        System.out.println(ans);        
        
    }
    
    public static int MaxPrimeFactors(int n)
    {
        if(n<2)
            return 0;
        
        //creating a prime sieve to to get all prime numbers from 1 to n
        int[] sieve= new int[n+1];          
        int prod=1,res=0;
        sieve[2]=1;
        for(int i=3;i<=n;i+=2)
            sieve[i]=1;
            
        for(int i=3;i<=n;i+=2)
        {
            if(sieve[i]==1)
            {
                for(int j=i*i;j<=n;j+=i)
                {
                    if(sieve[j]==1)
                        sieve[j]=0;
                }
            }
        }
        
        //maximum no of unique factors will be product of all prime numbers starting from 2 until the product is less than n
        for(int i=2;i<=n;i++)
        {
            if(sieve[i]==1)
            {
                prod=prod*i;
                if(prod>n)
                    return res;
                res++;
            }    
        }
        return res;
    }
}       