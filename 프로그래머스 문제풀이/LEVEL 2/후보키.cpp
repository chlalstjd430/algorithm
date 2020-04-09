#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int countBits(int n){
    int ret = 0;
    while(n){
        if(n & 1) ret++;
        n = n >> 1;
    }
    
    return ret;
}

bool cmp(int a, int b){
    a = countBits(a);
    b = countBits(b);
    return a < b;
}

bool check(vector<vector<string> > relation , int rowSize, int colSize, int subset){
    // 예시) relation, 6, 4, 1(= 0001)
    // subset의 값에 있는 같은 자리에 대헤서 후보키가 될 수 있는지 검사한다.
    for(int i = 0; i < rowSize - 1; i++){
        for(int j =  i + 1; j < rowSize; j++){
            bool isSame = true;
            for(int k = 0; k < colSize; k++){
                if ((subset & 1 << k) == 0) continue; // subset의 자리에 없는 colum은 지나친다.
                // 한 row에 값잍 틀린게 있으면(즉, 후보키가 될 수 있으면) isSame에 flase를 주고 해당 row에서 다음 row를 검사한다.
                // 예시로 subset = 3(0011) 일 때, 검색하는 row의 3번째자리나 4번째자리에 값중 하나만 달라도 후보키가 될 수 있다.
                if (relation[i][k] != relation[j][k]) { 
                    isSame = false;
                    break;
                }
            }
            if (isSame) return false;   // 해당 row의 값이 같으면 후보키가 될 수 없다.
        }
        
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int rowSize = relation.size();
    int colSize = relation[0].size();
    vector<int> candidates;
    
    // colSize로 표현할 수 있는 비트개수만큼 for문 진행
    for(int i = 1; i < (1 << colSize); i++){
        
        // 후보키가 될 수 있는지 여부를 탐색
        if(check(relation, rowSize, colSize, i))
            candidates.push_back(i);
    }
    
    // colum의 개수가 작은 순서대로 정렬
    sort(candidates.begin(), candidates.end(), cmp);
    
    while(!candidates.empty()){
        // sort된 후보키중 가장 작은 후보키를 답으로 제출
        int n = candidates[0];
        candidates.erase(candidates.begin());
        answer++;
        
        // 이후 해당 후보키가 포함된 후보키들은 답에서 제외
        for(int i = 0; i < candidates.size(); i++){
            if((n & candidates[i]) == n){
                candidates.erase(candidates.begin() + i);
                i = -1;
            }             
        }
    }
    return answer;
}
