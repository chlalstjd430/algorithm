#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int partSize = participant.size();
    int compSize = completion.size();
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i = 0; i < compSize; i++){
        if(completion[i] != participant[i]){
            answer = participant[i];
            return answer;
        }
    }
    answer = participant[partSize -1];

    return answer;
}
