// Applying KMP Algorithm
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // pat is the pattern string
    // str is the text string 
    string pat, str, mix;
    cin>>pat>>str;

    mix = pat + '#' + str;

    //prestr is the prefix array of the concatenated string of given pattern and text string
    int prestr[mix.size()];
    prestr[0]=0;

    for(int i=1; i<mix.size(); i++)
    {
        int j = prestr[i-1];
        while(j>0 && mix[i]!=mix[j])
            j = prestr[j-1];
        if(mix[j] == mix[i])
            j++;
        prestr[i]=j;
    }

    //cnt is the number of occurrences
    int s = pat.size(), cnt=0;
    for(int i=s+1; i<mix.size(); i++)
    {
        if(prestr[i] == s)
            cnt++;
    }

    cout<<cnt;
}
