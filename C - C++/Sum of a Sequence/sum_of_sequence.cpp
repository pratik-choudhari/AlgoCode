#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){


ll n;

cout<<"Input: ";
cin>>n;

ll ans=n*n;

cout<<"Output:\n";
cout<<"Sequence: ";

ll start=1;

while(n--){
    cout<<start<<" ";
    start+=2;
}

cout<<"\nSum: "<<ans<<endl;

}
