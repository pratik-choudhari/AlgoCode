#include <bits/stdc++.h> 
using namespace std; 
  
void compress(string s){ 
    for (int i = 0; s[i] != '\0'; i++){ 
      //counting occurrences of s[i]
        int count = 1; 
        while (s[i] == s[i + 1]){ 
            i++; 
            count++; 
        } 
        cout << "(" << s[i] << "," << count << ")"; 
    } 
   
} 

int main(){
string str;
cout<<"Enter a string"<<endl;
cin>>str;
compress(str);
return 0;
}
