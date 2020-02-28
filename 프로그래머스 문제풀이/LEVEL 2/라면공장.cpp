#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    priority_queue<int> pq;
    int before_stock = 0;
    int ind = 0;
    while(stock < k){
        int dates_size = dates.size();
        for(int i = ind; i < dates_size; i++){
            if(before_stock <= dates[i] && dates[i] <= stock){
                ind = i + 1;
                pq.push(supplies[i]);
            }
        }
        before_stock = stock;
        stock += pq.top();
        pq.pop();
        answer++;
    }
    return answer;
}
