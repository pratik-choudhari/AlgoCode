#include <bits/stdc++.h>

using namespace std;

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
