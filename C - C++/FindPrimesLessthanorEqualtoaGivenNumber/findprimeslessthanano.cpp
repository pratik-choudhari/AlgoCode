#include<iostream>
#include<vector>
using namespace std;
int main()
{
    //Taking input 
    int n,i,j;
    cin>>n;
    //Create a boolean vector to store a boolean value which indicates if the 'index' is prime or not.(Here the index indicates the prime number)
    //Initially we make the vector as true.Now we mark all the non-prime numbers as false using Sieve of Eratosthenes approach
    vector<bool> isprime(n+1,true);
    isprime[0]=false;
    isprime[1]=false;
    for(i=2;i<=n;i++)
    {
        //Now we mark all multiples of prime numbers as false
        for(j=i+i;j<=n;j=j+i)
        {
            isprime[j]=false;
        }
    }
    //Finally we display all prime numbers (indices of the array which hold true boolean value)
    for(i=0;i<=n;i++)
    {
        if(isprime[i]==true)
        cout<<i<<" ";
    }
    cout<<endl;
}