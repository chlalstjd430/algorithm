#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX = 10000;

int n;
double dist[10000][10000];
vector<int> path;
vector<bool> visited;

double shortesPath(double currentLength) {
  if (path.size() == n) {
    return currentLength + dist[path[0]][path.back()];
  }

  double ret = 987654321;

  for (int i = 0; i < n; i++) {
    if (visited[i]) continue;
    
    int here = path.back();
    path.push_back(i);
    visited[i] = true;
    double cand = shortesPath(currentLength + dist[here][i]);
    ret = min(ret, cand);
    visited[i] = false;
    path.pop_back();
  }

  return ret;
}

int main() {

}