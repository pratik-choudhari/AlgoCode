#include<bits/stdc++.h>
using namespace std;

int main()
{
	//Taking n as input
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0; i<n; i++)
		cin>>v[i];
	int pos = 1;
	while(pos<v.size())
	{
		for(int i=0; (i+pos)<v.size(); i++)
		{
			v.erase(v.begin()+i+pos);
			i=i+pos-1;
		}
		pos++;
	}

	//Print lucky numbers
	for(int j=0; j<v.size(); j++)
		cout<<v[j]<<" ";
}