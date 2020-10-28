#include <bits/stdc++.h>
using namespace std;

// Returns true if str[curr] does not matches with any of the
// characters after str[start]
bool shouldSwap(char str[], int start, int curr)
{
	for (int i = start; i < curr; i++) 
		if (str[i] == str[curr])
			return 0;
	return 1;
}

// Prints all distinct permutations in str[0..n-1]
void findPermutations(char str[], int index, int n)
{
	if (index >= n) {
		cout << str << endl;
		return;
	}

	for (int i = index; i < n; i++) {

		// Proceed further for str[i] only if it 
		// doesn't match with any of the characters
		// after str[index]
		bool check = shouldSwap(str, index, i);
		if (check) {
			swap(str[index], str[i]);
			findPermutations(str, index + 1, n);
			swap(str[index], str[i]);
		}
	}
}

int main()
{
    int n;
    cout<<"Enter the length of the String";
    cin>>n;
    char str[n];
    cout<<"Enter String \n";
	  cin>>str;
    cout<<"Permutations are : \n";
	  findPermutations(str, 0, n);
  	return 0;
}
