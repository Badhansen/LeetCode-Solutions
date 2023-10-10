class Solution {
public:
    int minOperations(vector<int>& nums) {
        int length = nums.size();
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int answer = length;
        int right = 0;
        for (int left = 0; left < nums.size(); left++) {
            // Searching for nums[left] to nums[left] + length - 1
            while (right < nums.size() && nums[right] < (nums[left] + length)) {
                right++;
            }
            int window = right - left;
            answer = min(answer, length - window);
        }
        return answer;
    }
};