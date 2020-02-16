#include <string>
#include <vector>

using namespace std;

string numToMap(int num, int n){
    string map = "";
    while(num > 0){
        int tmp = num%2;
        if(tmp == 1) map += "#";
        else map += " ";
        num /= 2;
    }
    while(map.size() < n){
        map += " ";
    }
    return map;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for(int i = 0; i < n; i++){
        string s1 = numToMap(arr1[i], n);
        string s2 = numToMap(arr2[i], n);
        string result = "";
        for(int j = 0 ; j < n; j++){
            if(s1[j] == '#' || s2[j] == '#') result = "#" + result;
            else result = " " + result;
        }
        answer.push_back(result);
    }

    return answer;
}
