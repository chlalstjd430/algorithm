#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<int> table[1000002];
vector<int> place;
int cnt;


vector<int> makeTable(char *pattern) {
	int patternSize = strlen(pattern);
	vector<int> table(patternSize, 0);

	int j = 0;
	for (int i = 1; i < patternSize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			table[i] = ++j;
		}
	}

	return table;
}

void kmp(char *parent, char *pattern) {
	vector<int> table = makeTable(pattern);

	int parentSize = strlen(parent);
	int patternSize = strlen(pattern);

	int j = 0;
	for (int i = 0; i < parentSize; i++) {
		while (j > 0 && parent[i] != pattern[j]) {
			j = table[j - 1];
		}

		if (parent[i] == pattern[j]) {
			if (j == patternSize - 1) {
				j = table[j];
				place.push_back(i - patternSize + 2);
			}
			else {
				j++;
			}
		}
	}
	
}

int main() {
	char parent[1000002] = {};
	char pattern[1000002] = {};

	cin.getline(parent, 1000002);
	cin.getline(pattern, 1000002);

	kmp(parent, pattern);

	int size = place.size();
	cout << size << endl;

	for (int i = 0; i < size; i++) {
		cout << place[i] << "\n";
	}
}
