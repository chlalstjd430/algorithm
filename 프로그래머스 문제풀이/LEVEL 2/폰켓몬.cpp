#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int,int> m;

int solution(vector<int> nums)
{
	int answer = 0;
    
    int numsSize = nums.size();
    for(int i = 0; i < numsSize; i++){
        m[nums[i]]++;
    }
    answer = min((int)m.size(), numsSize/2);
	return answer;
}
