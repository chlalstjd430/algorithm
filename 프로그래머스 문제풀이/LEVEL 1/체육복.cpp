#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> v(n+2,1);
    
    int lostSize = lost.size();
    for(int i = 0; i < lostSize; i++){
        v[lost[i]]--;
    }

    int reserveSize = reserve.size();    
    for(int i = 0; i < reserveSize; i++){
        int ind = reserve[i];
        v[ind]++;
    }
    
    for(int i = 0; i < reserveSize; i++){
        int ind = reserve[i];
        if(v[ind] < 2) continue;
        if(v[ind-1] == 0)
            v[ind-1]++;
        else if(v[ind+1] == 0)
            v[ind+1]++;
        
    }
    
    for(int i = 1; i <= n; i++){
        if(v[i] != 0) {
            answer++;
        }
    }
    
    return answer;
}
