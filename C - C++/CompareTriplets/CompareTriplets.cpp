#include <iostream>
using namespace std;

int main() {
	// declaring placeholder variables
	int scores[2] = {0, 0};
	int a[3], b[3];
	
	// reading in values for a
	for(unsigned int i = 0; i < 3; i++) {
		cin >> a[i];
	}
	
	// reading in values for b
	for(unsigned int i = 0; i < 3; i++) {
		cin >> b[i];
	}
	
	// comparing scores
	for(unsigned int i = 0; i < 3; i++) {
		if(a[i] > b[i]) scores[0] += 1; //adding for a if a is bigger
		else if (a[i] < b[i]) scores[1] += 1; //adding for b if b is bigger
	}
	
	// output
	cout << scores[0] << " " << scores[1];
	
}
