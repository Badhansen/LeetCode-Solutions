const int Mod = 1e9 + 7;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int answer = 0, n = nums.size();
        vector<int> powers(n, 1);
        for (int i = 1; i < n; i++) {
            powers[i] = (powers[i - 1] * 2) % Mod;
        }
        int left = 0, right = n - 1;
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                answer = (answer + powers[right - left]) % Mod;
                left++;
            } else {
                right--;
            }
        }
        return answer;
    }
};