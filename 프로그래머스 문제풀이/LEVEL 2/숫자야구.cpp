#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    int baseball_size = baseball.size();
    vector<string> answers;
    for(int i = 123; i <= 987; i++){
        string number = to_string(i);
        if(number[1] == '0' || number[2] == '0' ||
            number[0] == number[1] || number[1] == number[2] || number[0] == number[2]){
            continue;
        }
        answers.push_back(number);
    }
    for(int i = 0; i < baseball_size; i++){
        string number = to_string(baseball[i][0]);
        int answers_size = answers.size();
        for(int j = answers.size() - 1; j >= 0; j--){
            int strike = 0;
            int ball = 0;
            string check = answers[j];
            for(int k = 0; k < 3; k++){
                if(number[k] == check[k]){
                    strike++;
                }
                if(number[k] == check[(k+1)%3] || number[k] == check[(k+2)%3]){
                    ball++;
                }      
            }   
            if(baseball[i][1] == strike && baseball[i][2] == ball) continue;
                answers.erase(answers.begin() + j);
        }
    }
    answer = answers.size();
    return answer;
}
