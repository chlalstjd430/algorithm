/*
	- 이분 그래프는 같은 레벨에서는 같은 색을 가져야 한다. 또한 두가지 색으로만 표현이 가능하여야 한다.
*/
//void bfs(int start) {
//	queue<int> q;
//	q.push(start);
//	visited[start] = true;
//
//	while (!q.empty()) {
//		int f = q.front();
//		q.pop();
//		cout << f << endl;
//
//		for (int i = 0; i < tree[f].size(); i++) {
//			if (!visited[tree[f][i]]) {
//				q.push(tree[f][i]);
//				visited[tree[f][i]] = true;
//			}
//		}
//	}
//	
//}
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector<int> graph[20001];
int visitedColor[20001];// 0 - 방문X , 1 , 2
int vertex, edge;

int tc;
int x, y;
string result;

bool isBipartite(){

	queue<int> q;
	
	for (int i = 1; i <= vertex; i ++ ) {
		if (visitedColor[i] != 0) continue;

		q.push(i);

		while (!q.empty()) {
			
			int current = q.front();
			q.pop();

			int color = 0;

			for (int k = 0; k < graph[current].size(); k++) {
				int value = graph[current][k];

				if (visitedColor[value] == 0) q.push(value);
				else {
					if (color == 0) color = visitedColor[value]; // 이전에 방문했던 적이 있는 노드이면 지금 검사중인 노드와 다른 색이므르 그 색을 color에 저장
					else if (color != visitedColor[value]) return false; // 이전에 방문했던 적이 있는 인접 노드들끼리 색이 다를 경우 이것운 이분 그래프가 아니다.
				}
			}
				
				visitedColor[current] = (color == 0) ? 1 : 3 - color;
		}

	}

	return true;

}


int main() {
	//test case 입력
	cin >> tc;

	//vertex,edge 입력
	for (int i = 0; i < tc; i++) {
		cin >> vertex >> edge;

		//그래프 입력
		for (int i = 0; i < edge; i++) {
			cin >> x >> y;

			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		//isBipartite 시작
		if (isBipartite()) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}

		//그래프 초기화
		for (int i = 0; i <= vertex; i++) {
			visitedColor[i] = 0;
			graph[i].clear();
		}

			
	}
}