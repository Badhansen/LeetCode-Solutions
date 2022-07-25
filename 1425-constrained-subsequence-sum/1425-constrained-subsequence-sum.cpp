class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> que;
        int res = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            nums[i] += !que.empty() ? que.front() : 0;
            res = max(res, nums[i]);
            while (!que.empty() && nums[i] > que.back()) {
                que.pop_back();
            }
            if (nums[i] > 0) {
                que.push_back(nums[i]);    
            }
            if (i >= k && !que.empty() && que.front() == nums[i - k]) {
                que.pop_front();
            }
        }
        return res;
    }
};