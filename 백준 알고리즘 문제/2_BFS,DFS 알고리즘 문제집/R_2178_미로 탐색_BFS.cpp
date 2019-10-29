#include <iostream>
#include <queue>

using namespace std;

int map[102][102];
int visited[102][102];
int N, M;
int xAry[] = { 0, 0, -1, 1 };
int yAry[] = { -1, 1, 0, 0 };
int min;

void bfs(int x, int y) {
	queue<pair<int,int>> q;
	q.push(pair<int, int>(x, y));
	visited[x][y] = 1;

	while (!q.empty()) {
		int qx = q.front().first;
		int qy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = qx + xAry[i];
			int ny = qy + yAry[i];

			if (visited[nx][ny] == 0 && map[nx][ny] == 1) {
				q.push(pair<int, int>(nx, ny));
				visited[nx][ny] = visited[qx][qy] + 1;
			}
		
		}


	}
}

int main() {
	char input;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> input;
			map[i][j] = input - '0';
		}
	}
	bfs(1, 1);
	
	cout  << visited[N][M] << endl;

}