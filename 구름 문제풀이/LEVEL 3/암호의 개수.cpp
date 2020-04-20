#include <iostream>
using namespace std;
int main() {
	int answer = 0;
	int a, b, n;
	cin >> a >> b >> n;
	
	for(int i = a; i <= b; i++){
		int mul = 1;
		for(int j = 1; j <= i; j++){
			mul *= n;
		}
		answer += mul;
	}
	
	cout << answer << endl;
	return 0;
}
