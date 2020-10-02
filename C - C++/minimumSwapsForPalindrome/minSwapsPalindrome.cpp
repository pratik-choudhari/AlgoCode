// Problem Statement - Find minimum number of swaps to make a string Palindrome.
// Input Format - String
// Output Format - Integer

// Samaple Input 1 - niitn
// Sample Output 1 - 1

// Sample Input 2 - deideif
// Sample Output 2 - 2

// Below is an iterative solution using Brute force. We take two pointers left and right 
// We see char of left is present again by iterating right to the left else we return -1.

#include<bits/stdc++.h>
using namespace std;

int countSwaps(string s)
{

    int n = s.length(); 
      
    // counter to count minimum swap 
    int count = 0; 
  
    // A loop which run till mid of 
    // string  
    for (int i = 0; i < n / 2; i++) { 
        // Left pointer 
        int left = i; 
  
        // Right pointer 
        int right = n - left - 1; 
  
        // A loop which run from right 
        // pointer towards left pointer 
        while (left < right) { 
            // if both char same then 
            // break the loop. 

            if (s[left] == s[right]) { 
                break; 
            } 
            else { 
                right--; 
            } 
        } 
  
        // If both pointers are same 
        // it means that we 
        // don't have enough characters 
        // to make palindrome string 
        if (left == right) { 
            return -1; 
        } 
          
        // else swap and increase the count 
        for (int j = right; j < n - left - 1; 
                j++) { 
            swap(s[j], s[j + 1]); 
            count++; 
        } 
    } 
  
    return count; 
}
int main()
{
    string s;
    //take input
    cin>>s;

    int ans=countSwaps(s);
    
    cout<<ans;
    return 0;
}