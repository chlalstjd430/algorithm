#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
   int topSize = heights.size();
    vector<int> answer(topSize, 0);
    
    
    for(int i = 0; i < topSize; i++){
        for(int j = i-1; j >= 0; j--){
            if(heights[i] < heights[j]){
                answer[i] = j+1;
                break;
            }
        }
    }
    return answer;
}
