#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    
    stack<int > s;
    int size = arrangement.size();
    for(int i = 0; i < size; i++){
        if(arrangement[i] == '('){
            s.push(i);
        }
        else if(arrangement[i] ==')'){
            int top = s.top();
            // 레이저
            if(top == i -1){
                s.pop();
                answer += s.size();
                continue;
            }
            // 막대기 끝
            s.pop();
            answer++;
        }
    }
    return answer;
}
