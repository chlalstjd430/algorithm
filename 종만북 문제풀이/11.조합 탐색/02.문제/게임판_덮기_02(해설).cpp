#include <iostream>
#include <vector>
using namespace std;

const int coverType[4][3][2] = {
	{ { 0,0 },{ 1,0 },{ 0,1 } },
	{ { 0,0 },{ 0,1 },{ 1,1 } },
	{ { 0,0 },{ 1,0 },{ 1,1 } },
	{ { 0,0 },{ 1,0 },{ 1,-1 } }
};

//이 칸을 덮을 수 있는지 판단하고 board판을 덮거나 덮었던 블록을 없앤다
bool set(vector<vector<int> >&board, int y, int x, int type, int delta) {
	bool check = true;

	for (int i = 0; i < 3; i++) {
		int ny = y + coverType[type][i][0];
		int nx = x + coverType[type][i][1];

		//보드판 범위를 넘어가는지
		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size()) {
			check = false;
		}
		else if ((board[ny][nx] += delta) > 1) check = false; // 덮인 칸을 또 덮는 경우 false
	}
	return check;
}

int cover(vector<vector<int> >&board) {
	int y = -1, x = -1;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] == 0) { // 가장 먼저 덮을 칸 찾기
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) break; // for문 한번더 멈추기
	}

	if (y == -1) return 1;
	int ret = 0;

	for (int i = 0; i < 4; i++) {
		if (set(board, y, x, i, 1)) ret += cover(board);
		set(board, y, x, i, -1);
	}

	return ret;
}
int main() {
	int c, h, w;
	cin >> c;

	for (int i = 0; i < c; i++) {
		char temp;
		int white = 0;
		cin >> h >> w;
		vector<vector<int> > board(h, vector<int>(w, 0));

		for (int k = 0; k < h; k++) {
			for (int j = 0; j < w; j++) {
				cin >> temp;
				if (temp == '#') 
          board[k][j] = 1;
				else white++;
			}
		}

		if (white % 3 != 0) cout << 0;
		else cout << cover(board)<<endl;

	}
}