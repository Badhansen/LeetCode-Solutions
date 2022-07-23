// @Author: KING-SEN
// 1 last try

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0, count = 0, answer = 0, change;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right]) count++;
            change = right - left + 1 - count;
            if (change <= 1) {
                answer = max(answer, right - left + 1);
            } else {
                if (nums[left] == 1) count--;
                left++;
            }
        }
        return answer;
    }
};

// Time: O(N), N = numbers of elements
// Space: O(1)