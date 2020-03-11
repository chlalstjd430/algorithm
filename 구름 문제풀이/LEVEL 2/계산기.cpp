#include <iostream>
using namespace std;
int main() {
	double first, second;
	char mod;
	cin >> first;
	cin >> mod;
	cin >> second;
	
	switch(mod){
		case '-' : cout << first - second <<endl;
			break;
		case '+' : cout << first + second <<endl;
			break;
		case '/' : 
			cout << fixed;
			cout.precision(2);
			cout << first / second <<endl;
			break;
		case '*' : cout << first * second <<endl;
			break;
			
	}
	
	return 0;
}
