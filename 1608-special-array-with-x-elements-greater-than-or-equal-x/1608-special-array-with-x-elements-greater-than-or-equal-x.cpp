class Solution {
public:
    int specialArray(vector<int>& nums) {
        int start = 0, end = 1000, answer;
        while (start <= end) {
            int mid = (start + end) / 2;
            int count = 0;
            for (auto n : nums) {
                if (n >= mid) {
                    count++;
                }
            }
            if (count == mid) {
                return mid;
            } else if (count < mid) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }
};