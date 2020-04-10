#include <string>
#include <vector>
#include <iostream>

using namespace std;
// 4 6 7 8 9 12 15 18 19
vector<string> splitChar(string str, char ch){
    vector<string> v;
    int ind = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == ch){
            v.push_back(str.substr(ind, i - ind));
            ind = i + 1;
        }      
    }
    v.push_back(str.substr(ind, str.size()-1));
    
    return v;
}

bool searchMelody(vector<string> m, vector<string> melody){
    bool result = true;
    for(int i = 0; i < melody.size(); i++){
        if(melody[i] != m[0]) continue;
        
        int k = i;
        for(int j = 0; j < m.size(); j++){          
            if(melody[k] != m[j]) {
                result = false;
                break;
            }    
            k++;
        }
        if(result) {
            return result;
        }
        result = true;
    }
    return false;
}

vector<string> findMelodyCode(string melody){
    vector<string> melodyCode;
    
     for(int j = 0; j < melody.size() - 1; j++){
            string code = "";
            code += melody[j];
            if(melody[j+1] == '#'){               
                code += melody[j+1];
                j++;
            }
            melodyCode.push_back(code);
        }
        if(melody[melody.size() - 1] != '#'){
            string code = "";
            code += melody[melody.size() - 1];
            melodyCode.push_back(code);  
        }
    
    return melodyCode;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    
    int currentTime = 0;
    for(int i = 0; i < musicinfos.size(); i++){
        vector<string> musicinfo = splitChar(musicinfos[i], ',');
        vector<string> startTime = splitChar(musicinfo[0], ':');
        vector<string> endTime = splitChar(musicinfo[1], ':');
        int sumTime = (stoi(endTime[0]) - stoi(startTime[0]))*60 + (stoi(endTime[1]) - stoi(startTime[1]));
        if(currentTime > sumTime) continue;
        if(currentTime == sumTime){
            if(answer != "(None)") continue;
        }
        
        vector<string> melodyCode = findMelodyCode(musicinfo[3]);
        vector<string> melody;
           
        for(int j = 0; j < sumTime; j++){
            int ind = j%melodyCode.size();
            melody.push_back(melodyCode[ind]);
        }
        if(searchMelody(findMelodyCode(m), melody)){
            answer = musicinfo[2];
            currentTime = sumTime;
        }
        
        
    }
    
    return answer;
}
