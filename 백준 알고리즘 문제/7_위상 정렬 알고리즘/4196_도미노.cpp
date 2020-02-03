#include <iostream>
#include <vector>
#include <queue>
#define MAX 1000002
using namespace std;

int N, M;
int inDegree[MAX];
vector<int> graph[MAX];

void topologySort() {

}

int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		cin >> N >> M;

		for (int j = 0; j <= M; j++) {
			int a, b;
			cin >> a >> b;

			graph[a].push_back(b);
			inDegree[b]++;
		}
	}
}