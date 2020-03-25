#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if(!(s.length() == 4 || s.length() == 6)){
        answer = false;
        return answer;
    }
    for(int i = 0; i < s.length(); i++){
        if(!('0' <= s[i] && s[i] <= '9')){
            answer = false;
            break;
        }
    }
    return answer;
}
