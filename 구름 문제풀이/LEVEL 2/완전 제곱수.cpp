#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	vector<int> v;
	int tc;
	cin >> tc;
	
	vector<int> cnt(1000001, 0);
	for(int i =1; i <= 1000; i++){
		cnt[i*i] = 1;
	}
	
	int result = 0;
	for(int i = 0; i < tc; i++){
		int tmp;
		cin >> tmp;
		result+= cnt[tmp];
	}
	
	cout << result << endl;
	
	return 0;
}
