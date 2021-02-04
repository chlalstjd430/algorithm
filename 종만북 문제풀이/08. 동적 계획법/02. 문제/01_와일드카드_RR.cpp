#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> words;
int cnt;
int cache[101][101];

// 1. 일반적인 방법
bool match(string pattern, string word) {
  // pattern[pos]와 word[pos]를 맞춰나간다.
  // pattern[pos]가 '*'를 가르킬때까지 pos++
  int pos = 0;
  while ((pos < word.size() && pos < pattern.size()) && 
    (pattern[pos] == '?' || pattern[pos] == word[pos])) {
    ++pos;
  }

  // 패턴 끝에 도달한 경우, 문자열도 끝났어야 대응
  if (pos == pattern.size()) {
    return pos == word.size();
  }

  // *를 만나는 경우. *에 몇 글자를 대응해야 할지 재귀 호출하며 확인한다.
  // *p*, help인 경우 -> p*, help / p*, elp / p*, lp / p*, p 를 차레대로 재귀
  if (word[pos] == '*') {
    for(int i = 0; pos + i <= pattern.size(); i++) {
      if (match(pattern.substr(pos + 1), word.substr(pos + i))) {
        return true;
      }
    }
  }

  return false;
}

// 2. 메모제이션 활용
bool matchMemo(string pattern, string word, int patternPos, int wordPos) {
  int ret = cache[patternPos][wordPos];
  if (ret != -1) return cache[patternPos][wordPos];
  
  while(patternPos < pattern.size() && wordPos < word.size() &&
    (pattern[patternPos] == '?' || pattern[patternPos] == word[wordPos])) {
      patternPos++;
      wordPos++;
  }

  if (patternPos == pattern.size()) {
    return cache[patternPos][wordPos] = (wordPos == word.size());
  }

  if (word[wordPos] == '*') {
    for (int i = 0; i + patternPos <= pattern.size(); i++) {
      if (matchMemo(pattern, word, patternPos + 1, wordPos + i)) {
        return cache[patternPos][wordPos] = 1;
      }
    }
  }

  return cache[patternPos][wordPos] = 0;
}

int main() {
  int tc;
  cin >> tc;
  while(tc-- > 0) {
    string pattern;
    cin >> pattern;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
      string tmp;
      cin >> tmp;

      words.push_back(tmp);
    }

    for (int i = 0; i < cnt; i++) {
      if (match(pattern, words[i])) {
        cout << words[i] << endl;
      }
    }

  }
}