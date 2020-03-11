#include <iostream>
using namespace std;
int main() {
	int num;
	cin >> num;
	num = num > 0 ? num : -num;
	cout << num << endl;
	return 0;
}
