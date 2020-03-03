#include <iostream>
#include <vector>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	vector<int> number;
	for (int i = 1; i < 1000; i++) {
		for (int j = 0; j < i; j++) {
			number.push_back(i);
		}
	}

	int sum = 0;
	for (int i = a-1; i < b; i++) {
		sum += number[i];
	}

	cout << sum << endl;
}
