//Problem statement - Given base b and a of a triangle as integers, find minimum integer height
// Input format -> base followed by area
// Input: 17 100
// Output: 12

// Input: 2 2
// Output: 2

#include <bits/stdc++.h> 
using namespace std; 
  
// function to calculate minimum height of triangle 
int minHeight(int base, int area){ 
    //area of triangle is A = bh/2
    return ceil((float)(2*area)/base); 
} 
  
int main() { 
    int base, area;
    cin>>base>>area;
    cout<<minHeight(base, area); 
    return 0; 
} 