#include <bits/stdc++.h>
using namespace std;

int main() {
	cout<< "Enter number of rows: ";
	int nrows;
	cin>>nrows;
	cout<<'\n';

	vector<int> row(1, 1);

	for(int i = 0; i < nrows; i++) {
		vector<int> newRow;
		for(int j = 0; j < row.size(); j++) {
			cout<<row[j]<<" ";

			if(j==0) newRow.push_back(1);
			else newRow.push_back(row[j] + row[j-1]);
			if(j==row.size()-1)newRow.push_back(1);
		}
		cout<<'\n';
		row = newRow;
	}
}


