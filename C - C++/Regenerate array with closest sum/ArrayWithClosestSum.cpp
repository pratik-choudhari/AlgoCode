#include <iostream>
using namespace std;

int main() {

    int n,i;
    cout<<"Enter the number of elements in the array : ";
    cin>>n;
    int arr[n],sum=0;
    cout<<"\nEnter the elements of the array : ";
    for(i=0;i<n;i++)
    cin>>arr[i];

    for(i=0;i<n;i++)
    sum = sum + arr[i];

    cout<<"\nThe minimum value to be assigned to the elements so that the sum becomes greater than the initial sum is "<<((sum/n)+1)<<"\n";



	// your code goes here
	return 0;
}
