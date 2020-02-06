#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
	return p1.second < p2.second;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<pair<int, int> > brand;

	int minMoney = 987654321;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		brand.push_back(make_pair(a, b));
	}

	// 1. 모든 기타줄을 세트로만 구매했을 때
	sort(brand.begin(), brand.end());
	int setPrice = brand[0].first; // 가장 저렴한 세트의 가격
	int setCnt = N / 6; // 세트로 나눠지는 개수
	int piece = N % 6; // 세트로 나눠지고 남는 낱개 개수

	
	minMoney = (piece == 0) ? setCnt * setPrice : (setCnt + 1)*setPrice; // 세트 개수로 나누어졌을 때
	
	

	// 2. 세트 + 낱개로 구매했을 때
	sort(brand.begin(), brand.end(), compare);
	minMoney = min(minMoney, setPrice*setCnt + piece * brand[0].second);

	// 3. 모든 기타줄을 낱개로만 구매했을 때
	minMoney = min(minMoney, brand[0].second*N);

	cout << minMoney << endl;
}
