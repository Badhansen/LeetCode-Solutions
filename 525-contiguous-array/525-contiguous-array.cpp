class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>lastIndex;
        lastIndex[0] = -1;
        int cumulativeSum = 0;
        int maxLen = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cumulativeSum += (nums[i] == 0 ? -1 : 1);
            if (lastIndex.find(cumulativeSum) != lastIndex.end()) {
                maxLen = max(maxLen, i - lastIndex[cumulativeSum]);
            } else {
                lastIndex[cumulativeSum] = i;
            }
        }
        return maxLen;
    }
};