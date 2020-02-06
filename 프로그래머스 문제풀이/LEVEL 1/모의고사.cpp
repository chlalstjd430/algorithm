#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int score[3];

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int one[5] = {1,2,3,4,5};
    int two[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int three[10] = {3,3,1,1,2,2,4,4,5,5};
    
    //채점
    int size = answers.size();
    for(int i = 0; i < size; i++){
        //1
        if(answers[i] == one[i%5])
            score[0]++;
        //2
        if(answers[i] == two[i%8])
            score[1]++;
        //3
        if(answers[i] == three[i%10])
            score[2]++;
    }
    
    int maxScore = max(score[0], max(score[1],score[2]));

    for(int i = 0; i < 3; i++){
        if(maxScore == score[i]){
            answer.push_back(i+1);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    //순위 비교
    
    
    
    
    return answer;
}
