#include <iostream>
#include <algorithm>

using namespace std;

int square[51][51];

int main() {
	int N, M;
	cin >> N >> M;
	char ch[51];
	for (int i = 0; i < N; i++) {
		cin >> ch;
		for (int j = 0; j < M; j++) {
			square[i][j] = ch[j] - '0';
		}
	}

	int min_num = min(N, M);

	for (int k = min_num - 1; k > 0; k--) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int ni = i + k;
				int mj = j + k;

				if (ni >= N || mj >= M) continue;
				if (square[i][j] == square[i][mj] && square[i][j] == square[ni][mj] && square[i][j] == square[ni][j]) {
					cout << (k + 1)*(k + 1) << endl;
					return 0;
				}
			}
		}
	}

	cout << 1 << endl;
}
