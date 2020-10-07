/* WORD GAME */
#include<bits/stdc++.h>
 
#define ll long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
using namespace std;
             
int main(){
    int t;
    cin>>t;     // no. of test cases
    int i;
    string s[t];
   for(i=0;i<t;i++){
      cin>>s[i];              //array of strings
   }
   map<string,int> my_map;
    for ( i = 0; i < t; i++) 
        my_map[s[i]]++; 
       cout<<my_map.size()<<endl;  // prints no. of distinct strings
    vector<string> my_vector;           
    for (i = 0; i < t; i++) {
        if (find(my_vector.begin(), my_vector.end(), s[i]) == my_vector.end()) {

            cout << my_map[s[i]] << " ";   //prints frequency of each string

            my_vector.push_back(s[i]);
        }

    }
 
   return 0;
}
