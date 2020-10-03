#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
}
void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
int main(){
  int n,test;
  cout<<"Program for Merge Sort\n\nEnter the number of test cases:"<<endl;
  cin>>test;
  for(int i=0;i<test;i++)
  { cout<<"Enter the size:"<<endl;
    cin >> n;
    int a[n];
    for (int i =0;i<n;i++)
      a[i]=rand()% 1000;
    clockid_t t;
    t=clock();
    mergeSort(a,0,n);
    t=clock()-t;
    double time_taken= (double(t))/CLOCKS_PER_SEC;
    for(int j=0;j<n;j++)
        cout<<a[j]<<" ";
    cout<<"\nTime taken is:"<<time_taken<<endl;
   }
return 0;
}
