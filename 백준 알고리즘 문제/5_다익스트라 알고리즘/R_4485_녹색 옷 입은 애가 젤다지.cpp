#include <iostream>
#include <queue>
#include <vector>

using namespace std; 

const int MAX = 127;
const int INF = 987654321;
int nx[] = { -1,0,0,1 };
int ny[] = { 0,-1,1,0 };	

int graph[MAX][MAX];
int visited[MAX][MAX];

void dijkstra(int index) {
	visited[1][1] = graph[1][1];
	priority_queue<pair<int, pair<int,int> > > pq;
	pq.push(make_pair(-visited[1][1], make_pair(1, 1)));

	while (!pq.empty()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int distance = -pq.top().first;
		pq.pop();


		for (int i = 0; i < 4; i++) {
			int dx = x + nx[i];
			int dy = y + ny[i];
			int nextDistance = graph[dx][dy]+ distance;

			if (1 > dx || dx > index || 1 > dy || dy > index) continue;

			
			if (nextDistance < visited[dx][dy]) {
				visited[dx][dy] = nextDistance;
				pq.push(make_pair(-nextDistance, make_pair(dx, dy)));
			}
		}			
	}
}

int main() {
	int index = 0; 
	int tc = 1;

	while (true) {
		cin >> index;

		if (index == 0) break;

		fill(&visited[0][0], &visited[MAX - 1][MAX - 1], INF);

		for (int i = 1; i <= index; i++) {
			for (int j = 1; j <= index; j++) {
				cin >> graph[i][j];
			}
		}

		dijkstra(index);
		cout << "Problem " << tc++ << ": " << visited[index][index] << endl;
	}
}