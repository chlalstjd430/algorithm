#include <iostream>
#include <vector>

using namespace std;

int main() {
	int moneyArr[6] = { 500, 100,50,10,5,1 };
	int money = 0;
	cin >> money;
	money = 1000 - money;
	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		cnt += money / moneyArr[i];
		money %= moneyArr[i];
	}

	cout << cnt << endl;
}
