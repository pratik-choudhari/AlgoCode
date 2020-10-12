#include <bits/stdc++.h>

using namespace std;
//funtion to print floyd's triangle
void floyds(int n)
{
    int x = 1;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<=i; j++)
            cout<<x++<<" ";
        cout<<endl;
    }
}
int main()
{
    //Floyd’s triangle, named after Robert Floyd, is a right-angled triangle that is made up using natural numbers. It starts from 1 and consecutively selects the next greater number in the sequence. 
    int t;
    cout<<"Enter the number of test cases."<<endl;
    cin>>t;
    while(t--)
    {
        int n;
        cout<<"Enter the number of rows."<<endl;
        cin>>n;
        floyds(n);

    }
    return 0;
}
