#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Iland{
public :
    int node[2];
    int cost;
    
    Iland(int x, int y, int cost){
        node[0] = x;
        node[1] = y;
        this->cost = cost;
    }
    
    bool operator <(Iland &iland){
        return this->cost < iland.cost;
    }
};


int getParent(int parent[], int num){
    if(parent[num] == num) return num;
    return parent[num] = getParent(parent, parent[num]);
}

void unionParent(int parent[], int x, int y){
    x = getParent(parent, x);
    y = getParent(parent, y);
    if(x > y){
        parent[x] = y;
    }
    else parent[y] = x;
}

bool findParent(int parent[], int x, int y){
    x = getParent(parent, x);
    y = getParent(parent, y);
    if(x == y) return true;
    return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<Iland> ilands;
    int parent[10002] = {0, };
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }
    
    for(int i = 0; i < costs.size(); i++){
        ilands.push_back(Iland(costs[i][0], costs[i][1], costs[i][2]));
    }
    
    sort(ilands.begin(), ilands.end());
    for(int i = 0; i < ilands.size(); i++){
        if(!findParent(parent, ilands[i].node[0], ilands[i].node[1])){
            unionParent(parent, ilands[i].node[0], ilands[i].node[1]);
            answer += ilands[i].cost;
        }
    }
    
    return answer;
}
