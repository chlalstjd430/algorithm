
using namespace std;
int cntN(int n){
    int cnt = 0;
    while(n > 1){
        if(n%2 == 1) cnt++;
        n /= 2;
    }
    
    return cnt;
}
int solution(int n) {
    int answer = 0;
    
    int current = cntN(n);
    for(int i = n+1; i < 1000001; i++){
        if(current == cntN(i)){
            answer = i;
            break;
        }
    }
 
    return answer;
}
