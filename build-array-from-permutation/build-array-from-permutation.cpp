class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int length = nums.size();
        vector<int> answer(length);
        
        for(int i = 0; i < length; i++){
            answer[i] = nums[nums[i]];
        }
         
        return answer;
    }
};