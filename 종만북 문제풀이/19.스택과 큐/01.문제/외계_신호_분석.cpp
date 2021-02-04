#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

vector<int> signals;

int simple(int k) {
  int result = 0;
  for (int i = 0; i < signals.size(); i++) {
    int sum = 0;
    for (int j = i; j < signals.size(); j++) {
      // sum은 [i, j] 구간의 합
      sum += signals[j];
      if (sum == k) result++;
      if (sum >= k) break;
    }
  }

  return result;
}

int optimized(int k) {
  int result = 0 , tail = 0, rangeSum = signals[0];
  for (int head = 0; head < signals.size(); head ++) {
    while (rangeSum < k && tail < signals.size() - 1) {
      rangeSum += signals[++tail];
    }

    if (rangeSum == k) result++;

    rangeSum -= signals[head];
  } 

  return result;
}

int test(int k) {
  int tail = 0, result = 0, sum = signals[0];

  for (int front = 0; front < signals.size(); front++) {
    while (sum < k && tail < signals.size() - 1) {
      tail++;
      sum += signals[tail];
    }

    if (sum == k) result++;
    sum -= signals[front];
  }

  return result;
}



struct RNG {
  unsigned seed;
  RNG() : seed(1983) {}
  unsigned next() {
    unsigned ret = seed;
    seed = ((seed * 214013u) + 2531011u);
    return ret % 10000 + 1;
  }
};

int countRanges(int k, int n) {
  RNG rng;
  queue<int> range;
  int result = 0, rangeSum = 0;

  for (int i = 0; i < n; i++) {
    int newSignal = rng.next();
    rangeSum += newSignal;
    range.push(newSignal);

    while(rangeSum > k) {
      rangeSum -= range.front();
      range.pop();
    }

    if (rangeSum == k) result++;
  }

  return result;
}


int main()
{
  int tc;
  cin >> tc;

  while(tc-- > 0) {
    
  }
  
}
