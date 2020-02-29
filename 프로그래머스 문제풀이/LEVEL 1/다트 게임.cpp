#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int currentNumber = 0;
    
    vector<int> answers;
    int dartResultSize = dartResult.size();
    for(int i = 0; i < dartResultSize; i++){
        if(dartResult[i] == '0' && dartResult[i-1] == '1'){
            currentNumber = 10;
            continue;
        }
        if('0' <= dartResult[i] && dartResult[i] <= '9'){
            answers.push_back(currentNumber);
            currentNumber = dartResult[i] - '0';
            continue;
        }
        if(dartResult[i] =='D'){
            int tmp = currentNumber;
            currentNumber = tmp * tmp;
            continue;
        }
        if(dartResult[i] =='T'){
            int tmp = currentNumber;
            currentNumber = tmp * tmp * tmp;
            continue;
        }
        if(dartResult[i] =='*'){
            int answersSize = answers.size();
            currentNumber = currentNumber * 2;
            answers[answersSize - 1] = answers[answersSize - 1]*2;
            continue;
        }
        if(dartResult[i] =='#'){
            currentNumber = -currentNumber;
            continue;
        }
    }
    if('0' > dartResult[dartResultSize-1] || dartResult[dartResultSize-1] > '9'){
        answers.push_back(currentNumber);
    }
    
    int answersSize = answers.size();
    for(int i = 0; i < answersSize; i++){
        cout << answers[i] << " ";
        answer += answers[i];
    }
    return answer;
}
