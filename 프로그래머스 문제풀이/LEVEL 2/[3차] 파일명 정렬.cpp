#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string upperCase(string str){
    for(int i = 0; i < str.size(); i++){
        if('a' <= str[i] && str[i] <= 'z'){
            str[i] = (str[i] + ('A'-'a'));
        }
    }
    
    return str;
}

bool cmp(vector<string> v1, vector<string> v2){
    string str1 = upperCase(v1[0]);
    string str2 = upperCase(v2[0]);
    
    if(str1 == (str2))
        return stoi(v1[1]) < stoi(v2[1]);
    
    return str1 < str2;
}

vector<string> splitFileName(string fileName){
    vector<string> result(3, "");
    int ind = 0;
    // HEAD
    for(int i = 0; i < fileName.size(); i++){
        if(('0' <= fileName[i] && fileName[i] <= '9')){
            ind = i;        
            break;
        }
        result[0] += fileName[i];
    }

    // NUMBER
    for(int i = ind; i < fileName.size(); i++){    
        if(('0' > fileName[i] || fileName[i] > '9') ){
            i = ind;
            break;
        }
        result[1] += fileName[i];
        ind++;
    }
    //TAIL
    for(int i = ind; i < fileName.size(); i++){    
        result[2] += fileName[i];
    }
    //cout << result[2] << endl;
    
    return result;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    vector<vector<string> > splitFiles;
    for(int i = 0; i < files.size(); i++){
        splitFiles.push_back(splitFileName(files[i]));
    }
    
    stable_sort(splitFiles.begin(), splitFiles.end(), cmp);
    for(int i = 0; i < splitFiles.size(); i++){
       // cout << "HEAD : " <<splitFiles[i][0] << "   NUMBER : " << splitFiles[i][1]<< "   TAIL : " <<splitFiles[i][2] << endl;
        answer.push_back(splitFiles[i][0] + splitFiles[i][1] + splitFiles[i][2]);
    }
    return answer;
}
