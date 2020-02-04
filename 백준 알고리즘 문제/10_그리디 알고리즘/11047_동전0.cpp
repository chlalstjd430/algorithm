#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	int cnt = 0;
	for (int i = N-1; i >= 0; i--) {
		cnt += K / v[i];
		K %= v[i];
	}

	cout << cnt << endl;
}
