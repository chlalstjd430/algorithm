#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
   queue<pair<int, int> > q;
    priority_queue<int> pq;
    
    for(int i = 0; i < priorities.size(); i++){
        q.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }
    
    int index = 1;
    while(!q.empty()){
        if(q.front().second == pq.top()){
            if(location == q.front().first){
                answer = index;
                break;
            }
            else{
                index++;
                q.pop();
                pq.pop();
            }
        }
        else{
            q.push(q.front());
            q.pop();
        }
    }
    
    return answer;
}
