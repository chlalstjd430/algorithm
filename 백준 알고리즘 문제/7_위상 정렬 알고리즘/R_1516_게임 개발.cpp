#include <iostream>
#include <vector>
#include <queue>
#define MAX 502
using namespace std;

int N;
int inDegree[MAX];
int buildTime[MAX];
int result[MAX];
vector<int> graph[MAX];


void topologySort() {
	queue<int> q;
	
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
			result[i] = buildTime[i];
		}
	}

	for (int i = 1; i <= N; i++) {
		if (q.empty()) break;
		int front = q.front();
		q.pop();

		int size = graph[front].size();
		for (int i = 0; i < size; i++) {
			int cur = graph[front][i];
			// 필요한 건물중 더 오래걸리는 건물의 시간만큼만 추가되면 된다.
			result[cur] = max(result[cur], result[front] + buildTime[cur]); 
			if (--inDegree[cur] == 0)
				q.push(cur);
		}
	}
}

int main() {
	cin >> N;

	int input = 0;
	for (int i = 1; i <= N; i++) {
		bool isFirstInput = true;

		while (true) {
			cin >> input;
			if (input == -1) break;

			if (isFirstInput) {
				buildTime[i] = input;
				isFirstInput = false;
			}
			else {
				graph[input].push_back(i);
				inDegree[i]++;
			}
		}
	}

	topologySort();

	for (int i = 1; i <= N; i++) {
		cout << result[i] << " ";
	}

}