#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int vilages[51][51];
double v[51];
int n;
int d;
int p;
int q;
vector<int> path;
double cache[51][51];

void initCache() {
  for (int i = 0; i < 51; i++) {
    for (int j = 0; j < 51; j++) {
      cache[i][j] = -1;
    }
  }
}

double search(int here, int days) {
  if (days == d) return here == q ? 1.0 : 0.0;
  double ret = cache[here][days];
  if (ret > -0.5) return ret;
  ret = 0.0;

  for (int i = 0; i < n; i++) {
    if (vilages[here][i] == 1) {
      ret += search(i, days + 1) / v[here];
    }
  }

  return ret;
}

int main()
{
  int tc;
	cin >> tc;
	while (tc--) { 

		cin >> n >> d >> p;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> vilages[i][j];
        v[i] += vilages[i][j];
      }
    }

    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
      cin >> q;
      initCache();
      cout.precision(8);
      cout << search(p, 0) << " ";
    }
    cout << endl;
  }
}

/*
1
5 2 0
0 1 1 1 0
1 0 0 0 1
1 0 0 0 0
1 0 0 0 0
0 1 0 0 0
3
0 2 4
*/
