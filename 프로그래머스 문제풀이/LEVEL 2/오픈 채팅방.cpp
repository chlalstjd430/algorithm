#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<vector<string> > splitString(vector<string> v){
    vector<vector<string> > result;
    for(int i = 0; i < v.size(); i++){
        int size = v[i].size();
        int ind = 0;
        vector<string> tmp;
        for(int j = 0; j < size; j++){
            if(v[i][j] == ' '){
                string str = v[i].substr(ind, j - ind);
                tmp.push_back(str);
                ind = j+1;
            }
        }
        
        string str = v[i].substr(ind, size - 1);
        tmp.push_back(str);
        result.push_back(tmp);
    }
    
    return result;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string> > split_record = splitString(record);
    // for(int i = 0; i < split_record.size(); i++ ){
    //     for(int j = 0; j < split_record[i].size(); j++){
    //         cout << split_record[i][j] << "_";
    //     }
    //     cout << endl;
    // }
    
    map<string, string> nickname;
    for(int i = 0; i < split_record.size(); i++ ){
         if(split_record[i][0].compare("Enter") == 0){
             nickname[split_record[i][1]] = split_record[i][2];
         }
         else if(split_record[i][0].compare("Change") == 0){
              nickname[split_record[i][1]] = split_record[i][2];
         }
    }
    
     for(int i = 0; i < split_record.size(); i++ ){
         string str = "";
         if(split_record[i][0].compare("Enter") == 0){
             str = nickname[split_record[i][1]] +"님이 들어왔습니다.";
             answer.push_back(str);
         }
         if(split_record[i][0].compare("Leave") == 0){
              str = nickname[split_record[i][1]] +"님이 나갔습니다.";
             answer.push_back(str);
         }
         
    }

    return answer;
}
