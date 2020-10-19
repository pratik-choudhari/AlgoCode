#include <iostream>
#include<algorithm>

using namespace std;

bool compare(int a,int b) //Comparator Function
{
    cout<<"Comparing"<<a<< "and "<<b<<endl;
    return a>b;
}
sort(a,n,compare);

int main()
{
    int n,key;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<",";
    }

    return 0;
}
