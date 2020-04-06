#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int minNum = 9;

void dfs(int count, int number, int current, int target) {
    if(count > 8) return;
    if(current == target){
        minNum = min(minNum, count);
    }
    
    int tmp = 0;
    for(int i = 0; i < 8; i++){
        tmp = tmp*10 + number;
        
        dfs(count + 1 + i, number, current + tmp, target);
        dfs(count + 1 + i, number, current / tmp, target);
        dfs(count + 1 + i, number, current * tmp, target);
        dfs(count + 1 + i, number, current - tmp, target);
    }
}
int solution(int N, int number) {
    int answer = 0;
    
    dfs(0, N, 0, number);
    
    if(minNum >= 9)
        answer = -1;
    else
        answer = minNum;
    
    return answer;
}
