#include<iostream>
using namespace std;
int main() 
{
	long int N,n,m;
	cin>>N;
	if(N % 2 ==  0)
	{
		m = N / 2;
		n = 1;
		if(m > 0 and m > n)
		{
			cout<<(m*m - n*n)<<" "<<(m*m + n*n);
			return 0 ;
		}
		else
		{
	        cout<<"-1";
	        return 0;
		}
		
	}
	else
	{
		n = (N - 1)/2;
		m = (N + 1)/2;

		if(n > 0 and m > n)
		{
			cout<<(2*m*n)<<" "<<(m*m + n*n);
			return 0;
		}
		else
		{
	        cout<<"-1";
	        return 0;
		}

	}
	cout<<"-1";
	

	return 0;
}