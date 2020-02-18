#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int number_size = number.size();
    int value = -1;
    int value_ind;
    int kk = k;
    
    int default_last = number_size - k;
    k= number_size - k;
    for(int i = 0; i <= (number_size - k); i++){
        if(answer.size() == default_last) break;
        if(k == 0) {
            break;
        }
        int tmp = number[i] - '0';
        if(value < tmp){
            value = tmp;
            value_ind = i;
        }
        if(i == (number_size - k)){
            i = value_ind;
            value = -1;
            --k;
            answer += number[value_ind];
        }

    }
    if(answer.size() != default_last)
        answer += number.substr(value_ind+1);
    
    
    return answer;
}
