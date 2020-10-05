/* Language  C++ 17  */
#include<bits/stdc++.h>
using namespace std;


void solve(string s,int idx){

    if(idx==s.length()){
        cout<<s<<endl; // if all the '?' have been matched we have found one combination
        return;
    }
    if(s[idx]=='?')
    {
        s[idx]='0';  // try '?'----> '0'
        solve(s,idx+1); // apply recursion for the rest of the string
        s[idx]='1'; // try '?' ---> '1'
        solve(s,idx+1); // apply recursion for the rest of string
    }
    else{
        solve(s,idx+1); // if the input is 0 or 1 then just skip and go to next index
    }

}


int main(){

    string s;
    cin>>s; // take the input

    solve(s,0); // helper function

}
