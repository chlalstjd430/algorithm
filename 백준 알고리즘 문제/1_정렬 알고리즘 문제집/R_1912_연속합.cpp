#include <iostream>
#include <algorithm>

using namespace std;

int ary[100005];
int sumAry[100005];


int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		cin >> ary[i];
	}
	sumAry[0] = ary[0];

	int maxNum = ary[0];
	for (int i = 1; i < tc; i++) {
		sumAry[i] = max(sumAry[i-1] + ary[i], ary[i]);
		maxNum = max(maxNum, sumAry[i]);
	}

	cout << maxNum;
}