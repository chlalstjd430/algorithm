#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<string> v;
    int ind = 0;
    int size = s.size();
    for(int i = 0; i < size; i++){
        if(s[i] == ' '){
            v.push_back(s.substr(ind, i-ind +1));
            ind = i+1;
        }
    }
     v.push_back(s.substr(ind, size-ind));
    
    int vSize = v.size();
    for(int i = 0; i < vSize; i++){
        if('a' <= v[i][0] && v[i][0] <= 'z'){
            v[i][0] = v[i][0] + ('A' - 'a');
        }
        for(int j = 1; j < v[i].size(); j++){
            if('A' <= v[i][j] && v[i][j] <= 'Z'){
            v[i][j] = v[i][j] - ('A' - 'a');
        }
        }
        answer += v[i];
    }
    return answer;
}
