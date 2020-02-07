#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    int skillSize = skill.size();
    
    int treeSize = skill_trees.size();
    for(int i = 0; i < treeSize; i++){
        int ind = 0;
        string cur = skill_trees[i];
        string tmp = "";
        
        int curSize = cur.size();
        for(int j = 0; j < curSize; j++){
            for(int n = 0; n < skillSize; n++){
                if(cur[j] == skill[n])
                    tmp += cur[j];
            }
        }
        
        int tmpSize = tmp.size();
        bool find = true;
        for(int j = 0 ; j < tmpSize; j++){
            if(skill[j] != tmp[j]){
                find = false;
                break;
            }
        }
        
        if(find) answer++;
    }
    
    return answer;
}
