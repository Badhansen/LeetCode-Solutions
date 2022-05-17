class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int len = nums.size(), ans = 0;
        vector<int> odd;
        for(int i = 0; i < len; i++){
            nums[i] = !(nums[i] & 1);
            if(!nums[i]){
                odd.push_back(i);
            }
        }
        for(int i = k - 1; i < odd.size(); i++){
            int fr = odd[i - k + 1], fprev = i - k + 1 > 0 ? odd[i - k] : -1;
            int bk = odd[i], bnext = i + 1 == odd.size() ? len  : odd[i + 1];        
            int ans1 = fr - fprev;
            int ans2 = bnext - bk;
            ans += ans1 * ans2;
        }
        return ans;
    }
};