#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> vec;
bool visited[102][102];
int M, N;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int area;

void dfs(int x, int y, int color){
    visited[x][y] = true;
    area++;

    for(int i = 0; i < 4; i++){
        int mx = x + dx[i];
        int ny = y + dy[i];

        if(0 > mx || mx > M-1 || 0 > ny || ny > N-1) continue;

        if(!visited[mx][ny] && vec[mx][ny] == color){
            dfs(mx,ny,color);
        }
    }

}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

  // 전역변수 초기화  
        area = 0;
    M = m;
    N = n;
    vec = picture;

  // visited 2차원 배열을 초기화 안해서 계속 틀렸었다..아마 해당 문제에서는 전역변수 설정시 자동으로 false 설정이 안되나보다.
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = false;
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j] && vec[i][j] > 0){
                area = 0;
                dfs(i, j, vec[i][j]);
                number_of_area++;
                max_size_of_one_area = max(area, max_size_of_one_area);
            }
        }
    }


    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
