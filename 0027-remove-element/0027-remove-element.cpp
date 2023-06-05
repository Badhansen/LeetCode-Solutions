class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right  = 0, count = 0, len = nums.size();
        while (right < len) {
            if (nums[right] != val) {
                nums[left++] = nums[right]; 
            } else {
                count++;
            }
            right++;
        }
        return len - count;
    }
};