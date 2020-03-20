#include <string>
#include <vector>
#include <iostream>

using namespace std;

void printCache(vector<string> cache){
    for(int i = 0; i < cache.size(); i++){
        cout << cache[i] << " ";
    }
    cout << endl;
}
string bigToSmallAlpha(string str){
    int t = 'a' - 'A';
    for(int i = 0; i < str.size(); i++){
        if('A' <= str[i] && str[i] <= 'Z'){
            str[i] = (char)(str[i] + t);
        }
    }
    
    return str;
}
bool findCache(vector<string> cache, string city){
    if(cache.size() == 0) return false;

    for(int i = 0; i < cache.size(); i++){
        if(cache[i] == city){ 
            return true;
        }
        
    }
    return false;
}
vector<string> resortCache(vector<string> cache, string city){
    if(cache.size() == 0) return cache;
    
    for(int i = 0; i < cache.size(); i++){
        if(cache[i] != city) continue;
        for(int j = i; j < cache.size() - 1; j++){
            cache[j] = cache[j+1];
        }
        cache[cache.size() - 1] = city;
    }
    
    return cache;
}
vector<string> pushCache(vector<string> cache, string city){  
    if(cache.size() == 0) return cache;
    if(cache.size() == 1){
        cache[0] = city;
        return cache;
    }

    for(int i = 0; i < cache.size() - 1; i++){
        cache[i] = cache[i + 1];
    }
    cache[cache.size() - 1] = city;
    
    return cache;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache(cacheSize, "tmp");
    
    int citiesSize = cities.size();
    for(int i = 0; i < citiesSize; i++){
        cities[i] = bigToSmallAlpha(cities[i]);
        if(findCache(cache, cities[i])){
            answer++;
            cache = resortCache(cache, cities[i]);
        }
        else{
            answer += 5;
            cache = pushCache(cache, cities[i]);
        }
        
    }
    return answer;
}
