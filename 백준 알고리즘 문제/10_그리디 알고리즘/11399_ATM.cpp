#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int main() {
	int tc;
	cin >> tc;

	

	for (int i = 0; i < tc; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}

	sort(v.begin(), v.end());
	int sum = 0;
	int sum2 = 0;

	for (int i = 0; i < tc; i++) {
		sum += v[i];
		sum2 = sum2 + sum;
	}

	cout << sum2 << endl;
}
