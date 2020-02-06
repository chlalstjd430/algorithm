#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> lope;
	int tc = 0;
	int maxWeight = 0;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		int weight;
		cin >> weight;

		lope.push_back(weight);
	}

	sort(lope.begin(), lope.end());

	for (int i = 0; i < tc; i++) {
		maxWeight = max(maxWeight,lope[i] * (tc - i));
	}
	
	cout << maxWeight << endl;
}
