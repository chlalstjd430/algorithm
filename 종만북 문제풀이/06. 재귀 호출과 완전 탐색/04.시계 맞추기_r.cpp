#include <iostream>
#include <vector>
#include <string>

using namespace std;

int clocks[16];
int linked[10][16] = {
  {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
  {1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
  {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
  {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
  {0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
  {0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}
};
int linkedCount[10];

bool isAnswer() {
  for (int i = 0; i < 16; i++) {
    if (clocks[i] != 12) {
      return false;
    }
  }

  return true;
}

void push(int switchNo) {
  for (int i = 0; i < 16; i++) {
    if (linked[switchNo][i] == 1) {
      clocks[i] += 3;
      if (clocks[i] == 15) {
        clocks[i] = 3;
      }
    }
  }
}

int solve(int switchNo) {
  if (switchNo == 10) {
    return isAnswer() ? 0 : 987654321;
  }

  int ret = 987654321;
  for (int i = 0; i < 4; i++) {
    ret = min(ret, i + solve(switchNo + 1));
    push(switchNo);
  }

  return ret;
}

int main() {
  int tc;
  cin >> tc;
  while(tc-- > 0) {
    for (int i = 0; i < 16; i++) {
      int tmp;
      cin >> tmp;
      clocks[i] = tmp;
    }
    cout <<endl;
    cout << solve(0) << endl;
  }

}

/*
  하나의 스위치를 4번이상 누를 경우는 없다.
  3번이상 누를 경우 바늘은 그대로이므로.

  2
12 6 6 6 6 6 12 12 12 12 12 12 12 12 12 12 

1
12 9 3 12 6 6 9 3 12 9 12 9 12 12 6 6
*/