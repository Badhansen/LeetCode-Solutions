class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < nums.size(); i++){
            int id = abs(nums[i]) - 1;
            nums[id] *= -1;
            if(nums[id] > 0) nums[id] *= -1;
        }
        vector<int> answer;
        for(int i = 0; i < len; i++){
            if(nums[i] > 0) 
                answer.push_back(i + 1);
        }
        return answer;
    }
};