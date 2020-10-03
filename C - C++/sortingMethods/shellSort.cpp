#include <bits/stdc++.h>

using namespace std;


int shellSort(int arr[], int n)
{
    for(int gap=n/2;gap>0;gap=gap/2)
    {
        for(int i=gap;i<n;i++)
        {
            int temp = arr[i];
            int j;
            for (j =i;(j>=gap)&&(arr[j-gap]>temp);j=j-gap)
                arr[j] = arr[j-gap];
            arr[j] = temp;
        }
    }
    return 0;
}
int main()
{
    long int n,test;
    cout<<"Program for Shell Sort \n\nEnter the number of test cases:";
    cin>>test;
    for(int i=0;i<test;i++)
    {
        cout<<"Enter the size:"<<endl;
        cin>>n;
        int a[n];
        for(int j=0;j<n;j++)
            a[i]=rand()% 1000;
        clockid_t t;
        t= clock();
        shellSort(a,n);
        t=clock()-t;
        double time_taken = (double(t))/CLOCKS_PER_SEC;
        for(int j=0;j<n;j++)
            cout<<a[j]<<" ";
        cout<<"\nTime taken is "<<time_taken<<endl;
    }
    return 0;
}
