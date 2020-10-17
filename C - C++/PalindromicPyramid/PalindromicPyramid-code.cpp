#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter number of row:\n";
    cin>>n;
    int i,j,k;
    //here i represents the row	
    for(int i=0;i<n;i++){
        for(int j=1;j<=i+1;j++){
            cout<<j;
        }
        for(int k=i;k>0;k--){
            cout<<k;
        }
        cout<<"\n";
    }
    return 0;
}
