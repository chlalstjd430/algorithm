// "마을의 이장은 마을을 두 개의 분리된 마을로 분할할 계획을 가지고 있다" 가 핵심이었다.

#include <iostream>
#include <algorithm>
#include <vector>

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

bool compareParent(int parent[], int x, int y) {
	x = getParent(parent, x);
	y = getParent(parent, y);

	if (x == y) return true;
	return false;
}


int main() {
	int N = 0, M = 0;
	vector<Edge> vilage;
	int dist[100001];

	

	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		dist[i] = i;
	}
	int x, y, v;
	for (int i = 0; i < M;i++) {
		cin >> x >> y >> v;

		vilage.push_back(Edge(x, y, v));
	}

	sort(vilage.begin(), vilage.end());

	int sum = 0;
	int size = vilage.size();

	for (int i = 0; i < size; i++) {
		if (N == 2)break;
		if (!compareParent(dist, vilage[i].node[0], vilage[i].node[1])) {
			sum += vilage[i].value;
			unionParent(dist, vilage[i].node[0], vilage[i].node[1]);
			N--;
		}
	}

	cout << sum << endl;
}