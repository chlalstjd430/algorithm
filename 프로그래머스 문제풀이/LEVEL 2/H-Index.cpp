#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    int citations_size = citations.size();
    int first_index = 0;
    for(int i = 0; i < citations_size; i++){
        int cnt = citations_size - i;
        if(citations[i] <= cnt){
            first_index = i;
        }
    }
    
    
    for(int i = 0; i < citations[citations_size - 1]; i++){
        int cnt = 0;
        for(int j = 0; j < citations_size; j++){
            if(i <= citations[j]) cnt++;
        }
        if(i <= cnt){
            answer = max(answer, i);
        }
    }
    
    return answer;
}
