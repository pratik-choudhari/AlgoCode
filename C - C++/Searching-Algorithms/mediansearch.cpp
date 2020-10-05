/ Hacktoberfest2020 Contribution by Dhrubajyoti Chakraborty
// Median Search implementation

#include <bits/stdc++.h> 
using namespace std; 
  
// Function for calculating median 
double medianSearch(int a[], int n) 
{ 
    // sort the array 
    sort(a, a + n); 
  
    // Check for even case 
    if (n % 2 != 0) 
        return (double)a[n / 2]; 
  
    return (double)(a[(n - 1) / 2] + a[n / 2]) / 2.0; 
} 
   
int main() 
{ 
    int a[] = { 1, 3, 4, 2, 7, 5, 8, 6 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    cout << "Median: " << medianSearch(a, n) << endl; 
    return 0; 
} 
