#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge {
public :
	int node[2];
	int value;

	Edge(int x, int y, int value) {
		this->node[0] = x;
		this->node[1] = y;
		this->value = value;
	}

	bool operator <(Edge &edge) {
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
	if (x > y) parent[x] = y;
	else parent[y] = x;
}

int findParent(int parent[], int x, int y) {
	x = getParent(parent, x);
	y = getParent(parent, y);

	if (x == y) return true;
	return false;
}

int main() {
	vector<Edge> computer;
	int dist[10002];
	int N = 0, M = 0;
	int x, y, v;

	for (int i = 0; i < 1002; i++) {
		dist[i] = i;
	}
	
	cin >> N >> M;

	
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> v;
		computer.push_back(Edge(x, y, v));
	}

	sort(computer.begin(), computer.end());
	int sum = 0;
	int size = computer.size();
	for (int i = 0; i < size; i++) {
		if (!findParent(dist, computer[i].node[0], computer[i].node[1])) {
			sum += computer[i].value;
			unionParent(dist, computer[i].node[0], computer[i].node[1]);
		}
	}

	cout << sum << endl;
}