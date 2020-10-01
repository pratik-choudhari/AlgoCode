// Problem Statement - Find minimum number of changes to make a bit string with alternate values.
// Input Format - Binary string
// Output Format - Integer

// Samaple Input 1 - 011101
// Sample Output 1 - 1

// Sample Input 2 - 100101000
// Sample Output 2 - 3

// Below is an iterative solution using dynamic programming. We use 2 arrays to store the 2 possible cases of bit patterns. 
// Asymptotics - O(2 * |s|) where |s| is the length of the input binary string bits

#include <iostream>
#define MAXN 100007
using namespace std;

// Stores the input string of bits.
string s;

// Will store the length of the input binary string of bits
int sz;

// 2-D array for storing the values toceach subproblem.
// Here, cache[i][0] and cache[i][1] is the number of changes needed in bits from i to s.length() if the last bit is 0 and 1 respectively.
// Considering maximum length of the string to be 1e5 + 7.
int cache[MAXN][2];

int main() {
	// Taking input of binary string bits.
	cin >> s;

	sz = s.length();

	// This variable is used to toggle and check the bits as per our needs.

	int toggle = 0;
	for (int i = sz - 1; i >= 0; i --) {
		cache[i][0] = cache[i + 1][0] + (toggle ^ (s[i] - '0'));
		toggle ^= 1;
	}

	// Now we check for last bit starting with 1
	toggle = 1;
	for (int i = sz - 1; i >= 0; i --) {
		cache[i][1] = cache[i + 1][1] + (toggle ^ (s[i] - '0'));
		toggle ^= 1;
	}

	// Final answer will be minimum of cache[0][0] and cache[0][1]
	cout << "Minimum changes required - "<< min(cache[0][0], cache[0][1]);
	return 0;
}
