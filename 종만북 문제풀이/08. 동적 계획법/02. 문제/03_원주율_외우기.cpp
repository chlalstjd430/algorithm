#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = numeric_limits<int>::max();
string str;
int cache[10002];

int classify(string tmp) {
  // 숫자 조각을 가져온다

  // 난이도 1 : 첫 글자만으로 이루어진 문자열과 같으면 난이도는 1
  if (tmp == string(tmp.size(), tmp[0])) {
    return 1;
  }

  // 등차수열인지 확인
  bool flag = true;
  for(int i = 0; i < tmp.size() - 1; i++) {
    if(tmp[i+1] - tmp[i] != tmp[1] - tmp[0]) {
      flag = false;
      break;
    }
  }

  // 난이도 2 : 등차수열이고 공차가 1인 경우 -> 
  if (flag && abs(tmp[1] - tmp[0])) {
    return 2;
  }

  // 두 수가 번갈아 등장하는지 확인
  bool flagB = true;
  for (int i = 0; i < tmp.size(); i++) {
    if (tmp[i] != tmp[i%2]) {
      flagB = false;
      break;
    }
  }

  // 난이도 4 : 두 수가 번갈아가는 경우
  if (flagB) return 4;

  // 난이도 5 : 등차 수열
  if (flag) return 5;

  // 난이도 10 : 그 외
  return 10;
}

int memorize(int pos) {
  // 기저사례
  if (pos == str.size()) return 0;
  
  int ret = cache[pos];
  if (ret != -1) return ret;
  ret = INF;

  for (int i = 3; i <= 5; i++) {
    string tmp = str.substr(pos, i);
    ret = min(ret, memorize(pos + i) + classify(tmp));
  }

  return cache[pos] = ret;
}

int main() {
  string s = "0123456789";
  cout << s.substr(1,3) << endl;
  cout << INF << endl;
}

/*
  풀이방법


*/