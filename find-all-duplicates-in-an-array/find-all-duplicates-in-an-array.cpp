class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int len = nums.size();
        vector<int> answer;
        for(int i = 0; i < len; i++){
            int id = abs(nums[i]) - 1;
            if(nums[id] < 0) 
                answer.push_back(id + 1);
            nums[id] *= -1;
        }
        return answer;
    }
};