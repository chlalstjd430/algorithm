#include <iostream>
#include <queue>
#include <utility>

using namespace std;


int N, M;
int map[1002][1002];
int visited[1002][1002][2];

int xAry[] = { 0, 0, -1, 1 };
int yAry[] = { -1, 1, 0 , 0 };

int bfs(int x, int y, int z) {
	queue<pair<int,pair<int,int> > > q;
	q.push(pair<int, pair<int, int> >(x,pair<int,int>(y,z)));
	
	visited[x][y][z] = 1;

	while (!q.empty()) {
	
		int qx = q.front().first;
		int qy = q.front().second.first;
		int qz = q.front().second.second;
		

		q.pop();

		if (qx == N && qy == M) {
			return visited[qx][qy][qz];
		}


		for (int i = 0; i < 4; i++) {
			int nqx = qx + xAry[i];
			int nqy = qy + yAry[i];

			if ((1 <= nqx && nqx <= N) && (1 <= nqy && nqy <= M)) {
				if (visited[nqx][nqy][qz] == 0) {
					if (map[nqx][nqy] == 0) {
						q.push(pair<int, pair<int, int> >(nqx, pair<int, int>(nqy, qz)));
						visited[nqx][nqy][qz] = visited[qx][qy][qz]+1;
					}
					else if (map[nqx][nqy] == 1 && qz == 0 ) {
						q.push(pair<int, pair<int, int> >(nqx, pair<int, int>(nqy, 1)));
						visited[nqx][nqy][1] = visited[qx][qy][qz]+1;

					}
				}
			}
		}
	}

	return -1;
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

	
	cout << bfs(1, 1, 0) << '\n';

	
}