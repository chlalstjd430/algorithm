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
	- �ӵ��鿡�� cin,cout ���� scanf,printf�� ������.
	- ������ for������ count������ �ƴ϶� 10001�������� ����ϴ�.
*/