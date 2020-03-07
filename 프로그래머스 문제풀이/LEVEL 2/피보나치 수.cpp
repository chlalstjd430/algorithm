#include <string>
#include <vector>

using namespace std;

int num[100001];
int solution(int n) {
    int answer = 0;
    if(n == 0) return 0;
    if(n == 1) return 1;
    
    num[0] = 0;
    num[1] = 1;
    for(int i = 2; i <= n; i++){
        num[i] = (num[i-1] + num[i-2])%1234567;
    }
    answer = num[n];
    
    return answer;
}
