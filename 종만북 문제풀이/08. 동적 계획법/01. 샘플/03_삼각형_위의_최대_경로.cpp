#include <iostream>
#include <algorithm>

using namespace std;

int n;
int map[101][101];
int cache[101][101];

void initCache() {
  for(int i = 0; i < 101; i++) {
    for(int j = 0; j < 101; j++) {
      cache[i][j] = -1;
    }
  }
}

int searchPath(int x, int y) {
  if (x == n- 1 ) return map[x][y];

  int ret = cache[x][y];
  if (ret != -1) return cache[x][y];

  return cache[x][y] = max(searchPath(x + 1, y), searchPath(x + 1, y + 1)) + map[x][y];
}

int main() {
  // map[0][0] = 6;

  // map[1][0] = 1;
  // map[1][1] = 2;

  // map[2][0] = 3;
  // map[2][1] = 7;
  // map[2][2] = 4;

  // map[3][0] = 9;
  // map[3][1] = 4;
  // map[3][2] = 1;
  // map[3][3] = 7;

  // map[4][0] = 2;
  // map[4][1] = 7;
  // map[4][2] = 5;
  // map[4][3] = 9;
  // map[4][4] = 4;

  map[0][0] = 1;

  map[1][0] = 2;
  map[1][1] = 4;

  map[2][0] = 8;
  map[2][1] = 16;
  map[2][2] = 8;

  map[3][0] = 32;
  map[3][1] = 64;
  map[3][2] = 32;
  map[3][3] = 64;

  map[4][0] = 128;
  map[4][1] = 256;
  map[4][2] = 128;
  map[4][3] = 256;
  map[4][4] = 128;
  initCache();
  n = 5;
  cout << searchPath(0, 0) << endl;
}