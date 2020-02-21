#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    int phone_book_size = phone_book.size();
    for(int i = 0; i < phone_book_size; i++){
        string phone = phone_book[i];
        int phone_size = phone.size();
        
        for(int j = 0; j < phone_book_size; j++){
            if(i == j) continue;
            if(phone_size > phone_book[j].size()) continue;
            string search = phone_book[j].substr(0,phone_size);
            if(phone == search){
                    return false;
                }
        }
    }
    
    
    return answer;
}
