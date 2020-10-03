#include <bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
    {
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
     }
    }
}

int main()
{   int n,test;
    cout<<"Program for Bubble Sort\n\nEnter number of test cases:"<<endl;
    cin>>test;
    for(int i=0;i<test;i++)
    {
        cout<<"\nEnter the size:"<<endl;
        cin>>n;
        int a[n];
        srand(time(0));
        for(int j=0;j<n;j++)
            a[j]=rand()%1000;
        clockid_t t;
        t=clock();
        bubbleSort(a,n);
        t=clock()-t;
        double time_taken = (double(t))/CLOCKS_PER_SEC;
        cout<<"Time taken:"<<time_taken<<endl;
    }
    return 0;
}
