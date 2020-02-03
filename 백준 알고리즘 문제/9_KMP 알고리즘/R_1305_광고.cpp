#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

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

int main() {
	char pattern[1000002] = {};
	int advLength = 0;
	cin >> advLength;
	cin >> pattern;

	vector<int> table = makeTable(pattern);

	int maxNumber = 0;
	int maxIndex = 0;
	int tableSize = table.size();

	for (int i = 0; i < tableSize; i++) {
		if (maxNumber < table[i]) {
			maxNumber = table[i];
			maxIndex = i;
		}
	}

	int startIndex = 0;
	for (int i = maxIndex; i > 0; i--) {
		if (table[i] == 1) {
			startIndex = i;
		}
	}
	cout << "maxIndex : " << maxIndex << ", startIndex : " << startIndex << endl;
	int result = maxIndex - startIndex + 1;
	cout << advLength - table[advLength - 1] << endl;

}
