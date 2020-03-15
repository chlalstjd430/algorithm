#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int users = stages.size();
    int current[200002] = {0,};
    priority_queue<pair<double, int> > pq;
    
    for(int i = 0; i < users; i++){ 
        current[stages[i]]++;
    }
    
    for(int i = 1; i <= N; i++){
        int sum = 0;
        
        for(int j = i; j <= N+1; j++){
            sum += current[j];
        }
        
        double fail = (current[i] == 0) ? 0 : (double)current[i]/sum;
        pq.push(make_pair(fail, -i));
    }
    
    while(!pq.empty()){
        answer.push_back(-pq.top().second);
        pq.pop();
    }
    
    return answer;
}
