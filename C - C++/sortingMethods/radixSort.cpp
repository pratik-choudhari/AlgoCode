#include<bits/stdc++.h>
using namespace std;

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
int main()
{   long int n,test;
    cout<<"Program for Radix Sort \n\nEnter the number of test cases:"<<endl;
    cin>>test;
    for(int i =0;i<test;i++)
    {
        cout<<"Enter the size:"<<endl;
        cin>>n;
        int arr[n];
        srand(time(0));
        for (int j= 0; j < n; j++)
            arr[j]=rand() %1000;
        clockid_t t;
        t=clock();
        radixsort(arr, n);
        t=clock()-t;
        double time_taken = (double(t))/CLOCKS_PER_SEC;
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout<<"Time taken is :"<<time_taken<<endl;
    }
    return 0;
}
