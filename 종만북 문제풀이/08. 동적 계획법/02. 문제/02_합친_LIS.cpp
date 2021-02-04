#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int cache[100];

vector<int> av;
vector<int> bv;

void initCache() {
  for(int i = 0; i < 100; i++) {
    cache[i] = -1;
  }
}

void init() {
  av.clear();
  bv.clear();
  initCache();
}

void printV(vector<int> v) {
  cout << "v : ";
  for(int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

int lis(vector<int> v, int pos) {
  if (v.empty()) return 0;

  int ret = cache[pos];
  if (ret != -1) return cache[pos];

  ret = 1;
  for (int i = pos + 1; i < v.size(); i++) {
    if (v[pos] < v[i]) {
      ret = max(ret, lis(v, i) + 1);
    }
  }

  return cache[pos] = ret;
}

int compareLis(vector<int> a, vector<int> b) {
  vector<int> tmpA = a;
  for (int i = 0; i < b.size(); i++) {
    tmpA.push_back(b[i]);
  }

  vector<int> tmpB = b;
  for (int i = 0; i < a.size(); i++) {
    tmpB.push_back(a[i]);
  }
  printV(tmpA);
  printV(tmpB);

  int lisA = 0, lisB = 0;

  for (int i = 0; i < tmpA.size(); i++) {
    lisA = max(lisA, lis(tmpA, i));
  }
  initCache();
  for (int i = 0; i < tmpB.size(); i++) {
    lisB = max(lisB, lis(tmpB, i));
  }

  return max(lisA, lisB);
}


int main() {
  int tc;
  cin >> tc;
  while(tc-- > 0) {

    // 1. init   
    init();

    // 2.input
    int a, b;
    cin >> a >> b;
    for(int i = 0; i < a; i++) {
      int tmp;
      cin >> tmp;
      av.push_back(tmp);
    }

    for(int i = 0; i < b; i++) {
      int tmp;
      cin >> tmp;
      bv.push_back(tmp);
    }

    // 3. lis()
    int answer = compareLis(av, bv);
    cout << "answer" << 3 - tc << " : " << answer << endl;
  }
}

/*
3
3 3
1 2 4
3 4 7
3 3
1 2 3
4 5 6
5 3
10 20 30 1 2
10 20 30
*/