#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arraySize;
    cin>>arraySize;
    vector<int> v(arraySize);
    for(int i=0;i<arraySize;i++)
    {
        cin>>v[i];
    }
    vector<int>suffix,prefix;
    int prefix_temp=0;
    for(int i=0;i<arraySize;i++)
    {
        prefix_temp+=v[i];
        prefix.push_back(prefix_temp);
    }

    int suffix_temp=0;
    for(int i=arraySize-1;i>=0;i--)
    {
        suffix_temp+=v[i];
        suffix.push_back(suffix_temp);
    }
    reverse(suffix.begin(),suffix.end());
    cout<<"Prefix - ";
    for(auto i:prefix)
    {
        cout<<i<<' ';
    }
    cout<<endl;
    cout<<"Suffix - ";
    for(auto i:suffix)
    {
        cout<<i<<' ';
    }
    cout<<endl;
}
