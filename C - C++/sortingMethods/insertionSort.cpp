#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n)
{
	for(int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while(j >= 0 and arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
int main()
{
    int t,n;
    cout<<"Program for Insertion Sort \n \nHow many cases?"<<endl;
    cin>>t;
	for(int i=0;i<t;i++)
    {
        cout<<"Enter N :";
        cin>>n;
        int arr[n];
        for(int i = 0; i < n; i++)
            arr[i] = rand() % 1000;
        clock_t t;
        t = clock();
        insertion_sort(arr, n);
        t = clock() - t;;
        double time_used = (double(t))/CLOCKS_PER_SEC;
        for(int j=0;j<n;j++)
            cout<<arr[j]<<" ";
        cout<<"\nTime for N = "<<n<<" is "<<time_used<<endl;
    }
	return 0;
}
