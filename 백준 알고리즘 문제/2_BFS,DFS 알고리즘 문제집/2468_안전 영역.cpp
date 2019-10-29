#include <iostream>
#include <queue>

using namespace std;

int map[102][102];
int visited[102][102];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

int N;

void dfs(int x, int y, int max) {
	if (visited[x][y] != 0) return;
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
			if (visited[nx][ny] == 0 && map[nx][ny] > max) {
				dfs(nx, ny, max);
			}
		}
	}
	
	
}

int main() {
	cin >> N;
	int layer = -1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (layer < map[i][j])
				layer = map[i][j];
		}
	}
	
	int max = 0, cnt = 0;
	for (int i = 0; i <= 101; i ++ ) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (visited[j][k] == 0 && map[j][k] > i) {
					dfs(j, k, i);
					cnt++;
				}
			}
		}
		if (cnt > max)
			max = cnt;

		//visited √ ±‚»≠
		cnt = 0;
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				visited[j][k] = 0;
			}
		}
	}

	cout << max << endl;

}