#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
const int MAX = 300001;

int visited[MAX];
int A, P;

void dfs(int num) {
	if (visited[num] == 2) {
		return;
	}
	visited[num]++;

	int sum = 0;

	while (num)
	{
		sum += (int)pow((num % 10), P);
		num /= 10;
	}
	
	dfs(sum);
}

int main() {
	cin >> A >> P;

	dfs(A);

	int sum = 0;
	for (int i = 0; i < MAX; i++) {
		if (visited[i] == 1)
			sum++;
	}
	cout << sum <<'\n';	
}