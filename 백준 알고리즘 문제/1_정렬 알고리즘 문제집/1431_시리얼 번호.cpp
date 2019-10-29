#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int getSum(string s) {
	int sum = 0;
	int len = s.length();

	for (int i = 0; i < len; i++) {
		if (0 < s[i] - '0' && s[i] - '0' <= 9) {
			sum += s[i] - '0';
		}
	}

	return sum;
}

bool comapre(string a, string b) {
	if (a.length() == b.length()) {
		if (getSum(a) == getSum(b)) {
			return a < b;
		}
		return getSum(a) < getSum(b);
	}
	else
		return a.length() < b.length();
}

int main() {
	string str[20000];
	int count;

	cin >> count;
	for (int i = 0; i < count; i++) {
		cin >> str[i];
	}

	sort(str, str + count, comapre);

	for (int i = 0; i < count; i++) {
		cout << str[i] << endl;
	}
	
}