#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string correct_string(string w) {
	if (w == "") return "";
	int w_size = w.size();
	int sum = 0;
	int div_index = -1;
    vector<bool> w_tmp;
    for (int i = 0; i < w_size; i++) {
		if (w[i] == '(') {
			w_tmp.push_back(true);
			continue;
		}
		if(!w_tmp.empty()){
			w_tmp.pop_back();
		 }
	}
    if(w_tmp.empty()) return w;
    

	if (w[0] == '(') {
		sum = 1;
	}
	else {
		sum = -1;
	}

	for (int i = 1; i < w_size; i++) {
		if (w[i] == '(') {
			sum += 1;
		}
		else {
			sum -= 1;
		}
		if (sum == 0) {
			div_index = i;
			break;
		}
	}
	string u = w.substr(0, div_index + 1);
	string v = w.substr(div_index + 1, w_size);

	int u_size = u.size();
	vector<bool> tmp;
	for (int i = 0; i < u_size; i++) {
		if (u[i] == '(') {
			tmp.push_back(true);
			continue;
		}
		if(!tmp.empty()){
			tmp.pop_back();
		 }
	}
	if (tmp.empty()) {
		return u + correct_string(v);
	}
	else {
		string str = "(" + correct_string(v) + ")";
		string uu = u.substr(1, u_size - 2);
        string tmp_uu = "";
        int uu_size = uu.size();
		
        for(int i = 0; i < uu_size; i++){
            if(uu[i] == '('){
                tmp_uu +=  ')';
            }
            else{
                tmp_uu += '(';
            }
        }

		return str + tmp_uu;
	}
}

string solution(string p) {
	string answer = "";
	answer = correct_string(p);
	return answer;
}
