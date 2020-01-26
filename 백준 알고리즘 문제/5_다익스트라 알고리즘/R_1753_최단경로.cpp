#include <iostream>
#include <vector>
#include <queue>

using namespace std;


//int d[20001]; // �迭�� �ƴ� ����Ʈ�� �ذ��ؾ� ��
const int INF = 987654321;
int E, V, W;
int start;

vector<pair<int, int> > graph[20001];

vector<int>  dijkstra() {
	vector<int> d(V+1, INF );// �ð��� ���̱� ���� �迭�� �ƴ� vector�� ����
	d[start] = 0;

	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();

		if (d[current] < distance) continue;

		int size = graph[current].size();// �� �κ��� ���ָ� �ð��� ���δ�.
		for (int i = 0; i < size; i++) {
			int next = graph[current][i].first;
			int nextDistance = distance + graph[current][i].second;

			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(-nextDistance, next));
			}

		}

	}

	return d;
}

int main() {
	cin >> V >> E;
	cin >> start;

	int u, v, w;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}

	vector<int> d = dijkstra();

	for (int i = 1; i <= V; i++) {
		if (d[i] == 987654321)
			cout << "INF" << endl;
		else
			cout << d[i] << endl;
	}
}