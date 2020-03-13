#include <iostream>
using namespace std;

int dp[31];

int main() {
	int n;
	cin >> n;
	
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	
	for(int i = 2; i <= 30; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	
	int sum = 0;
	for(int i = 0; i <= n; i++){
		sum += dp[i];
	}
	
	cout << sum << endl;
	
	return 0;
}
