#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm> 
#include <cmath>
#include <cstdlib>
using namespace std;
#define ll long long 
#define gc getchar_unlocked
const ll int INF = 1e18;
const int MOD = 1000000007;

int N;
vector<ll> v(1e6+1); 
double round(double x) 
{
    double val = (int)(x*100 + 0.5); 
    return (double)val/100; 
}
int main()
{
    cout<<"Enter the number of elements : ";
    cin>>N;
    v.resize(N); 
    int i; 
    ll mx = INT_MIN; 
    ll mn = INT_MAX; 
    ll sum = 0;
    cout<<"\nEnter the numbers :\n"; 
    for(i=0;i<N;i++)
    {
        cin>>v[i];
        sum += v[i]; 
        mx = max(mx,v[i]); 
        mn = min(mn,v[i]);
    }
    double mean = (sum*1.0)/N; 
    ll range = (mx-mn); 

    double variance = 0; 
    for(i=0;i<N;i++)
    {
        variance += (v[i]*1.0-mean)*(v[i]*1.0-mean);
    }
    variance /= N; 
    double sd = pow(variance,0.5); 

    cout<<"\n";
    cout<<"Range : "<<range<<"\n";
    cout<<"Variance : "<<round(variance)<<"\n"; 
    cout<<"Standard Deviation : "<<round(sd)<<"\n";
    return 0;
}
