#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    if(n == 1) {
        answer.push_back(0);
        return answer;
    }
    if(n == 2){
        answer.push_back(0);
        answer.push_back(0);
        answer.push_back(1);
        return answer;
    }
    string result = "001";
    for(int i = 3; i <= n; i++){
        string tmp = result;
        string tmp2 = result;
        tmp2[result.size()/2] = '1';
        result = tmp + '0' + tmp2;
    }
    int result_size = result.size();
    for(int i = 0; i < result_size; i++){
        answer.push_back(result[i] - '0');
    }    
    
    return answer;

}
