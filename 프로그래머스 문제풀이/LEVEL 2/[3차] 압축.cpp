#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> directory;

string ctos(char ch){
    string str = "";
    str += ch;
    
    return str;
}

int search(string word){
    for(int i = 0; i < directory.size(); i++){
        if(word == directory[i])
            return i + 1;
    }
    
    return -1;
}

vector<int> solution(string msg) {
    vector<int> answer;
    
    // 사전 초기화
    for(int i = 0; i < 26; i++){
        directory.push_back(ctos('A' + i));
    }
    
    for(int i = 0; i < msg.size(); i++){
        string word = "";
        
        for(int j = i; j < msg.size(); j++){
            string before = word;
            word += msg[j];
            int searchResult = search(word);
            if(searchResult == -1) {
                i = j - 1;
                answer.push_back(search(before));
                directory.push_back(word);
                
                break;
            }
            
            // 마지막 문자열일 경우
            if(j == msg.size() - 1){
                answer.push_back(search(word));
                i = msg.size();
                break;
            }
        }
    }
    
    return answer;
}
