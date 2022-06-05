class Solution {
private:
    unordered_map<int, int> seen;
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int len = nums.size(), n = operations.size();
        for(int i = 0; i < len; i++){
            seen[nums[i]] = i;
        }
        for(int i = 0; i < n; i++){
            int a = operations[i][0], b = operations[i][1];
            nums[seen[a]] = b;
            seen[b] = seen[a];
        }
        return nums;
    }
};