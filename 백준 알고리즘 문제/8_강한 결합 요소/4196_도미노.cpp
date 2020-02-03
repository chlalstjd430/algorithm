#include <iostream>
#include <vector>
#define MAX 100002

using namespace std;

int N, M;
int cnt;
bool visited[MAX];
vector<int> graph[MAX];

void dfs(int num) {
	if (visited[num]) return;
	visited[num] = true;

	int size = graph[num].size();
	for (int i = 0; i < size; i++) {
		int next = graph[num][i];

		if (!visited[next]) {
			dfs(next);
		}
	}

	return;
}

int main() {
	int tc = 0;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		cin >> N >> M;

		for (int j = 0; j < M; j++) {
			int a, b = 0;
			cin >> a >> b;
			graph[a].push_back(b);
		}

		for (int j = 1; j <= N; j++) {
			if (!visited[j]) {
				dfs(j);
				cnt++;
			}
		}

		cout << cnt << endl;

		fill(&visited[0], &visited[MAX - 1], false);
		graph->clear();
		
	}
}
