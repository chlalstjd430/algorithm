#include <iostream>
#include <algorithm>

using namespace std;

int map[30][30];
int visited[30][30];
int xAry[4] = { 0, 0 ,1 , -1 };
int yAry[4] = { 1, -1, 0 , 0 };
int cnt;
int tc;

int ary[1010];


void dfs(int x, int y) {
	if (visited[x][y] != 0) return;
	ary[cnt]++;
	if (map[x][y] == 1 && visited[x][y] == 0) {
		visited[x][y] = cnt + 1;
	}
	else visited[x][y] = -1;
	

	for (int i = 0; i < 4; i++) {
		if ((1 <= x + xAry[i] && x + xAry[i] <= tc) && (1 <= y + yAry[i] && y + yAry[i] <= tc)) {
			if (visited[x + xAry[i]][y + yAry[i]] == 0 && map[x + xAry[i]][y + yAry[i]] == 1) {
				dfs(x + xAry[i], y + yAry[i]);
			}

		}
	}


}

int main() {
	char input;
	cin >> tc;

	for (int i = 1; i <= tc; i ++ ) {
		for (int j = 1; j <= tc; j++) {
			cin >> input;
			map[i][j] = input - '0';
		}
	}

	for (int i = 1; i <= tc; i++) {
		for (int j = 1; j <= tc; j++) {
			if (visited[i][j] == 0 && map[i][j] == 1) {
				dfs(i, j);
				cnt++;
			}
		}
	}

	cout << cnt << '\n';

	sort(ary, ary + tc*tc);

	for (int i = 0; i <= tc*tc; i++) {
		if(ary[i] != 0)
			cout << ary[i] << '\n';
	}

	
}