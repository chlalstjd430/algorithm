#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    stack<char> st;
    stack<char> st2;
    int sSize = s.length();
    for(int i = 0; i < sSize; i++){
        if(s[i] == '('){
            st.push(s[i]);
            continue;
        }
        if(st.size() == 0) return false;
        
        st.pop();
    }
    if(st.size() != 0) answer = false;

    return answer;
}
