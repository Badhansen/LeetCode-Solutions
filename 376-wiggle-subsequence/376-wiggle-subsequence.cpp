class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int ncnt = 0, pcnt = 0, ans = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i + 1]) ncnt = 1 + pcnt;
            if(nums[i] < nums[i + 1]) pcnt = 1 + ncnt;
            ans = max(ncnt, pcnt);
        }
        return ans + 1;
    }
};