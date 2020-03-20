#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> friendsBoard;
int nx[] = {0, 0, 1, 1};
int ny[] = {0, 1, 0, 1};
int answer = 0;

void pushBoard(){
    int w = friendsBoard[0].size();
    int h = friendsBoard.size();

    for(int i = h - 1; i >= 0; i--){
        for(int j = w - 1; j >= 0; j--){
            if(friendsBoard[i][j] != 'x') continue;
            int ind =  -1;
            for(int k = i; k >= 0; k--){
                if(friendsBoard[k][j] != 'x') {
                    ind = k;
                    break;
                }
            }
            if(ind == -1) continue;
            int cur = i;
            for(int k = ind; k >= 0; k--){
                if(cur < 0) break;
                friendsBoard[cur][j] = friendsBoard[k][j];
                friendsBoard[k][j] = 'x';
                cur--;
            }
      
        }
    }
}

bool findFriends(){  
    vector<pair<int, int> > boardLocation;
    int w = friendsBoard[0].size();
    int h = friendsBoard.size();
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            bool find[4] = {false, };
            char v = friendsBoard[i][j];
            if(v == 'x') continue;
            for(int k = 0; k < 4; k++){
                int x = i + nx[k];
                int y = j + ny[k];
                if(0 > x || 0 > y || x >= h || y >= w ) break;
                if(v == friendsBoard[x][y]){
                    find[k] = true;
                    continue;
                }
                break;
            }
            if(find[0] && find[1] && find[2] && find[3]){
                for(int k = 0; k < 4; k++){
                    boardLocation.push_back(make_pair(i + nx[k], j + ny[k]));
                }
                find[0] = find[1] = find[2] = find[3] = false;
            }
        }
    }
    
    for(int i = 0; i < boardLocation.size(); i++){
        int x = boardLocation[i].first;
        int y = boardLocation[i].second;
        friendsBoard[x][y] = 'x';
    }
    if(boardLocation.size() == 0){
        return false;
    }
    return true;
}

void findAnswer(){
    int w = friendsBoard[0].size();
    int h = friendsBoard.size();
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(friendsBoard[i][j] == 'x') answer++;
        }
    }
}

int solution(int m, int n, vector<string> board) {
    friendsBoard = board;
    bool find = true;
    findFriends();
    while(find){     
        pushBoard();  
        find = findFriends();           
    }
    findAnswer();
    return answer;
}
