#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 10002

using namespace std;

int V, E;
int id;
int visited[MAX], d[MAX];
int cnt;
vector<int> graph[MAX];
vector<vector<int> > scc;
stack<int> s;

int dfs(int x) {
	d[x] = ++id;
	s.push(x);

	int parent = d[x];
	int size = graph[x].size();
	for (int i = 0; i < size; i++) {
		int next = graph[x][i];

		if (d[next] == 0) {
			parent = min(parent, dfs(next));
		}
		else if (visited[next] == 0) {
			parent = min(parent, d[next]);
		}
	}

	if (parent == d[x]) {
		vector<int> tmp;

		while (true) {
			int top = s.top();
			s.pop();
			tmp.push_back(top);
			visited[top] = 1;
			if (top == x) break;
		}
		sort(tmp.begin(), tmp.end());
		scc.push_back(tmp);
		cnt++;
	}

	return parent;
}

int main() {
	cin >> V >> E;
	for (int i = 1; i <= E; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	for (int i = 1; i <= V; i++) {
		if (d[i] == 0) {
			dfs(i);
		}
	}
	sort(scc.begin(), scc.end());
	cout << cnt << endl;
	int sccSize = scc.size();
	for (int i = 0; i < sccSize; i++) {
		int nextSize = scc[i].size();
		for (int j = 0; j < nextSize; j++) {
			cout << scc[i][j] << " ";
		}
		cout << "-1" << endl;
	}

}
