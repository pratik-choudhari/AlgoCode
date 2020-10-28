#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// count of total permutations
int total = 0;

void permute(int i, string s)
{
	// base case
	if (i == (s.length() - 1)) {
		cout << s << endl;
		total++;
		return;
	}

	char prev = '*';

	// loop from j = 1 to length of string
	for (int j = i; j < s.length(); j++) {
		string temp = s;
		if (j > i && temp[i] == temp[j])
			continue;
		if (prev != '*' && prev == s[j]) {
			continue;
		}
	
		// swap the elements
		swap(temp[i], temp[j]);
		prev = s[j];
	
		// recursion call
		permute(i + 1, temp);
	}
}

int main()
{
	string s;
	cin >> s;
	// sort
	sort(s.begin(), s.end());

	// Function call
	permute(0, s);
	cout << "Total distinct permutations = " << total
		<< endl;
	return 0;
}

