#include <iostream>
#include <algorithm>

using namespace std;

int n;
int nh[20001];
int maxRectengle = 0;

void recycle(int ind) {
  
}

int main() {
  int tc;
  cin >> tc;

  while(tc-- > 0) {
    maxRectengle = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int tmp;
      cin >> tmp;
      nh[i] = tmp;
    }

    for(int i = 0; i < n; i++) {
      int h = 20000;
      for(int j = i; j < n; j++) {
        int w = j - i + 1;
        h = min(h, nh[j]);
        maxRectengle = max(maxRectengle, w*h);
      }
    }

    cout << "answer : " << maxRectengle << endl;
  }
}

/*
  1. 무식하게 풀기
    a 부터 b판자의 직사각형 넓이 구하는 공식 : (a - b + 1) * minH(a~b)
    -> O(n2)이여서 최대 400000000번 수행하여 어렵다.


*/