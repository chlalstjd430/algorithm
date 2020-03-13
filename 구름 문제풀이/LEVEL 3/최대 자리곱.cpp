#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int makeResult(int n){
	int result = 1;
	while(n!=0){
		result *= (n%10);
		n/=10;
	}
	return result;
}

using namespace std;
int main() {
	int n;
	cin >> n;
	
	int result = makeResult(n);
	string str = to_string(n);
	int size = str.size();
	int mul = 10;
	for(int i = 1; i < size; i++){
		int tmp = n%mul + 1;
		n -= tmp;
		mul *= 10;
		result = max(result, makeResult(n));
	}
	cout<<result<<endl;
	
	return 0;
}
