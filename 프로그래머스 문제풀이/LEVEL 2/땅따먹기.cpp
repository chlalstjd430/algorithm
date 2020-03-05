#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > dp;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    dp = land;
    
    int landSize = land.size();
    for(int i = 1; i < landSize; i++){
        for(int j = 0; j < 4; j++){
            int num = 0;
            for(int k = 0; k < 4; k++){
                if(j == k) continue;
                num = max(num, land[i-1][k]);
            }
            land[i][j] += num;
        }
    }
    
    for(int i = 0; i < 4; i++){
        answer = max(land[landSize-1][i], answer);
    }

    return answer;
}
