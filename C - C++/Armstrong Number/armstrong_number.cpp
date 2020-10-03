#include <bits/stdc++.h>
using namespace std;

//Function to find length of a number
int length(int x)
{
    int count=0;
    while(x>0)
    {   
        count++;
        x=x/10;
    }
    return count;
}

//Function to check whether a no is an armstrong no or not
bool check_armstrong(int val)
{
    int l = length(val), sum = 0, temp=val;
    while(temp>0)
    {
        int r=temp%10;
        //Using math - pow() inbuilt function for computing powers
        sum += pow(r,l); 
        temp = temp/10;
    }
    if(sum==val)    return true;
    else            return false;
}

int main(){
    //An Armstrong number is the one whose sum of mth power of every digit in the number is equal to number itself
    //Find all armstrong numbers less than n
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        if(check_armstrong(i)){
            cout<<i<<" ";
        }
    }
    return 0;
}