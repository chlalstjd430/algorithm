#include <iostream>
#include <vector>
#include <string>

using namespace std;

int tc;
int h, w;
vector<vector<int> > map;
const int coverType[4][3][2] = {
  { {0, 0}, {1, 0}, {0, 1} },
  { {0, 0}, {0, 1}, {1, 1} },
  { {0, 0}, {1, 0}, {1, 1} },
  { {0, 0}, {1, 0}, {1, -1} }
};

void printMap() {
  cout << "print map" << endl;
  for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cout << map[i][j] << " ";
      }
      cout << endl;
  }
  cout << endl;
}

bool hasBlank() {
  int cnt = 0;
  for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (map[i][j] == 0) cnt++;
      }
  }

  if (cnt % 3 == 0) return true;

  return false;
}

bool set(int x, int y, int type, int delta) {
  bool isPossible = true;
  for (int i = 0; i < 3; i++) {
    int nx = x + coverType[type][i][0];
    int ny = y + coverType[type][i][1];

    if (ny < 0 || ny >= w || nx < 0 || nx >= h) {
      isPossible = false;
    }
    else {
      map[nx][ny] += delta;

      if (map[nx][ny]> 1) 
        isPossible = false;
    }
  }

  return isPossible;
}

int cover() {
  int x = -1, y = -1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (map[i][j] == 0) {
        x = i;
        y = j;
        break;
      }
    }

    if (x != -1) break;
  }

  if (x == -1) {
    return 1;
  } 

  int sum = 0;
  for (int i = 0; i < 4; i++) {
    if (set(x, y, i, 1)) {
      sum += cover();
    }
    set(x, y , i, -1);
  }

  return sum;
}

int main() {
  cin >> tc;

  while(tc-- > 0) {
    cin >> h >> w;
    
    map.clear();
    vector<int> tmp;
    for (int i = 0; i < w; i++) {
      tmp.push_back(0);
    }
    for (int i = 0; i < h; i++) {
      map.push_back(tmp);
    }

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        char c;
        cin >> c;

        if (c == '#') {
          map[i][j] = 1;
        }
      }
    }

    printMap();

    // start
    if (hasBlank())
      cout << "answer : " << cover() << endl;
    else
      cout << "no answer" << endl;
  }
}

/*

1
3 7 
#.....# 
#.....# 
##...## 

1
3 7 
#.....# 
#.....# 
##..### 

1
8 10 
########## 
#........# 
#........# 
#........# 
#........# 
#........# 
#........# 
########## 



*/