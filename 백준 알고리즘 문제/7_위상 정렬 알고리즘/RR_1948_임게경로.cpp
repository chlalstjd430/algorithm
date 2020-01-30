#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 10002

using namespace std;

class Edge {
public:
	int node;
	int time;
	Edge(int node, int time) {
		this->node = node;
		this->time = time;
	}
};

int n, start, goal;
int inDegree[MAX], result[MAX], visited[MAX];
vector<Edge> map[MAX];
vector<Edge> reverseMap[MAX]; // ����ô�� ���� ����

void topologySort() {
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int current = q.front();
		q.pop();
		int mapSize = map[current].size();
		for (int i = 0; i < mapSize; i++) {
			Edge next = Edge(map[current][i].node, map[current][i].time);

			int totalTime = next.time + result[current]; // ���� �������� �Ÿ� + ����������� �Ÿ�
			if (result[next.node] <= totalTime) { // �ٸ� ��η� ���� �������� �Ÿ� <= ���� ���κ��� ���� �������� �Ÿ�
				result[next.node] = totalTime;
			}

			if (--inDegree[next.node] == 0) { // ���� ��带 ���� ���� ���� ��尡 �����Ƿ� inDegree -1 ����
				q.push(next.node);
			}
		}
	}

	cout << result[goal] << endl;
}

void traceBack() {
	queue<int> q;

	// ����� �������մϴ�.
	int count = 0;
	q.push(goal); // goal���� ���� ����
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		int reverseMapSize = reverseMap[front].size();
		for (int i = 0; i < size i++) {
			Edge next = Edge(reverseMap[front][i].node, reverseMap[front][i].time);

			if (result[front] - result[next.node] == next.time) { // ��������� ��� �Ÿ� - ����-1������ ��� �Ÿ� == ������� ����-1������ ���Ÿ�
				count++;
				if (visited[next.node] == 0) {
					q.push(next.node);
					visited[next.node] = 1;
				}
			}
		}
	}

	cout << count;
}

int main() {
	int m;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int x, node, time;
		cin >> x >> node >> time;
		map[x].push_back(Edge(node, time));
		reverseMap[node].push_back(Edge(x, time));
		inDegree[node]++;
	}

	cin >> start >> goal;

	topologySort();
	traceBack();


}