#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[],int n)
{   int temp;
    for(int i=0;i<n-1;i++)
    {
        int min_=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_])
                min_=j;
        }

        temp=arr[i];
        arr[i]=arr[min_];
        arr[min_]=temp;
    }
}

int main()
{   int N,test;
    cout<<"Program for Selection Sort \n\nEnter the number of test cases?";
    cin>>test;
    for(int i=0;i<test;i++)
    {
        cout<<"\nEnter the size"<<endl;
        cin>>N;
        int a[N];
        srand(time(0));
        for(int j=0;j<N;j++)
            a[i]=rand();
        clockid_t t;
        double time_taken;
        t= clock();
        selectionSort(a,N);
        t= clock()- t;
        time_taken = (double(t))/CLOCKS_PER_SEC;
        for(int j=0;j<N;j++)
            cout<<a[j]<<" ";
        cout<<"\nTime taken is:"<<time_taken<<endl;
    }
    return 0 ;
}
