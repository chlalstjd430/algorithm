#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int max_number = 0;


bool cmp(string a, string b){   
    if(a.size() == b.size())
        return a > b;
    
    return a + b > b + a;
}
// 3 30 34

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> numbers_str;
    int numbers_size = numbers.size();
    for(int i = 0; i < numbers_size; i++){
        numbers_str.push_back(to_string(numbers[i]));
    }
    sort(numbers_str.begin(), numbers_str.end(), cmp);
    
    for(int i = 0; i < numbers_size; i++){
        answer += numbers_str[i];
    }
    if(answer[0] == '0'){
        long long int tmp = stoi(answer);
        answer = to_string(tmp);
    }
    

    return answer;
}
