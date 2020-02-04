#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char Inequality[11];
bool visited[11];

vector<char> num;
vector<string> answer;
int tc;


// Inequality에 저장되어있는 부등호에 맞게 비교되는 수열인지 확인
bool isPossible() {

	for (int i = 0; i < tc; i++) {
		if (Inequality[i] == '>') {
			if (!(num[i] - '0' > num[i+1] - '0')) return false;
		}
		else if(Inequality[i] == '<'){
			if (!(num[i] - '0' < num[i+1] - '0')) return false;
		}
	}

	return true;
}


// 순열을 만드는 재귀 함수
void dfs(int index) {
	// Inequality의 index값이 tc와 같아질 경우 부등호에 맞는지 검증
	if (index == tc + 1) {
		if (isPossible()) {
			string tmp = "";
			int size = num.size();
			for (int i = 0; i < size; i++) {
				tmp += num[i];
			}

			answer.push_back(tmp);
		}

		return;
	}
	for (int i = 0; i < 10; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		num.push_back(i + '0');
		dfs(index+1);
		visited[i] = false;
		num.pop_back();

	}
}

int main() {
	
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		char a;
		cin >> a;
		Inequality[i] = a;
	}

	dfs(0);
	sort(answer.begin(), answer.end());

	cout << answer[answer.size() - 1] << endl;
	cout << answer[0] << endl;
	
}
