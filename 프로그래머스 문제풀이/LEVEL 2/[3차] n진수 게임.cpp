#include <string>
#include <vector>
#include <iostream>

using namespace std;

string makeNumber(int num, int make){
    if(num == 0) return "0";
    string result = "";
    while(num > 0){
        int m = num % make;
        if(10 <= m && m <= 15){
            result = (char)('A' + m -10) + result;
        }
        else
            result = to_string(num % make) + result;
        
        num /= make;
    }
    
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string numbers = "";
    
    
    int sum = m * t;
    for(int i = 0; i <= sum; i++){
        numbers += makeNumber(i, n);
    }
    for(int i = p; i <= sum; i += m){
        answer += numbers[i-1];
    }
    return answer;
}
