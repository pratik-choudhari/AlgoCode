#include<iostream>
using namespace std;

void rotate(int *arr,int n,int d)
{
  int temp[d];
  for (int i=0;i<d;i++)
  {
    temp[i]=arr[i];
  }

  int x=0;
  for(int j=d;j<n;j++)
  {
    arr[x]=arr[j];
    x++;
  }
  
  x=0;
  for (int k=n-d;k<n;k++)
  {
    arr[k]=temp[x];
    x++;
  }
  
}
  

int main()
{
  int n,d;
  
  cout<<"Enter size\n";
  cin>>n;
  
  int arr[n];
  cout<<"Elements \n";
  for (int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  
  cout<<"Enter the value of d\n";
  cin>>d;
  
  rotate(arr,n,d); 
    
  for (int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  
  
  return 0;
}