#include <iostream>
#include <queue>

using namespace std;

int tomato[102][102][102];
int dist[102][102][102];

int dx[] = { 0, 0, 0, 0 , 1, -1 };
int dy[] = { 0, 0, -1, 1 , 0, 0 };
int dz[] = { 1, -1, 0, 0, 0, 0 };

int x, y, z;
int day;

queue<pair<pair<int, int>, int> > q;

bool tomatoState() {
	for (int i = 1; i <= z; i++) {
		for (int j = 1; j <= y; j++) {
			for (int k = 1; k <= x; k++) {
				if (tomato[j][k][i] == 0)
					return false;
			}
		}
	}

	return true;
}

void bfs() {
	while (!q.empty()) {
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int qx = q.front().first.first;
			int qy = q.front().first.second;
			int qz = q.front().second;
			q.pop();

			for (int j = 0; j < 6; j++) {
				int nqx = qx + dx[j];
				int nqy = qy + dy[j];
				int nqz = qz + dz[j];
				if (1 <= nqx && nqx <= y && 1 <= nqy && nqy <= x && 1 <= nqz && nqz <= z) {
					if (dist[nqx][nqy][nqz] == 0 && tomato[nqx][nqy][nqz] == 0) {

						q.push(make_pair(make_pair(nqx, nqy), nqz));
						dist[nqx][nqy][nqz] = 1;
						tomato[nqx][nqy][nqz] = 1;
					}
				}
			}
		}
		day++;
		if (tomatoState()) return;
	}

	
	day = -1;
	return;
}



int main() {
	cin >> x >> y >> z;
	//5 3 1
	bool isFinish = true;

	for (int i = 1; i <= z; i++) {
		for (int j = 1; j <= y; j++) {
			for (int k = 1; k <= x; k++) {
				cin >> tomato[j][k][i];
				if (tomato[j][k][i] == 1) {
					q.push(make_pair(make_pair(j, k), i));
					dist[j][k][i] = 1;

				}
				else if (tomato[j][k][i] == 0)
					isFinish = false;

			}
		}
	}

	

	if (isFinish == true) {
		cout << 0 << '\n';
	}
	else {
		bfs();
		cout << day << '\n';
	}


}