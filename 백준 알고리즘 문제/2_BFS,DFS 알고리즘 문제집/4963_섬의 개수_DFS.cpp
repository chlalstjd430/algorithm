#include <iostream>
#include <vector>

using namespace std;

int W, H;
int map[52][52];
int visited[52][52];
int cnt;
int isIland;
void dfs(int x, int y) {
	

	if ((0 < x && x <= W) && (0 < y && y <= H)) {
		
		if (visited[x][y] == 0 && map[x][y]) {
			visited[x][y] = 1;


			dfs(x, y - 1);
			dfs(x + 1, y - 1);
			dfs(x + 1, y);
			dfs(x + 1, y + 1);
			dfs(x, y + 1);
			dfs(x - 1, y + 1);
			dfs(x - 1, y);
			dfs(x - 1, y - 1);

			
		}
		
	}
	
}

int main() {
	while (true) {
		cin >> H >> W;

		if (W == 0 && H == 0) break;
		
		
		for (int i = 1; i <=  W; i++ ) {
			for (int j = 1; j <= H; j++) {
				cin >> map[i][j];
			}
		}

		
		for (int i = 1; i <= W; i++) {
			for (int j = 1; j <= H; j++) {
				if (visited[i][j] == 0 && map[i][j] == 1) {
					dfs(i, j);
					cnt++;
				}
			}
		}

	
		cout << cnt << '\n';
		cnt = 0;

		for (int i = 0; i <= W; i++) {
			for (int j = 0; j <= H; j++) {
				map[i][j] = 0;
				visited[i][j] = 0;
			}
		}

	}

}