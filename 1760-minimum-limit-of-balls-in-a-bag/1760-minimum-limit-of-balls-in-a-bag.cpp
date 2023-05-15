class Solution {
public:
    bool IsPossible(vector<int>& nums, int value, int maxOperations) {
        int operations = 0;
        for (auto &n : nums) {
            operations += (n - 1) / value;
        }
        return operations <= maxOperations; 
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int start = 1, end = 1e9, mid, answer = 0;
        while (start <= end) {
            mid = (end - start) / 2 + start;
            if (IsPossible(nums, mid, maxOperations)) {
                answer = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return answer;
    }
};