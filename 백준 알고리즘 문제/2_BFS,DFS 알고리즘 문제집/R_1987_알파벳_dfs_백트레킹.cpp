#include <iostream>
#include <algorithm>

using namespace std;

char map[22][22];
int dist[22][22];
int alpha[30];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int R, C;
int answer;

void dfs(int x, int y, int cnt) {
	answer = max(answer, cnt);

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (1 <= nx && nx <= R && 1 <= ny && ny <= C) {
			int num = map[nx][ny] - 'A' + 1;
			if (dist[nx][ny] == 0 && alpha[num] == 0) {
				alpha[num] = 1;
				dist[nx][ny] = 1;
				dfs(nx, ny, cnt+1);
				alpha[num] = 0;
				dist[nx][ny] = 0;
			}
		}
	}
	

}

int main() {
	cin >> R >> C;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
		}
	}
	alpha[map[1][1] - 'A' + 1] = 1;
	dist[1][1] = 1;

	dfs(1, 1, 1);

	cout << answer << endl;
}