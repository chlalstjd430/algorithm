#include <iostream>
#include <vector>
#include <string>

using namespace std;

int TC;
int students;
int group;
vector<vector<bool> > friends;
vector<bool> groups;

void init(int students, int group) {
  friends.clear();
  groups.clear();
  for (int i = 0; i < students; i++) {
    vector<bool> row;
    for (int j = 0; j < group; j++) {
      row.push_back(false);
    }
    friends.push_back(row);
    groups.push_back(false);
  }
}

int countGroup() {
  int studentNo = -1;
  for (int i = 0; i < students; i++) {
    if (groups[i] == false) {
      studentNo = i;
      break;
    }
  }

  if (studentNo == -1) return 1;

  int sum = 0;
  for (int i = studentNo + 1; i < students; i++) {
    if (friends[studentNo][i] && !groups[i]) {
      groups[studentNo] = groups[i] = true;
      sum += countGroup();
      groups[studentNo] = groups[i] = false;
    }
  }

  return sum;
}

int main() {
  cin >> TC;
  
  for (int i = 0; i < TC; i++) {
    cin >> students >> group;
    init(students, group);

    for (int j = 0; j < group; j++) {
      int a, b;
      cin >> a >> b;
      friends[a][b] = friends[b][a] = true;
    }

    cout << countGroup() << endl;
  }


}
/*
  풀이 방법

  1. 앞 번호 학생부터 완전 탐색
  2. 재귀
    1. 기저 사례 : 모든 학생들이 짝이 있다면 1리턴.(차례대로 검사)
    2. 재귀 부분
      - 짝이 없는 가장 앞 번호부터 완전 탐색
      - 기준 : 가장 앞번호 / 반복 : 그 이후부터 순회하면서 짝이 될 수 있다면 sum += 재귀() 이후 초기화
*/

/*
3 2 1 0 1 4 6 0 1 1 2 2 3 3 0 0 2 1 3 6 10 0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5
*/

void solve(int no) {
  if (no == 11)
  for (int i = no + 1; i < 10; i++) {
    if (f[no][i] && ) {}
  }
}