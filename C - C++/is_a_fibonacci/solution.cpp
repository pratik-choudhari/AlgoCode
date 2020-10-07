#include<iostream>
#include<cmath>
using namespace std;

//Approach 1
int Is_Fibonacci1(int &num){
	int m=5*num*num+4;
	if(ceil(sqrt(m))==floor(sqrt(m)))
	    return 1;
	else if(ceil(sqrt(m-8))==floor(sqrt(m-8)))
	    return 1;
	else
	    return 0;
}

//Approach 2
int Is_Fibonacci2(int &num){
    int a = 0,b=1,c;
    if (num==a || num==b)
		return 1;
    c = a+b;
    while(c<=num){
        if(c == num)
		    return 1;
        a = b;
        b = c;
        c = a + b;
    }
    return 0;
}
int main(){
    int t;//no of test
    cin>>t;
    while(t--){
    	int n;//number to be checked is a fibonacci no or not
    	cin>>n;
    	int ans=Is_Fibonacci1(n);
    	if(ans==1)
    	   cout<<"\nTRUE";
    	else
    	   cout<<"\nFALSE";
	}
	return 0;
}
