#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	vector<bool> v(1000000001, false);
	for(int i = 1; i <= 10000; i++){
		v[i*i] = true;
	}
	
	int a, b;
	cin >> a >> b;
	
	bool flag = false;
	int minNum =9875654321;
	int sum = 0;
	for(int i = a; i <= b; i++){
		if(v[i]){
			sum += i;
			if(!flag){
				flag = true;
				minNum = i;
			}
		}
	}
	
	cout << minNum << " " << sum << endl;
	return 0;
}
