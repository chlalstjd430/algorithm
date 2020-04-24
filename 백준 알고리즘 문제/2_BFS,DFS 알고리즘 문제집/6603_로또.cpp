#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int visited[50];
int lotto[50];
int k;

void dfs(int cur, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < 50; i++) {
			if(visited[i] == 1)
			cout << i << " ";
		}
		cout << endl;

		return;
	}
	if (k - cur + cnt < 6) return;

	visited[lotto[cur]] = 1;
	dfs(cur+1, cnt + 1);
	visited[lotto[cur]] = 0;
	dfs(cur + 1, cnt);
	

}

int main() {
	while (true) {
		cin >> k;
		if (k == 0) break;

		for (int i = 0; i < k; i++) {
			int tmp;
			cin >> tmp;
			lotto[i] = tmp;
		}

		dfs(0, 0);
		cout << endl;
	}
}
