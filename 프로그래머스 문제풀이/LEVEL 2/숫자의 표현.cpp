#include <string>
#include <vector>

using namespace std;


int solution(int n) {
    int answer = 0;
    int startNum = 1;
    int sum = 0;
    
    for(int i = startNum; i <= n; i++){
        sum += i;
        if(sum >= n){
            if(sum == n) answer++;
            i = startNum;
            startNum++;
            sum = 0;
        }
        
    }
    
    return answer;
}
