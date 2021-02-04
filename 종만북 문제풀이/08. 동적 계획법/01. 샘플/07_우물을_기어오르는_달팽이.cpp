#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n, m;
int cache[100][201];
double cache2[100][201];

void initCache() {
  for(int i = 0; i < 100; i++) {
    for (int j = 0; j < 201; j++) {
      cache[i][j] = -1;
      cache2[i][j] = -1.0;
    }
  }
}
int climb(int days, int climbed) {
  if (days == n) return climbed >= m ? 1 : 0;
  
  int ret = cache[days][climbed];
  if (ret == -1) return ret;

  return cache[days][climbed] = climb(days + 1, climbed + 1) + climb(days + 1, climbed + 2);
}

double climb2(int days, int climbed) {
  if (days == n) return climbed >= m ? 1 : 0;
  
  int ret = cache2[days][climbed];
  if (ret == -1) return ret;

  return cache2[days][climbed] = 0.5 * climb2(days + 1, climbed + 1) + 0.5 * climb2(days + 1, climbed + 2);
}

int main() {
  n = 10; m = 20;
  cout << climb(0, 0) / pow(2, n) << endl;
  cout << climb2(0, 0) << endl;
}
