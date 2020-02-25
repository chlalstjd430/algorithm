#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int t, n, m;
	cin >> t >> n >> m;

	vector<int> tonerment;
	for (int i = 1; i <= t; i++) {
		tonerment.push_back(i);
	}
	
	int cnt = 0;
	while (true) {
		vector<int> tmp;
		cnt++;
		int tonerment_size = tonerment.size()%2 == 0 ? tonerment.size() : tonerment.size() - 1;
		for (int i = 0; i < tonerment_size; i+=2) {
			if ((tonerment[i] == n && tonerment[i + 1] == m) || (tonerment[i] == m && tonerment[i + 1] == n)) {
				cout << cnt << endl;
				return 0;
			}
			if ((tonerment[i+1] == n) || (tonerment[i+1] == m)) {
				tmp.push_back(tonerment[i+1]);
				continue;
			}
			tmp.push_back(tonerment[i]);
		}
		if (tonerment.size() % 2 == 1) tmp.push_back(tonerment[tonerment_size]);
		tonerment = tmp;
		if (tonerment.size() == 1) {
			cout << -1 << endl;
			return 0;
		}

	}
}
