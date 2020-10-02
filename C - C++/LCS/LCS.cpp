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
#define inf 100000000000000009
#define endl "\n"

signed main()
{
 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
 
    string s,t;
    cin>>s;
    cin>>t;

    int n = s.length();
    int m = t.length();

    int dp[n+1][m+1];

    for (int i = 0; i <=n; ++i)
    {
        for (int j = 0; j <=m; ++j)
        {
            if(i==0 || j==0)
                dp[i][j] = 0;
            else
                dp[i][j] = max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1] + ((s[i-1]==t[j-1]) ? 1 : 0)));
        }
    }

    //cout<<dp[n][m]<<endl;

    string ans = "";

    int i=n, j=m;

    while(i>0 && j>0)
    {
        if(s[i-1] == t[j-1])
        {
            ans+=s[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

    reverse(ans.begin(), ans.end());

    cout<<ans;
 
    return 0;
   
}