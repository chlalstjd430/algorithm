#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int h, w, nh, nw;
char gameMap[51][51];
char block[10][10];
bool memo[51][51];

void printMap() {
  cout << "========[print map]==========" << endl;
  cout << "[gameMap]" << endl;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << gameMap[i][j] << " ";
    }
    cout << endl;
  }

  cout << "[block]" << endl;
  for (int i = 0; i < nh; i++) {
    for (int j = 0; j < nw; j++) {
      cout << block[i][j] << " ";
    }
    cout << endl;
  }

  cout << "[memo]" << endl;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << memo[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl;
}

int solve(int x, int y) {
  
  if (gameMap[x][y] == '#') {
    // memo[x][y] = fa
  }

  return 0;
}

int main()
{
  int tc;
  cin >> tc;

  while(tc-- > 0) {
    cin >> h >> w >> nh >> nw;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> gameMap[i][j];
      }
    }

    for (int i = 0; i < nh; i++) {
      for (int j = 0; j < nw; j++) {
        cin >> block[i][j];
      }
    }

    printMap();
  }
  
}

/*
2
4 7 2 3
##.##..
#......
#....##
#..####
###
#..
5 10 3 3
..........
..........
..........
..........
..........
.#.
###
..#
*/