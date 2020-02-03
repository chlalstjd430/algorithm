#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int k;
int cnt;
vector<int> s;

bool compare (int a, int b){
    return a > b;
}

bool check_scoville(){
    int size = s.size();
    int result = true;
    for(int i = 0; i < size; i++){
        if(s[i] < k){
            result = false;
            break;
        }
    }

    return result;
}

int solution(vector<int> scoville, int K) {
    int answer = 0;
    s = scoville;
    k = K;
    cnt = 0;

    while(true){
        int size = s.size();
        if(check_scoville() || size == 1 ){
            break;
        }
        sort(s.begin(), s.end(), compare);

        int a = s[size - 1];
        int b = s[size - 2];
        s[size-2] = a + b * 2;
        s.pop_back();
        cnt++;
    }

    if(check_scoville()){
        answer = cnt;
    }
    else answer = -1;

    return answer;
}
