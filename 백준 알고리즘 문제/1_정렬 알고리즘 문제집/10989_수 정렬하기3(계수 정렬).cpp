#include <iostream>
#include <algorithm>
#include <stdio.h>
#pragma warning(disable:4996)
using namespace std;



int num[10001];


int main() {
	
	int count,tmp = 0;
	cin >> count;

	for (int i = 0; i < count; i++) {
		
		scanf("%d", &tmp);
		num[tmp]++;
	}
	printf("------------------\n");

	for (int i = 0; i < 10001; i ++ ) {
		while (num[i] != 0) {
			printf("%d\n", i);
			num[i]--;
		}
	}

}

/*
	- 속도면에서 cin,cout 보다 scanf,printf가 빠르다.
	- 마지막 for문에서 count까지가 아니라 10001번까지면 충분하다.
*/