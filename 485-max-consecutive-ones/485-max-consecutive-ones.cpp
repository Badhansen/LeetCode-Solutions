// @Author: KING-SEN
// 1 last try

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, answer = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]) count++;
            else{
                count = 0;
            }
            answer = max(answer, count);
        }
        return answer;
    }
};

// Time: O(N), N = numbers of elements
// Space: O(1)