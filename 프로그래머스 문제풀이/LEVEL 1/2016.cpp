#include <string>
#include <vector>
#include <iostream>

using namespace std;

int month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string day[7] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};

string solution(int a, int b) {
    string answer = "";
    
    int d = 0;
    for(int i = 1; i < a; i++){
        d += month[i];
    }
    d += b;
    cout << d;
    int ind = d%7;
    answer = day[ind]+"";
    
    return answer;
}
