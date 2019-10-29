#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dist[200002];
int m, n;

class Edge {
public:
	int node[2];
	int value;

	Edge(int x, int y, int value) {
		this->node[0] = x;
		this->node[1] = y;
		this->value = value;
	}

	bool operator < (Edge &edge) {
		return this->value < edge.value;
	}
};

int getParent(int parent[], int num) {
	if (parent[num] == num) return num;
	return parent[num] = getParent(parent, parent[num]);
}

void unionParent(int parent[], int x, int y) {
	x = getParent(parent, x);
	y = getParent(parent, y);

	if (x > y)parent[x] = y;
	else parent[y] = x;

}

bool equalParent(int parent[], int x, int y) {
	x = getParent(parent, x);
	y = getParent(parent, y);

	if (x == y) return true;
	return false;
}

int main() {
	vector<Edge> map;
	

	while (true) {
		cin >> m >> n;
		if (m == 0 && n == 0) break;

		for (int i = 0; i <= m; i++) {
			dist[i] = i;
		}

		int x = 0, y = 0, z = 0;

		for (int i = 0; i < n; i++) {
			cin >> x >> y >> z;
			map.push_back(Edge(x, y, z));
		}


		sort(map.begin(), map.end());

		int size = map.size();

		int sum = 0;
		for (int i = 0; i < size; i++) {
			sum += map[i].value;
		}
		for (int i = 0; i < size; i++) {
			if (!equalParent(dist, map[i].node[0], map[i].node[1])) {
				unionParent(dist, map[i].node[0], map[i].node[1]);
				sum -= map[i].value;
			}
		}

		cout << sum << endl;

		map.clear();
	}
}

