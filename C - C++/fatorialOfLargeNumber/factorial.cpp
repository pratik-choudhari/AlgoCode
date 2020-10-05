#include <iostream>
using namespace std;
int main()
{
   int t;
   cin>>t;
   while(t--){
       int n,size=200,fact[size],j=size-1,carry=0;
       cin>>n;
       fact[size-1]=1;
       while(n>1){
           int x;
           for(int k=size-1;k>=j;k--){
               x=fact[k]*n+carry;
               fact[k]=x%10;
               carry=x/10;}
            while(carry>0){
                fact[--j]= carry%10;
                carry/=10;}
            n--;    
       }
       for(int k=j;k<size;k++){
           cout<<fact[k];
        }
       cout<<endl;    
    }
  return 0;
}

