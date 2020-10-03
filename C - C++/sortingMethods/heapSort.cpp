#include <bits/stdc++.h>

using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x= *y;
    *y= temp;
}
void heapify(int arr[], int N, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < N && arr[left] > arr[largest])
        largest = left;
    if (right < N && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}
void heapSort(int arr[], int n)
{
    for(int i = n/2 -1;i>=0;i--)
        heapify(arr, n, i);
    for(int i=n-1;i>0;i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
int main()
{
    long int n,test;
    cout<<"Program for Heap Sort\n\nEnter the number of test cases:"<<endl;
    cin>>test;
    for(int i=0;i<test;i++)
    {
        cout<<"Enter the size:"<<endl;
        cin>>n;
        int arr[n];
        for(int j=0; j<n; j++)
            arr[j]= rand()% 1000;
        clockid_t t;
        t = clock();
        heapSort(arr, n);
        t= clock()-t;
        double time_taken = (double(t))/CLOCKS_PER_SEC;
        for(int j=0; j<n; j++)
            cout << arr[j] << " ";
        cout<<"Time taken:"<<time_taken<<endl;
    }
    return 0;
}
