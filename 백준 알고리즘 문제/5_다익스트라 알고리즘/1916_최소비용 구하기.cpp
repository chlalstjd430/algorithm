#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1002;
const int INF = 987654321;
int N, M;
int start, goal;

vector<pair<int, int> > graph[MAX];

vector<int> dijkstra() {
	vector<int> d(N+1, INF);
	d[start] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int current = pq.top().second;
		int distance = pq.top().first;
		pq.pop();

		int size = graph[current].size();
		for (int i = 0; i < size; i++) {
			int next = graph[current][i].first;
			int nextDistance = graph[current][i].second + distance;

			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(d[next], next));
			}
		}
	}

	return d;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int x, y, v = 0;
		cin >> x >> y >> v;

		graph[x].push_back(make_pair(y, v));
	}

	cin >> start >> goal;

	vector<int> d = dijkstra();

	cout << d[goal];
}