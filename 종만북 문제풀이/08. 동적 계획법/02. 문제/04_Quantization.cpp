#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int ary[101];
int cache[11][11][11];

int n, s;
int main() {
  int tc;
  cin >> tc;

  while(tc-- > 0) {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
      cin >> ary[i];
    }
    sort(ary, ary + n);
    
  }
}
