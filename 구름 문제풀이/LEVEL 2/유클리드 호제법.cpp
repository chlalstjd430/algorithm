#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
	while(b != 0){
		int tmpA = a%b;
		int tmpB = a%b;
		a = b;
		b = tmpA;
	}
	
	return a;
}

int main() {
	int a, b;
	cin >> a >> b;
	int maxN = max(a,b);
	int minN = min(a,b);
	cout << gcd(maxN,minN) << endl;
	
	return 0;
}
