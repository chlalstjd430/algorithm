/*
	-������ �׷����� ���� ��� ���ϴ� �����̴�.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[10000];
int visited[10000];
int x, y;

void dfs(int num) {
	if (visited[num]) return;

	visited[num] = true;
	
	for (int i = 0; i < graph[num].size(); i++) {
		dfs(graph[num][i]);
	}
}

int main() {
	int node,edge, count = 0;

	cin >> node >> edge;
	
	for (int i = 0; i < edge; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for (int i = 1; i < node+1; i++) {
		if (!visited[i]) {
			dfs(i);
	
			count++;
		}
		else continue;
	}

	cout << count << endl;

}

/*
	Ʋ�ȴ� ����
	- ��尡 �ϳ��� ��츦 ���� ���ߴ�.
*/