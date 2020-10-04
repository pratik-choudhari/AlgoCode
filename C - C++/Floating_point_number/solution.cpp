//Author : @shashankseth01
//A simple program to identify a floating point number


#include <iostream>

using namespace std;

int main()
{
    string s;
    unsigned int i,flag=0,count=0,pos,t=0,size=0; // no need to take signed int as the input is compared as characters
    cout<<"Enter any number ";
    cin>>s;
    if(s[0]=='+' || s[0]=='-'){
        t=1;
    }
    for(i=0;i<s.length();i++){
       if(s[i]=='.'){
           count++;
           pos=i+1;
       }
    }
    if(count!=1 || pos==s.length()){
        cout<<"No";
        return 0;
    }
    for(i=0+t ;i<s.length();i++){
       if(s[i]>'9' || s[i]=='-' || s[i]=='+'){
           flag=1;
           break;
        }
    }
    if(flag==1){
        cout<<"No";
        return 0;
    }       
    else
    cout<<"Yes";
    return 0;
}


