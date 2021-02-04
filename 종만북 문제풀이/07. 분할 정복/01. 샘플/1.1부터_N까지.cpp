#include <iostream>

using namespace std;

int fastSum(int n) {
  if (n == 1) return 1;
  if (n % 2 == 1) return fastSum(n-1) + n;
  
  return 2*fastSum(n/2) + (n/2)*(n/2);
}

int fastSum2(int n) {
  if (n == 1) return 1;
  if (n % 2 == 1) return 2*fastSum(n/2) + (n/2)*(n/2) + n;
  
  return 2*fastSum(n/2) + (n/2)*(n/2);
}

int main() {

  cout << fastSum(101) << endl;
  cout << fastSum2(101) << endl;
}