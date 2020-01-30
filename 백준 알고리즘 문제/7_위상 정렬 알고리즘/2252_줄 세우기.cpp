#include <iostream>
#include <vector>
#include <queue>
#define MAX 32002

using namespace std;

int N, M;
int inDegree[MAX];
int result[MAX];
vector<int> graph[MAX];

void topologySort() {
	queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0)
			q.push(i);
	}

	for (int i = 1; i <= N; i++) {
		if (q.empty()) {
			return;
		}
		int front = q.front();
		q.pop();
		result[i] = front;

		int size = graph[front].size();
		for (int i = 0; i < size; i++) {
			int current = graph[front][i];

			if (--inDegree[current] == 0)
				q.push(current);
		}
	}
}

int main() {
	cin >> N >> M;

	int a, b = 0;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;

		graph[a].push_back(b);
		inDegree[b]++;
	}

	topologySort();

	for (int i = 1; i <= N; i++)
		cout << result[i] << " ";
}