#include <iostream>

using namespace std;

int sumByFor(int n) {
  int sum = 0;

  for (int i = 1; i <= n; i++) {
    sum += i;
  }

  return sum;
}

int sumByRecursive(int n) {
  if (n == 1) // base case
  {
    return 1;
  }
  return n + sumByRecursive(n-1);
}

int main() {
  cout << sumByFor(10) << endl;
  cout << sumByRecursive(10) << endl;
}