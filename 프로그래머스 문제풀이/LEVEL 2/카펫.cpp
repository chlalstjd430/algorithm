#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;

    int sum = brown + red;
    for(int i = 3; i < sum; i++ ){
        if(sum % i == 0){
            int height = i;
            int weight = sum/height;
            if((height - 2)*(weight - 2) == red){
                answer.push_back(weight);    
                answer.push_back(height);                   
                break;
            }
        }
    }

    return answer;
}
