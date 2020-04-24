#include <iostream>

using namespace std;

int isAnswer[250000];

int main() {
	int n;
	// 소수먼저 계산

	while (true) {
		cin >> n;
		int answer = 0;
		if (n == 0) break;
		
		for (int i = 2; i <= 2*n; i++) {
			for (int j = i+i; j <= 2 * n; j += i) {
				isAnswer[j] = -1;
			}
		}

		for (int i = n +1; i <= 2 * n; i++) {
			if (isAnswer[i] == 0) {
				answer++;
			}
		}

		cout << answer << endl;
		

	}
}
