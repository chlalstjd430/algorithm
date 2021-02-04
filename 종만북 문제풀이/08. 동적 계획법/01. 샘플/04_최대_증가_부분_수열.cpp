#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int cache[100], S[100];

// 일반적인 방법
int lis(vector<int> v) {
  if (v.empty()) {
    return 0;
  }

  int ret = 0;
  for (int i = 0; i < v.size(); i++) {
    vector<int> tmp;
    for (int j = i + 1; j < v.size(); j++) {
      if (v[i] < v[j]) {
        tmp.push_back(v[j]);
      }
    }

    ret = max(ret, 1 + lis(tmp));
  }
  
  return ret;
}

// 메모리제이션
int lis2(int start) {
  int ret = cache[start];
  if(ret != -1) return ret;

  ret = 1;
  for(int i = start + 1; i < n; i++) {
    if (S[start] < S[i]) {
      ret = max(ret, lis2(i) + 1);
    }
  }

  return cache[start] = ret;
}
/*
  3 2 1 7 5 4 2 6
  3 | 7 5 4 6
    | 7
    | 5 | 6
    | 4 | 6
    | 6
*/

int lis(int pos) {
  int ret = cache[pos];
  if (ret != -1) return ret;

  ret = 1;
  for (int i = pos; i < n; i++) {
    if (S[pos] < S[i]) {
      ret = max(ret, lis(i) + 1);
    }
  }

  return cache[pos] = ret;
}
int main() {
  vector<int> v;
  v.push_back(3);
  v.push_back(2);
  v.push_back(1);
  v.push_back(7);
  v.push_back(5);
  v.push_back(4);
  v.push_back(2);
  v.push_back(6);

  n = 8;
  S[0] = 3;
  S[1] = 2;
  S[2] = 1;
  S[3] = 7;
  S[4] = 5;
  S[5] = 4;
  S[6] = 2;
  S[7] = 6;
  
  for (int i = 0; i < 100; i++) {
    cache[i] = -1;
  }
  cout << lis(v) << endl;

  int maxLen = 0;
  for (int i = 0; i < n; i++) {
    maxLen = max(maxLen, lis2(i));
  }
  cout << maxLen << endl;

}