#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1000000;
const int MAX = 10000;
int N, E;

vector<pair<int, int> > graph[MAX];

int visited[MAX];

void dijkstra(int start) {
	visited[start] = 0;
	priority_queue<pair<int,int> > pq;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		
		int size = graph[current].size();
		for(int i = 0; i < size; i++){
			int next = graph[current][i].first;
			int nextDistance = distance + graph[current][i].second;

			if (nextDistance < visited[next]) {
				visited[next] = nextDistance;
				pq.push(make_pair(-nextDistance, next));
			}
		}
	}
}

void init() {
	fill(&visited[0], &visited[MAX - 1], INF);
}

int isINF(int goal) {
	if (visited[goal] == INF)
		return -1;
	else
		return visited[goal];
}

int isPossible(int a, int b, int c, int d) {

	init();
	dijkstra(a);
	int a_b = isINF(b);

	init();
	dijkstra(b);
	int b_c = isINF(c);

	init();
	dijkstra(c);
	int c_d = isINF(d);

	if (a_b == -1 || b_c == -1 || c_d == -1) return INF;

	return a_b + b_c + c_d;
}

int main() {
	cin >> N >> E;

	int a, b, c;
	int start, goal;

	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}

	cin >> start >> goal;

	int one = isPossible(1, start, goal, N);
	int two = isPossible(1, goal, start, N);

	int result = min(one, two);
	cout << (result >= INF ? -1 : result);
}

/*
	총 거리
	1) 1 -> a -> b -> N
		즉, 1에서 a가지 가는 다익스트라 + a에서 b까지 가는 다익스트라 + b에서 N까지 가는 다익스트라를 구해서 합산하면 된다.
		(단, 다익스트라 하나마다 경로가 있는지 확인해야 한다.

	2) 1 -> b -> a -> N
		위 와 마찬가지
*/