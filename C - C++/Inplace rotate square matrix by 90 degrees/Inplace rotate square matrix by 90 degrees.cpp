#include<bits/stdc++.h>
using namespace std;
void rotate(vector< vector<int> >& a) {
        int temp;
        int n=a[0].size();
        int y=n/2;
        //first create the upside down version of the matrix
        for(int i=0;i<y;i++)
            for(int j=0;j<n;j++)
            {
                temp=a[i][j];
                a[i][j]=a[n-i-1][j];
                a[n-i-1][j]=temp;
            }
         //upon this perform transpose operation   
        for(int i=0;i<n;i++)
            for(int j=0;j<i;j++)
            {
                temp=a[i][j];
                a[i][j]=a[j][i];
                a[j][i]=temp;
            }
    }
//Driver function
int main()
{
	int n;
	cout<<"Enter the matrix size: ";
	cin>>n;
	vector< vector<int> >a(n,vector<int>(n));
	
	//input of the matrix
	for(int i=0;i<n;i++)
	  for(int j=0;j<n;j++)
	     cin>>a[i][j];
	     
	//call to rotate the matrix in place     
	rotate(a);
	
	//output
	cout<<"The rotated matrix is:\n";
	for(int i=0;i<n;i++)
	{
	  for(int j=0;j<n;j++)
	     cout<<a[i][j]<<' ';
	  cout<<'\n';
    }
    return 0;
}
