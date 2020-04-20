#include <string>
#include <vector>

using namespace std;
vector<vector<int>> c;
bool visited[202][202];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void dfs(int x){
    int size = c.size();
    
    for(int i = 0; i < size; i++){
        if(c[x][i] == 1){
            c[x][i] = 0;
            c[i][i] = 0;
            dfs(i);
        }
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    c = computers;
    int size = c.size();
    for(int i = 0; i < size; i++){
        if(c[i][i] == 1){
            c[i][i] = 0;
            dfs(i);
            answer++;
        }
    }
    
    return answer;
}

/*
1 1 0
1 1 0
0 0 1
*/
