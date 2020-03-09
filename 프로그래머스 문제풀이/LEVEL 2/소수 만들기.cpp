#include <vector>
#include <iostream>
using namespace std;

int answer;
int numbers[3001];

void isAnswer(int num){
    for(int i = 2; i < num; i++){
        if(num%i == 0) return;
    }
    answer++;    
    return;
}

void r(vector<int> nums, int ind, int cnt, int sum){
    if(ind > nums.size()) return;
    if(cnt == 3){
        isAnswer(sum);
        return;
    }
    
    r(nums, ind + 1, cnt + 1, sum + nums[ind]);
    r(nums, ind + 1, cnt, sum);
    
}

int solution(vector<int> nums) {
    answer = 0;
    r(nums, 0, 0, 0);

    return answer;
}
