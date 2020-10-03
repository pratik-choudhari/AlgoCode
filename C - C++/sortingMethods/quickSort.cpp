#include<bits/stdc++.h>
#include<ctime>

using namespace std;

void swap( int *a,int *b)
{
    int temp = *a;
    *a= *b;
    *b = temp;
}

int partition(int arr[], int p, int r)
{
    int x= arr[r];
    int i= p-1;
    for(int j=p;j<r;j++)
    {
        if(arr[j]<=x)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}

void quicksort(int arr[],int p, int r)
{   int q;
    if(p<r)
    {
        q = partition(arr,p,r);
        quicksort(arr,p,q-1);
        quicksort(arr,q+1,r);
    }
}
int main()
{
    int N,test;
    cout<<"Program for QuickSort \n \nEnter number of test cases"<<endl;
    cin>>test;
    for(int i=0;i<test;i++)
    {
        cout<<"How many numbers?"<<endl;
        cin>>N;
        int a[N];
        srand(time(0));
        for(int i=0;i<N;i++)
            a[i]=rand() % 1000;
        double time_taken;
        clockid_t t;
        t=clock();
        quicksort(a,1,N-1);
        t=clock() - t;
         for(int j=0;j<N;j++)
            cout<<a[j]<<" ";
        time_taken = (double(t))/CLOCKS_PER_SEC;
        cout<<"\n\NTime taken is :"<<time_taken<<endl;
    }
return 0;
}
