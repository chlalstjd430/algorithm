#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;



int solution(vector<vector<string>> clothes) {
	int answer = 1;
	map<string, int> m;
	vector<string> order;
	
	int clothes_size = clothes.size();
	for (int i = 0; i < clothes_size; i++) {
		if (m[clothes[i][1]] == 0) {
			m[clothes[i][1]]++;
			order.push_back(clothes[i][1]);
			continue;
		}
		m[clothes[i][1]]++;
	}
	for (int i = 0; i < order.size(); i++) {
		answer = answer * (m[order[i]] + 1);
	}
	answer -= 1;
	return answer;
}
