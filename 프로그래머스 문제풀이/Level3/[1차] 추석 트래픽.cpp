#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

double abs(double num){
    if(num > 0) return num;
    return -num;
}

vector<string> splitByChar(string str, char ch){
    vector<string> result;
    
    int ind = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == ch){
            result.push_back(str.substr(ind, i - ind));
            ind = i + 1;
        }
    }
    result.push_back(str.substr(ind, str.size() - ind ));    
    
    return result;
}

int solution(vector<string> lines) {
    int answer = 0;
    int size = lines.size();
    
    vector<long> startTime;
    vector<long> endTime;
    
    for(int i = 0; i < size; i++){
        vector<string> line = splitByChar(lines[i], ' ');
        vector<string> time = splitByChar(line[1], ':');
        
        long d = (long)(stoi(time[0])*60*60*1000 + stoi(time[1])*60*1000 + stod(time[2])*1000);
        startTime.push_back(d - stod(line[2])*1000 + 1);
        endTime.push_back(d);       
    }
    
    for(int i = 0; i< size; i++){
        long s = startTime[i];
        long e = endTime[i];
        
        int tmp1 = 0;
        int tmp2 = 0;
        for(int j = 0; j < size; j++){
            long cs = startTime[j];
            long ce = endTime[j];
            
            if(s <= ce && s + 999 >= cs) tmp1++;
            if(e <= ce && e + 999 >= cs) tmp2++;
        }
        answer = max(answer, max(tmp1,tmp2));
    }
    
    return answer;
}
