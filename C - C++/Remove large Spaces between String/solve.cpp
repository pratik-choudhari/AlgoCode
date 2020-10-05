#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){

    string str,tmp;

    getline(cin,str); // read the single line

    stringstream ss(str); // used to split into tokens


    while(ss>>tmp){
        cout<<tmp<<" "; // output the string
    }
    cout<<"\n";
}

