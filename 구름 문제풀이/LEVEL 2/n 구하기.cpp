#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int sum = 0;
	int ind = 0;
	for(int i = 1; i <= n; i++){
		sum+=i;
		ind = i;
		if(sum > n) break;
	}
	cout << ind << endl;
	return 0;
}
