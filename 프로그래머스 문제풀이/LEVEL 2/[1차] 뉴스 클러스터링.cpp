#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

void test(string str, vector<string> v){
    cout << str << " : " ;
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

string makeMinAlpha(string str){
    int plu = 'a' - 'A';
    int strSize = str.size();
    for(int i = 0; i < strSize; i++){
        if('A' <= str[i] && str[i] <= 'Z'){
            str[i] += plu;
        }
    }
    
    return str;
}

bool isAlpha(char ch){
    if('a' <= ch && ch <= 'z'){
        return true;
    }
    return false;
}

map<string, int> makeMap(string str){
    map<string, int> m;
    
    for(int i = 0; i < str.size() - 1; i++){
        if(isAlpha(str[i]) && isAlpha(str[i+1])){
            string tmp;
            tmp += str[i];
            tmp += str[i+1];
            m[tmp] = m[tmp] + 1;
        }
    }
    
    return m;
}

vector<string> makeVector(string str){
    vector<string> v;
    for(int i = 0; i < str.size() - 1; i++){
        if(isAlpha(str[i]) && isAlpha(str[i+1])){
            string tmp;
            tmp += str[i];
            tmp += str[i+1];
            v.push_back(tmp);
        }
    }
    
    return v;
}

int solution(string str1, string str2) {
    int answer = 0;
    str1 = makeMinAlpha(str1);
    str2 = makeMinAlpha(str2);
    
    map<string, int> m1 = makeMap(str1);
    map<string, int> m2 = makeMap(str2);
    vector<string> v1 = makeVector(str1);
    vector<string> v2 = makeVector(str2);
    
    vector<string> intersection_v;
    map<string, int> check_duplication;
    for(int i = 0; i < v1.size(); i++){
        if(check_duplication[v1[i]] == 0){
            check_duplication[v1[i]] = 1;
            intersection_v.push_back(v1[i]);
        }
    }
     for(int i = 0; i < v2.size(); i++){
        if(check_duplication[v2[i]] == 0){
            check_duplication[v2[i]] = 1;
            intersection_v.push_back(v2[i]);
        }
    }
    
   int in = 0, un = 0;
   for(int i = 0; i < intersection_v.size(); i++){
       string s = intersection_v[i];
       in += min(m1[s], m2[s]);
       un += max(m1[s], m2[s]);
   } 
    
    if(in == 0 && un == 0) return 65536;
    else if(in == 0) return 0;
    else{
        double tmp = (double)in/un;
        answer = (int)(tmp * 65536);
    }
    
    
    return answer;
}
