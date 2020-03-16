#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    map<string, int> record;
    
    int wordsSize = words.size();
    int ind = 0;
    for(int i = 0; i < wordsSize; i++){
        if(i%n == 0) ind++;
         // 단어 중복체크
        if(record[words[i]] == 0){
            record[words[i]] = 1;
        }
        else{
            answer[0] = i%n + 1;
            answer[1] = ind;
            break;
        } 
        if(i == 0) continue;
         // 끝말잇기 여부 체크
        if(words[i][0] != words[i-1][words[i-1].size() - 1]){
            answer[0] = i%n + 1;
            answer[1] = ind;
            break;
        }
        // 단어 길이 체크
        if(words[i].size() < 2 || words[i].size() > 50){
            answer[0] = i%n + 1;
            answer[1] = ind;
            break;
        }
             
    }
    
    return answer;
}
