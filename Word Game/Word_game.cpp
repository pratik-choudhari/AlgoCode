#include<bits/stdc++.h>
 
#define ll long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
using namespace std;
             
int main(){
    int t;
    cin>>t;
    int i;
    string s[t];
   for(i=0;i<t;i++){
      cin>>s[i];
   }
   map<string,int> my_map;
    for ( i = 0; i < t; i++) 
        my_map[s[i]]++; 
       cout<<my_map.size()<<endl;
    vector<string> my_vector;
    for (i = 0; i < t; i++) {
        if (find(my_vector.begin(), my_vector.end(), s[i]) == my_vector.end()) {
            cout << my_map[s[i]] << " ";
            my_vector.push_back(s[i]);
        }

    }
 
   return 0;
}
#include<bits/stdc++.h>
 
#define ll long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
using namespace std;
             
int main(){
    int t;
    cin>>t;
    int i;
    string s[t];
   for(i=0;i<t;i++){
      cin>>s[i];
   }
   map<string,int> my_map;
    for ( i = 0; i < t; i++) 
        my_map[s[i]]++; 
       cout<<my_map.size()<<endl;
    vector<string> my_vector;
    for (i = 0; i < t; i++) {
        if (find(my_vector.begin(), my_vector.end(), s[i]) == my_vector.end()) {
            cout << my_map[s[i]] << " ";
            my_vector.push_back(s[i]);
        }

    }
 
   return 0;
}
