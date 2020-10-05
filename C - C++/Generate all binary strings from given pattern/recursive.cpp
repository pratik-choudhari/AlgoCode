#include<bits/stdc++.h>
using namespace std;


void solve(string s,int idx){

    if(idx==s.length()){
        cout<<s<<endl;
        return;
    }
    if(s[idx]=='?')
    {
        s[idx]='0';
        solve(s,idx+1);
        s[idx]='1';
        solve(s,idx+1);
    }
    else{
        solve(s,idx+1);
    }

}


int main(){

    string s;
    cin>>s;

    solve(s,0);

}
