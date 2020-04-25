#include <iostream>

using namespace std;

int map[101][101];

int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int left, bottom;
		cin >> left >> bottom;

		for (int j = bottom; j < bottom + 10; j++) {
			for (int k = left; k < left + 10; k++) {
				map[j][k] = 1;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			result += map[i][j];
		}
	}

	cout << result << endl;
}
