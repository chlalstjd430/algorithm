#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(char s1, char s2){
    return s1 > s2;
}

string solution(string s) {
    string answer = s;
    sort(answer.begin(), answer.end(), compare);
    return answer;
}
