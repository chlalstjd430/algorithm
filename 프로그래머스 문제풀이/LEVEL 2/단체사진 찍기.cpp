#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string friends = "ACFJMNRT";
int friends_size = friends.size();
bool visited[8];
int answer = 0;
vector<string> data_tmp;


void check(string f, map<char, int> info){
    int data_size = data_tmp.size();

    for(int i = 0; i < data_size; i++){
        int tmp = info[data_tmp[i][0]] - info[data_tmp[i][2]];
        tmp = tmp >= 0 ? tmp : -(tmp);
        tmp--;
        int num = (data_tmp[i][4] - '0');

        if(data_tmp[i][3] == '='){
            if(tmp != num) return;
        }
        else if(data_tmp[i][3] == '>'){  
            if(tmp <= num) return;
        }
        else if(data_tmp[i][3] == '<'){
            if(tmp  >= num) return;
        }
    }
     answer ++;
    return;
}

void r(string result, int ind, map<char, int> info){
    if(ind == 8){
        check(result, info);
        return;
    }

    for(int i = 0; i < friends_size; i++){
        if(visited[i] == false){
            visited[i] = true;
            info[friends[i]] = ind;
            r(result + friends[i], ind + 1, info);
            visited[i] = false;
        }
    }

}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    data_tmp = data;
    map<char,int> info;
    answer = 0;
    for(int i=0;i<friends.size();i++) {
        visited[i] = false;
    }
    r("", 0, info);
    return answer;
}
