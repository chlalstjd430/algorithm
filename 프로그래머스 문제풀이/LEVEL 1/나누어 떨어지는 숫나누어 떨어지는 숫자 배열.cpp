#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    int arrSize = arr.size();
    for(int i = 0; i < arrSize; i++){
        if(arr[i] % divisor == 0){
            answer.push_back(arr[i]);
        }
    }
    
    if(answer.size() == 0) answer.push_back(-1);
    sort(answer.begin(), answer.end());
    
    return answer;
}
