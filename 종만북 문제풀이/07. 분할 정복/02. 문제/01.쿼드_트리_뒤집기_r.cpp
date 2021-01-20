#include <iostream>
#include <string>

using namespace std;

// 검은색 : b
// 흰색 : w
// x (왼쪽위 - 오른쪽위 - 왼쪽아래 - 오른쪽아래)

string zipImage;
int ind;

void input() {
  cin >> zipImage;
}

void init() {
  ind = 0;
}

string decompress() {
  char cur = zipImage[ind++];
  if(cur != 'x') 
    return string(1, cur);
  
  string upperLeft = decompress();
  string upperRight = decompress();
  string lowerLeft = decompress();
  string lowerRight = decompress();

  return "x" + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main() {
  int tc;
  cin >> tc;
  cout << "=============test============" << endl;
  while(tc-- > 0) {
    input();
    init();
    cout << zipImage << " => ";
    cout << decompress() << endl;
  }

}

/*
  1. 해결방법
    1)
      1 2       1 S        3 4
      3 4  ->   3 4    ->  1 S
      제 자리에서 뒤집고, 위아래를 바꾼다.
    
    2) 
      문자열을 차례대로 탐색하면서, w나 b이면 바로 리턴하고 그 외의 경우는 제 자리에서 뒤집고, 위아래를 바꾼다.
      위 문제의 경우 제 자리에서 뒤집어도 흑과 백으로만 표현되기에 따로 처리할 필요는 없다.

      왼쪽위,오른쪽위,왼쪽아래,오른쪽아래 순서대로 하는게 핵심

    3)
      시간복잡도는 O(n)
4
w
xbwwb
xbwxwbbwb
xxwwwbxwxwbbbwwxxxwwbbbwwwwbb

*/