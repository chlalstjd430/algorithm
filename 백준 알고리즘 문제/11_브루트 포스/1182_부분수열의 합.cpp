#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S;
int cnt;
vector<int> v;
int arr[20];

void solution(int ind, int sum) {
	sum += v[ind];
	if (N <= ind) {
		return;
	}
	if (sum == S) {
		cnt++;
	}
	
	solution(ind + 1, sum - v[ind]);
	solution(ind + 1, sum);
}

int main() {
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	v.push_back(0);

	solution(0, 0);

	cout << cnt << endl;

}
