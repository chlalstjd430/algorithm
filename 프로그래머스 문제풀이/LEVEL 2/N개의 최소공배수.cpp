#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    int arrSize = arr.size();
    sort(arr.begin(), arr.end());
    answer = arr[arr.size() - 1];
    while(true){
        bool find = true;
        for(int i = 0; i < arrSize; i++){
            if(answer%arr[i] == 0) continue;
            find = false;
            break;
        }
        if(find){
            break;
        }
        answer++;
    }
    
    return answer;
}
