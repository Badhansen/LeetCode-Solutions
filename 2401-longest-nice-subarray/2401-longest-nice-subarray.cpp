class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int used = 0, left = 0, answer = 1;
        for (int right = 0; right < nums.size(); right++) {
            while ((used & nums[right]) != 0) {
                used ^= nums[left++];
            }
            used |= nums[right];
            answer = max(answer, right - left + 1);
        }
        return answer;
    }
};