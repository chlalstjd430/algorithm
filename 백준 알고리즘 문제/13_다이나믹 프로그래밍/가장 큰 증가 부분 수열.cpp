#include <iostream>
#include <algorithm>

using namespace std;

int arry[1002];
int dp[1002];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arry[i] = tmp;
	}

	for (int i = 0; i < n; i++) {
		dp[i] = arry[i];
		for (int j = 0; j < i; j++) {
			if (arry[i] > arry[j]) {
				dp[i] = max(dp[i], arry[i] + dp[j]);
			}
		}
	}

	sort(dp, dp + 1000, cmp);

	cout << dp[0] << endl;


}
