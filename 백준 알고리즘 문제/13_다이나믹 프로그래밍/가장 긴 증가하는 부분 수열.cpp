#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int tc;
	cin >> tc;
	vector<int> v;
	for (int i = 0; i < tc; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	vector<int> dp(v.size(), 0);
	for (int i = 0; i < tc; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	sort(dp.begin(), dp.end());

	cout << dp[dp.size() - 1] << endl;
	

}
