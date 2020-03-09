#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int arr1_w = arr1[0].size();
    int arr1_h = arr1.size();
    int arr2_w = arr2[0].size();
    int arr2_h = arr2.size();
    
    for(int i = 0; i < arr1_h; i++){
        vector<int> v;
        for(int j = 0; j < arr2_w; j++){
            int tmp = 0;
            for(int k = 0; k < arr1_w; k++){
                tmp += arr1[i][k]*arr2[k][j];
            }
            v.push_back(tmp);
        }
        answer.push_back(v);
    }
    return answer;
}
