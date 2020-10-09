//This program counts the frequency of digits in a string.
#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cout<<"Enter a string:-\n";
  cin>>s;
  int n,i;
  n = s.size();
  int occ[10]={0};
  for(i=0;s[i]!='\0';++i)
  {
    switch(s[i])
    {
      case '0': occ[0]++;
      		break;
      case '1': occ[1]++;
      		break;
      case '2': occ[2]++;
      		break;
      case '3': occ[3]++;
      		break;
      case '4': occ[4]++;
      		break;
      case '5': occ[5]++;
      		break;
      case '6': occ[6]++;
      		break;
      case '7': occ[7]++;
      		break;
      case '8': occ[8]++;
      		break;
      case '9': occ[9]++;
      		break;
    }
  }
  cout<<"\nThe occurences of the digits are as follows:-\n";
  for(i=0;i<10;++i)
  {
    cout<<i<<" - "<<occ[i]<<" times\n";
  }
  return 0;
}
