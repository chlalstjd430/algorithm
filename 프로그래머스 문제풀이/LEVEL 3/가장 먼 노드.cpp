#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int graph[20002][20002];
int maxNode = -1;
int dist[20002];
int visited[20002];

bool cmp(int a, int b){
    return a > b;
}

void bfs(int n){
    queue<int> q;
    q.push(1);
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        for(int i = 2; i <= n; i++){
            if(graph[front][i] == 1 && dist[i] == 0){
                dist[i] = dist[front] + 1;
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(int i = 0; i < edge.size(); i++){
        graph[edge[i][0]][edge[i][1]] = graph[edge[i][1]][edge[i][0]] = 1;
    }
    bfs(n);
    sort(dist, dist + n +1, cmp);
    
    for(int i = 0; i <= n; i++){
        if(dist[0] == dist[i])
            answer++;
    }
    
    return answer;
}r
