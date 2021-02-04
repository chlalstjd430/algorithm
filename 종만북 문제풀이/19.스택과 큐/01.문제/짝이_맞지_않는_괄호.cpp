#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

stack<char> s;

int main()
{
  int tc;
  cin >> tc;

  while(tc-- > 0) {
    string result = "YES";
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
      char current = str[i];
      if (current == '(' || current == '[' || current == '{') {
        s.push(str[i]);
        continue;
      }
      char last = s.top();
      if ((current == ')' && last == '(') 
      || (current == ']' && last == '[') 
      || (current == '}' && last == '{')) {
        s.pop();
      }
      else {
        result = "NO";
        break;
      }
      
    }

    cout << result << endl;
  }
  
}
