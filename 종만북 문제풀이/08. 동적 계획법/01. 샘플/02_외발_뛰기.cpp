#include <iostream>

using namespace std;

int n;
int board[100][100];
int cache[100][100];

// 일반적인 방법
bool jump(int x, int y) {
  if (x > n || y > n) return false;
  if (x == n - 1 && y == n - 1) return true;

  int cnt = board[x][y];
  bool down = jump(x + cnt, y);
  bool right = jump(x, y + cnt);

  return down || right;
}

// 메모제이션 활용
bool jump2(int x, int y) {
  // 기저사례
  if (x > n || y > n) return false;
  if (x == n - 1 && y == n - 1) return true;

  // 메모제이션
  int ret = cache[x][y];
  if (ret != -1) return ret;
  
  int cnt = board[x][y];
  bool down = jump(x + cnt, y);
  bool right = jump(x, y + cnt);

  return cache[x][y] = down || right;
}

int main() {

}