class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int sum = 0;
        for (auto n : nums) {
            if (!(n & 1)) {
                sum += n;
            }
        }
        for (auto q : queries) {
            if (!(nums[q[1]] & 1)) {
                sum -= nums[q[1]];
                
            }
            nums[q[1]] += q[0];
            if (!(nums[q[1]] & 1)) {
                sum += nums[q[1]];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};