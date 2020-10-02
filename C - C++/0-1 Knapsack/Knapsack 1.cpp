#include<bits/stdc++.h> 
using namespace std;
 
#define ull unsigned long long
#define int long long
#define ld long double
#define pb push_back
#define pi  pair< int,int >
#define ff first
#define ss second
#define mod 1000000007
#define endl "\n"
 
signed main()
{
 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
 
    int N,W;
    int w[105];
    int v[105];
    cin>>N>>W;
    for(int i=1; i<=N; i++)
    {
        cin>>w[i];
        cin>>v[i];
    }

    vector<int> dp[W+1];

    for(int i=0; i<=W; i++)
    {
        for(int j=0; j<=N; j++)
        {
            if(i==0 || j==0)
                dp[i].pb(0);
            else if(w[j] > W)
            {
                dp[i].pb(dp[i][j-1]);
                continue;
            }
            else
            {
                if(i-w[j]>=0)
                    dp[i].pb(max(dp[i-w[j]][j-1] + v[j], dp[i][j-1]));
                else
                    dp[i].pb(dp[i][j-1]);
            }
        }
    }

    cout<<dp[W][N]<<endl;
 
    return 0;
   
}