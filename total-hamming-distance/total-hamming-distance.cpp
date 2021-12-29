class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0, count;
        int len = nums.size();
        for(int i = 0; i < 32; i++){
            count = 0;
            for(auto n : nums){
                if(n & (1 << i))
                    count++;
            }
            ans += (len - count) * count;
        }
        return ans;
    }
};