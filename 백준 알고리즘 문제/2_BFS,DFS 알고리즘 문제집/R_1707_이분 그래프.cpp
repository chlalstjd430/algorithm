/*
	- �̺� �׷����� ���� ���������� ���� ���� ������ �Ѵ�. ���� �ΰ��� �����θ� ǥ���� �����Ͽ��� �Ѵ�.
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
int visitedColor[20001];// 0 - �湮X , 1 , 2
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
					if (color == 0) color = visitedColor[value]; // ������ �湮�ߴ� ���� �ִ� ����̸� ���� �˻����� ���� �ٸ� ���̹Ǹ� �� ���� color�� ����
					else if (color != visitedColor[value]) return false; // ������ �湮�ߴ� ���� �ִ� ���� ���鳢�� ���� �ٸ� ��� �̰Ϳ� �̺� �׷����� �ƴϴ�.
				}
			}
				
				visitedColor[current] = (color == 0) ? 1 : 3 - color;
		}

	}

	return true;

}


int main() {
	//test case �Է�
	cin >> tc;

	//vertex,edge �Է�
	for (int i = 0; i < tc; i++) {
		cin >> vertex >> edge;

		//�׷��� �Է�
		for (int i = 0; i < edge; i++) {
			cin >> x >> y;

			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		//isBipartite ����
		if (isBipartite()) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}

		//�׷��� �ʱ�ȭ
		for (int i = 0; i <= vertex; i++) {
			visitedColor[i] = 0;
			graph[i].clear();
		}

			
	}
}