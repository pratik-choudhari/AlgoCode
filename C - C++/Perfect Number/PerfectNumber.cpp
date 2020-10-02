/*Find all perfect number less than n
Input: 500
Output: 6 28 496*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int i, j, sum,n;
    cin>>n;
    for(i=1; i<n; i++)
    {
        sum = 0;
        for(j=1; j<i; j++)
        {
            if(i % j == 0)
            {
                sum += j;
            }
        }
        if(sum == i)
        {
            printf("%d ", i);
        }
    }
  return 0;
}
