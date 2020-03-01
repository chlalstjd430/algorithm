#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[1002][1002];

void dfs(int x, int y){
    
}

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int h = board.size();
    int w = board[0].size();
    
    // 검사를 1,1부터 시작하기 때문에, 맨윗줄과 왼쪽줄에 1값이 있는지 검사한다.
    for(int i = 0; i < h; i++){
        if(board[i][0] == 1) {
            answer = 1;
            break;
        }
    }
    for(int i = 0; i < w; i++){
        if(board[0][i] == 1) {
            answer = 1;
            break;
        }
    }
    
    // DP를 이용하여 최대 넓이를 구한다.
    for(int i = 1; i < h; i++){
        for(int j = 1; j < w; j++){
            if(board[i][j] == 0) continue;  // 진행하는 값이 0이라면 패스한다.
            board[i][j] = min(board[i-1][j-1], min(board[i-1][j],board[i][j-1])) + 1;   // DP
            answer = max(board[i][j]*board[i][j], answer);  // answer에 최대 넓이 값을 비교한다.
        }
    }

    return answer;
}
