#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	vector<pair<int, int> > bridge(bridge_length, make_pair(0, 0));
	vector<int> goal;
	int truck_size = truck_weights.size();
	int ind = 0;
	while (true) {
		if (goal.size() == truck_size) {
			break;
		}
		answer++;		// 1초 증가

		// 다리를 지나는 트럭이 있다면 goal에 추가
		if (bridge[bridge_length - 1].first != 0) {
			goal.push_back(bridge[bridge_length - 1].first);
		}

		// 다리를 한칸씩 지난다.
		for (int i = bridge_length - 1; i >= 1; i--) {
			bridge[i] = bridge[i - 1];
		}
		bridge[0] = make_pair(0, 0);

		if (ind >= truck_size) continue;		// index가 벗어나면 위에 과정만 진행한다.

		// 다리에 있는 트럭의 무게들을 구한다
		int bridge_weight = 0;
		for (int i = 0; i < bridge_length; i++) {
			bridge_weight += bridge[i].second;
		}
		// 다리가 무게를 허용한다면 다리의 첫칸에 트럭을 넣는다
		if ((bridge_weight + truck_weights[ind]) <= weight) {
			bridge[0] = make_pair(ind + 1, truck_weights[ind]);
			ind++;
		}
	}


	return answer;
}
