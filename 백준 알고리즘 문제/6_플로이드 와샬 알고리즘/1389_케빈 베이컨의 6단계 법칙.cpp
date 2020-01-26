#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 102;
const int INF = 987564321;
int graph[MAX][MAX];
int visited[MAX][MAX];
int N, M;

int floydWarshall() {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visited[i][j] = graph[i][j];
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if ((visited[i][k] + visited[k][j]) < INF) {
					int tmp = visited[i][k] + visited[k][j];
					visited[i][j] = min(visited[i][j], tmp);
				}
			}
		}
	}

	int minNum = INF;
	int minIndex = 0;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			sum += visited[i][j];
		}
		if (minNum > sum) {
			minNum = sum;
			minIndex = i;
		}
	}

	return minIndex;
}

int main() {
	cin >> N >> M;

	fill(&graph[0][0], &graph[MAX - 1][MAX - 1], INF);
	for (int i = 0; i <= N; i++)
		graph[i][i] = 0;

	int a, b = 0;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		graph[a][b] = graph[b][a] = 1;
	}

	cout << floydWarshall();
}