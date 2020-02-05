#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int> > room;

bool compare(pair<int, int>  &p1, pair<int, int> &p2) {
	if (p1.second == p2.second) {
		return p1.first < p2.first;
	}

	return p1.second < p2.second;
}

int main() {
	int tc;

	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int a, b;
		cin >> a >> b;
		room.push_back(make_pair(a, b));
	}
	sort(room.begin(), room.end(), compare);

	int cnt = 0;
	int end = 0;

	for (int i = 0; i < tc; i++) {
		if (end <= room[i].first) {
			end = room[i].second;
			cnt++;
		}
	}
	
	cout << cnt << endl;
}
