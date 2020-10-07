//AnkitCode99 here....

#include<bits/stdc++.h>
#define endl "\n"
#define Ryuga ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr)
typedef long long int ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back

using namespace std;

const ll sz=1e5+5;
const ll szz=1e6+6;
const ll mod=1e9+7;

ll n,mat[1005][1005],dp[1005][1005];

ll path(ll i,ll j)
{
	if(i==n-1 and j==n-1)
		return 1;

	if(i>=n or j>=n or mat[i][j]==0)
		return 0;

	if(dp[i][j]!=-1)
		return dp[i][j];

	return dp[i][j]=(path(i+1,j)+path(i,j+1))%mod;
}

int main()
{
	Ryuga;

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("op.txt","w",stdout);
	#endif

	clock_t startTime=clock();

	cin>>n;
	memset(dp,-1,sizeof dp);
	
	rep(i,0,n)
	{
		rep(j,0,n)
		{
			cin>>mat[i][j];
		}
	}

	cout<<path(0,0)<<endl;

	cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

}//Goodbye...