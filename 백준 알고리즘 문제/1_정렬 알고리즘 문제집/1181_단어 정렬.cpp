#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool compare(string a, string b) {
	if (a.length() == b.length()) {
		return (a < b);
	}
	else {
		return a.length() < b.length();
	}
}

int main() {
	int count = 0;
	cin >> count;

	string str[20000];
	for (int i = 0; i < count; i++) {
		cin >> str[i];
	}

	sort(str, str + count,compare);

	for (int i = 0; i < count; i++) {
		if (i != count - 1 && str[i] == str[i + 1])
			continue;
		cout << str[i] << endl;

	}
		

}