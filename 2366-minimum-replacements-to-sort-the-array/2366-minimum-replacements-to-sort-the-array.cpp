class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long answer = 0, prev = nums[n - 1], k;
        for (int i = n - 2; i >= 0; i--) {
            if (prev < nums[i]){
                k = ((nums[i] - 1) / prev) + 1;
                answer += k - 1;
                prev = 1ll * nums[i] / k;
                
            } else {
                prev = nums[i];
            }
        }
        return answer;
    }
};