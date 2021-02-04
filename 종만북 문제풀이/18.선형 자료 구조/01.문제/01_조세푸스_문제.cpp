#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N, K;
vector<int> v;

void initAry() {

  for (int i = 0; i < N; i++) {
    v.push_back(i + 1);
  }
}

void printAry() {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

bool isFinal() {
  return v.size() <= 2;
}

int main()
{
  int tc;
  cin >> tc;

  while(tc-- > 0) {
    cin >> N >> K;
    initAry();
    printAry();

    int target = 0;
    while(v.size() > 2) {
      cout << "target : " << v[target] << endl;
      v.erase(v.begin() + target);
      target = (target + K - 1) % v.size();
    }

    cout << "answer : ";
    for (int i = 0; i < v.size(); i++) {
      cout  << v[i] << " ";
    }
    cout << endl;
    v.clear();
  }
  
}
