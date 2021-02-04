#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const long long NEGINF = numeric_limits<long long>::min();
int n, m, A[100], B[100];
int cache[101][101];

int jlis(int posA, int posB) {
  // 메모제이션
  int ret = cache[posA + 1][posB + 1];
  if(ret != -1) return ret;

  // A[index], B[index]가 이미 존재하므로 2개는 항상 있다.
  ret = 2;

  long long a = (posA == -1 ? NEGINF : A[posA]);
  long long b = (posB == -1 ? NEGINF : B[posB]);
  long long maxElemnet = max(a, b);

  for (int i = posA + 1; i < n; i++) {
    if (maxElemnet < A[i]) {
      ret = max(ret, jlis(i, posB) + 1);
    }
  }
  for (int i = posB + 1; i < n; i++) {
    if (maxElemnet < B[i]) {
      ret = max(ret, jlis(posA, i) + 1);
    }
  }

  return cache[posA][posB] = ret;
}

int main() {

}