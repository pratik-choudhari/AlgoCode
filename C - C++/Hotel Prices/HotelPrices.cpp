#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	long long total_cost = 0;

	while (t--) {
		string room_type;
		int bedrooms, bathrooms;
		cin >> room_type >> bedrooms >> bathrooms;
		long long cost = (5 * bedrooms) + (2 * bathrooms);

		if (room_type == "luxury") {
			cost += 200;
		}
		total_cost += cost;
	}

	cout << total_cost << "\n";
	return 0;
}
