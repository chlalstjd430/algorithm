#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> num;
    int size = s.size();
    
    string tmp="";
    for(int i = 0; i < size; i++){
        if(s[i] == ' '){
            num.push_back(stoi(tmp));
            tmp = "";
            continue;
        }
        tmp += s[i];
    }
    num.push_back(stoi(tmp));
    
    sort(num.begin(), num.end());
    
    answer = to_string(num[0]) +" " + to_string(num[num.size() - 1]);
    return answer;
}
