/*	Language - cpp 
	This code takes 2 strings as inputs and tells
	if they are anagrams 
	Note: all letters must be Lowercase/Uppercase */

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isAnagram(string a, string b){

	// Logic - After sorting if the two strings are equal, they are anagrams. 

	// Sort stl in the algorithms header file is used for sorting. 
	// Sorting of a strings means alphabetically, i.e. bcda after sorting become abcd 
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	return a == b;
}

int main()
{
	/* code */
	string a, b;
	cout << "Enter the two strings\n";
	// Taking input
	cin >> a >> b;

	// Function returns true if the strings are anagrams. 
	if(isAnagram(a, b)){
		cout << a << " & " << b << " are anagrams.";
	} else {
		cout << a << " & " << b << " are NOT anagrams.";
	}
	return 0;
}

// Author - Utkarsh Bajaj