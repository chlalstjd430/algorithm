#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> v;

bool cmp(char c1, char c2) {
	return c1 > c2;
}

int main() {
	string str = "";
	string answer = "";
	int sum = 0;
	cin >> str;
	
	int strSize = str.size();
	for (int i = 0; i < strSize; i++) {
		v.push_back(str[i]);
	}

	sort(v.begin(), v.end(), cmp);

	if (v[strSize - 1] != '0') {
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i < strSize; i++) {
		sum += v[i] - '0';
		answer += v[i];
	}

	if (sum % 3 == 0) {
		cout << answer << endl;
	}
	else {
		cout << -1 << endl;
	}


}
