#include <iostream>

using namespace std;

const int MAX = 402;

int graph[MAX][MAX];
int visited[MAX][MAX];
int n, k;

void floydWarshall() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			visited[i][j] = graph[i][j];
		}
	}

	for (int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				int order = visited[i][k] + visited[k][j];

				if (visited[i][j] == 0) {
					if (order == 2) {
						visited[i][j] = 1;
						visited[j][i] = -1;
					}
					else if (order == -2) {
						visited[i][j] = -1;
						visited[j][i] = 1;
					}
				}
				


			}
		}
	}
}

int main() {
	cin >> n >> k;

	int a, b = 0;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		graph[a][b] = -1;
		graph[b][a] = 1;
	}

	floydWarshall();

	int tc = 0;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		cin >> a >> b;
		cout << visited[a][b] << endl;
	}
}