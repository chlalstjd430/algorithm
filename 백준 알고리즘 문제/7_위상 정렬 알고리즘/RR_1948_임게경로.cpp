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
vector<Edge> reverseMap[MAX]; // 역추척을 위한 벡터

void topologySort() {
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int current = q.front();
		q.pop();
		int mapSize = map[current].size();
		for (int i = 0; i < mapSize; i++) {
			Edge next = Edge(map[current][i].node, map[current][i].time);

			int totalTime = next.time + result[current]; // 다음 노드까지의 거리 + 현재노드까지의 거리
			if (result[next.node] <= totalTime) { // 다른 경로로 다음 노드까지의 거리 <= 현재 노드로부터 다음 노드까지의 거리
				result[next.node] = totalTime;
			}

			if (--inDegree[next.node] == 0) { // 다음 노드를 가기 위한 현재 노드가 끝나므로 inDegree -1 감소
				q.push(next.node);
			}
		}
	}

	cout << result[goal] << endl;
}

void traceBack() {
	queue<int> q;

	// 결과를 역추적합니다.
	int count = 0;
	q.push(goal); // goal에서 부터 시작
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		int reverseMapSize = reverseMap[front].size();
		for (int i = 0; i < size i++) {
			Edge next = Edge(reverseMap[front][i].node, reverseMap[front][i].time);

			if (result[front] - result[next.node] == next.time) { // 현재까지의 노드 거리 - 현재-1까지의 노드 거리 == 현재부터 현재-1까지의 노드거리
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