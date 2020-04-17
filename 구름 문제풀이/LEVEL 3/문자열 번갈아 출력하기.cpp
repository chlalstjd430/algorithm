#include <iostream>
using namespace std;
int main() {
	string input;
	getline(cin,input,'\n');
	
	int front = 0;
	int last = input.size() - 1;
	for(int i = 1; i <= input.size(); i++){
		if(i%2 == 1)
			cout << input[front++];
		else
			cout << input[last--];
	}
		
	
	return 0;
}
