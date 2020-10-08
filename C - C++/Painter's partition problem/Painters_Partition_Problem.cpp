// This arena belongs to WhiteDeath99

#include<bits/stdc++.h>
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr)
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

bool isPossible(long long int mid, vector<int> C, int paint)
{
    int maxi = 0;
    for(int i = 0; i < C.size(); i++)
    {
        if(C[i] > maxi)
        {
            maxi = C[i];
        }
    }
    
    if(maxi > mid)
    {
        return false;
    }
    
    long long int sum = 0;
    int count = 1;
    
    for(int i = 0; i < C.size();)
    {
        if((sum + (long long int)C[i]) > mid)
        {
            count++;
            sum = 0;
        }
        else
        {
            sum = sum + (long long int)C[i];
            i++;
        }
    }
    
    if(count <= paint)
    {
        return true;
    }
    
    return false;
}

int main()
{
	IOS;

	clock_t startTime=clock();

	int A,B,N;
	vector<int> C;

	cin>>A>>B>>N;

	rep(i,0,N)
	{
		int ele;
		cin>>ele;
		C.push_back(ele);
	}

	long long int start = 0, end = 0;
    
    for(int i = 0; i < C.size(); i++)
    {
        end = end + C[i];
    }
    
    long long int sol = INT_MAX;
    
    while(start <= end)
    {
        long long int mid = start + (end - start)/2;
        if(isPossible(mid, C, A))
        {
            sol = min(sol, mid);
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    
    cout<<(int)((sol * (long long) B) % 10000003);

	cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

}//See'ya soon.