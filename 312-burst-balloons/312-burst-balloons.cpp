class Solution {
private:
    vector<vector<int>> memo;
public:
    int solve(int left, int right, vector<int>& nums){
        if(right - left < 0){
            return 0;
        }
        int &ret = memo[left][right];
        if(ret != -1){
            return ret;
        }
        ret = 0;
        for(int i = left; i <= right; i++){
            int gain = nums[left - 1] * nums[i] * nums[right + 1];
            int remain = solve(left, i - 1, nums) + solve(i + 1, right, nums);
            ret = max(ret, gain + remain);
        }
        return ret;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int len = nums.size();
        memo.resize(len + 1, vector<int>(len + 1, -1));
        return solve(1, len - 2, nums);
    }
};