// @Author: KING-SEN

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int  n = nums.size();
        multiset<int> left;
        multiset<int> right;
        // left = max heap
        // right = min heap
        vector<double> medians;
        for (int i = 0; i < n; i++) {
            // remove window first element
            if (i >= k) {
                if (nums[i - k] <= *left.rbegin()) {
                    left.erase(left.find(nums[i - k]));
                } else {
                    right.erase(right.find(nums[i - k]));
                }
            }
            left.insert(nums[i]);
            right.insert(*left.rbegin());
            left.erase(prev(left.end()));
            
            if (left.size() < right.size()) {
                left.insert(*right.begin());
                right.erase(right.begin());
            }
            if (i >= k - 1) {
                double result = (k & 1) ? *left.rbegin() : ((double)(*left.rbegin()) + (double)(*right.begin())) / 2.00;
                medians.push_back(result);
            }
        }
        return medians;
    }
};

/*
    Time complexity: O((n−k)⋅6⋅log⁡k)≈O(nlogk).
        At worst, there are three set insertions and three set deletions from the start or end. Each of these takes about O(log⁡k) time.
        Finding the mean takes constant O(1) time since the start or ends of sets are directly accessible.
        Each of these steps takes place about (n−k) times (the number of sliding window instances).

    Space complexity: O(k) extra linear space to hold contents of the window.
*/