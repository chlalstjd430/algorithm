#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int vertex, edge;
int p1,p2 ;

vector<int> relation[102];
int visited[102];

int bfs() {
	queue<int > q;
	q.push(p1);

	visited[p1] = 0;

	while (!q.empty()) {
		int next = q.front();
		q.pop();

		if (next == p2) return visited[p2];

		int size = relation[next].size();
		for (int i = 0; i < size; i++) {
			int tmp = relation[next][i];
			if (visited[tmp] > 0) continue;
			q.push(tmp);
			visited[tmp] = visited[next]+1;
		}
	}

	return -1;
}

int main() {
	cin >> vertex;
	cin >> p1 >> p2;

	cin >> edge;

	int x, y;
	for (int i = 0; i < edge; i++) {
		cin >> x >> y;
		relation[x].push_back(y);
		relation[y].push_back(x);
	}
	
	cout << bfs();


}