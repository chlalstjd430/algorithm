
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<bool> findAnswer(progresses.size(), false);
    
    for(int i = 0; i < 100; i++){
        int progressSize = progresses.size();
        int cnt = 0;
        progresses[0] += speeds[0];
        if(progresses[0] >= 100 && !findAnswer[0] ){
                cnt++;
                findAnswer[0] = true;
        }
        for(int j = 1; j < progressSize; j++ ){
            progresses[j] += speeds[j];
            if(progresses[j] >= 100 && findAnswer[j-1] && !findAnswer[j] ){
                cnt++;
                findAnswer[j] = true;
            }
        }
        if(cnt != 0) answer.push_back(cnt);

    }
    return answer;
}
