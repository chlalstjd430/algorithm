#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654;
int n, m;
int graph[102][102];
int visited[102][102];

void floydWarshall() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			visited[i][j] = graph[i][j];
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (visited[i][j] > visited[i][k] + visited[k][j]) {
					visited[i][j] = visited[i][k] + visited[k][j];
				}
			}
		}
	}
}

int main() {

	fill(&graph[0][0], &graph[101][101], INF);
	cin >> n >> m;

	int a, b, c = 0;
	for (int i = 1; i <= n; i++)
		graph[i][i] = 0;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		
		if (graph[a][b] > c)
			graph[a][b] = c;
	}

	floydWarshall();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited[i][j] == INF)
				cout << 0 << " ";
			else
				cout << visited[i][j] << " ";
		}
		cout << endl;
	}
}