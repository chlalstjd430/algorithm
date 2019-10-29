#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[1002];
int visited[1002];

int cnt;
int vertex;

void dfs(int x) {
	if (visited[x] == 1) return;
	
	visited[x]= 1;

	int size = graph[x].size();

	for (int i = 0; i < size; i++) {
		int next = graph[x].back();

		graph[x].pop_back();
		dfs(next);
	}
	
}

int main() {
	int tc, num;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		cin >> vertex;
		for (int j = 1; j <= vertex; j++) {
			cin >> num;
			graph[j].push_back(num);
		}

		for (int j = 1; j <= vertex; j++) {
			if (visited[j] == 0 && !graph[j].empty()) {
				dfs(j);
				cnt++;
			}
		}

		cout << cnt << '\n';
		cnt = 0;

		for (int j = 1; j <= vertex; j++) {
			graph[j].clear();
			visited[j] = 0;
		}


	}
}