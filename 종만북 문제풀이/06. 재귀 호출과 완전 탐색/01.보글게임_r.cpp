#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> map;
const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0};
const int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1};

bool inRange(int x, int y) {
  if ((0 > x || 5 <= x) || (0 > y || 5 <= y)) {
    return false;
  }

  return true;
}

bool hasWord(int x, int y, string word) {
  if (!inRange(x, y)) {
    return false;
  }

  if (map[x][y] != word[0]) return false;
  if (word.size() == 1) return true;

  for (int i = 0; i < 8; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (hasWord(nx, ny, word.substr(1))) {
      return true;
    }
  }
  return false;
}

void bogleGame(string word) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (hasWord(i, j, word))
      {
        cout << "TRUE" << endl;
        return;
      }
    }
  }

  cout << "FALSE" << endl;
  return;
}

int main() {
  map.push_back("URLPM");
  map.push_back("XPRET");
  map.push_back("GIAET");
  map.push_back("XTNZY");
  map.push_back("XOQRS");
  
  bogleGame("PRETTY");
}