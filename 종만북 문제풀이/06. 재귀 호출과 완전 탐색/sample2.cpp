#include <iostream>
#include <vector>

using namespace std;

void printPicked(vector<int> picked) {
  cout << "\npicked list" << endl;

  int size = picked.size();
  for (int i = 0; i < size; i++) {
    cout << picked[i] << " ";
  }
  cout << endl;
  
}

/*
  n : 전체 원소의 수
  picked: 지금까지 고른 원소드르이 번호
  toPick: 더 고를 원소의 수
*/
void pick(int n, vector<int> picked, int pickSize) {
  if (pickSize == 0 ) {
    printPicked(picked);
    return;
  }
  int smallest = picked.empty() ? 1 : picked.back() + 1;

  for (int i = smallest; i <= n; i++) {
    picked.push_back(i);
    pick(n, picked, pickSize - 1);
    picked.pop_back();
  }
}

int main() {
  /*
    중첩 반복문 대처
    - 01 n개의 원소 중 m개를 고르는 모든 조합을 찾는 알고리즘
  */
 vector<int> emptyPicked;
 pick(12, emptyPicked, 3);
}
