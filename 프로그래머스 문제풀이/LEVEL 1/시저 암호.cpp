#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i = 0; i <  s.length(); i++){
        if(s[i] == ' ') continue;
        s[i] += n;
        if( 'z' < s[i] && s[i] < 'a')
            s[i] -= 'Z' - 'A' + 1;
        else if( 'z' < s[i])
            s[i] -= 'z' - 'a' + 1;
    }
    answer = s;
    return answer;
}
