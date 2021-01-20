#include <iostream>
#include <algorithm>

using namespace std;

int n;
int nh[20001];
int maxRectengle = 0;

int recycle(int left, int right) {
  // 기저 사례 : 판자가 하나밖에 없는 경우
  if (left == right) return nh[left];

  int mid = (left + right) / 2;

  // 왼쪽과 오른쪽 중 가장 큰 값
  int result = max(recycle(left, mid), recycle(mid + 1, right));

  // 가운데 값 계산 시작
  int lm = mid, rm = mid + 1;
  int height = min(nh[lm], nh[rm]);
  result = max(result, height * 2);

  while(left < lm || rm < right) {
    // 높이가 더 높은쪽으로 확장

    // rm이 아직 Right값보다 작고, 높이가 rm+1이 높거나 lm이 가장 왼쪽값일 경우
    if (rm < right && (lm == left || nh[lm-1] < nh[rm + 1])) {
      ++rm;
      height = min(height, nh[rm]);
    }
    else {
      --lm;
      height = min(height, nh[lm]);
    }

    result = max(result, height * (rm - lm + 1));
  }

  return result;
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


    cout << "answer : " << maxRectengle << endl;
  }
}

/*
  2. 분할 정복
    1) 첫번째로 반절 나눈다.
    2) 왼쪽에서 가장 큰 직사각형, 오른쪽에서 가장 큰 직사각형, 가운데 겹치는 직사각형 3가지 중에서 가장 큰 직사각형을 구한다.

    -> 시간 복잡도 O(nlongN)

*/