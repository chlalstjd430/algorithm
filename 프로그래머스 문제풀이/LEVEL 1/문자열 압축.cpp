#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int len = s.length();
    int answer = len;
    
    for(int i = 1; i <= (len/2); i++){
        string result = "";
        string tmp = s.substr(0, i);
        int cnt = 1;
        
        for(int j = i; j <= len; j+=i){
            if(tmp == s.substr(j, i)){
                cnt++;
            }
            else{
                if(cnt == 1){
                    result += tmp;
                }
                else{
                    result += (to_string(cnt) + tmp);
                }
                tmp = s.substr(j, i);
                cnt = 1;
            }
        }      
        
        result += s.substr((len/i) * i); // 문자열을 자르는 단위에 포함 안되는 문자열 추가
        answer = min(answer, (int)result.length());      
    }
    return answer;
}
