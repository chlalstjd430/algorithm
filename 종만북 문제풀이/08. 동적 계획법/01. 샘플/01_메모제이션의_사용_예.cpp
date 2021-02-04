#include <iostream>

using namespace std;

int cache[2500][2500];

int someObscureFunction(int a, int b) {
  // 기저사례
  //if () return ...;

  int ret = cache[a][b];
  if (ret != -1) return ret;

  //...


  return ret;
}

int main() {

}