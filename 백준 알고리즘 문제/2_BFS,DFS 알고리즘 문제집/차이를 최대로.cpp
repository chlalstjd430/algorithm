#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int sum = -987654321;
int ary[9];
bool visited[9];
vector<int> v;


void isAnswer() {
	int tmp = 0;
	for (int i = 0; i < n - 1; i++) {
		tmp += abs(v[i] - v[i + 1]);
	}
	sum = max(sum, tmp);
}

void dfs(int cnt) {
	if (cnt == n) {
		isAnswer();
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(ary[i]);
			dfs(cnt + 1);
			v.pop_back();
			visited[i] = false;
		}
	}

}

int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> ary[i];
	}

	dfs(0);
	cout << sum << endl;
}
