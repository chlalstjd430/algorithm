#include <iostream>
#include <vector>

using namespace std;


int vertex, edge;
vector<int> computer[102];
int visited[102];
int cnt;

void dfs(int start) {
	if (visited[start] == 1) return;

	visited[start] = 1;
	
	int size = computer[start].size();

	for (int i = 0; i < size; i++) {
		if (visited[computer[start][i]] == 0) {
			dfs(computer[start][i]);
			cnt++;
		}
	}
}

int main() {
	cin >> vertex >> edge;

	int x, y;
	for (int i = 0; i < edge; i++) {
		cin >> x >> y;

		computer[x].push_back(y);
		computer[y].push_back(x);
	}
	dfs(1);
	cout << cnt << '\n';
	
}