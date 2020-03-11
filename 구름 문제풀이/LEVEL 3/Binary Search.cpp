#include <iostream>
#include <vector>

using namespace std;
int main() {
	int n;
	cin >> n;
	
	vector<int> v;
	for(int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	
	int find;
	cin >> find;
	
	int result = -1;
	if(v[n/2] == find){
		cout << n/2 + 1 <<endl;
		return 0;
	}
	else if(v[n/2] < find){
		for(int i = n/2+1; i < n; i++){
			if(v[i] == find){
				cout << i + 1 << endl;
				return 0;
			}
		}
	}
	else if(v[n/2] > find){
		for(int i = 0; i < n/2; i++){
			if(v[i] == find){
				cout << i + 1 << endl;
				return 0;
			}
		}
	}
	cout << 'X' << endl;
	return 0;
}
