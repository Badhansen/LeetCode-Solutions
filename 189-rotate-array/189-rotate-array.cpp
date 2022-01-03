// Programming Language Used: C++

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length = nums.size();
        k %= length;
        
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

// Time Complexity: O(3 * N) ~ O(N), Here N = Length of the array.
// Space Complexity: O(1), Here we used only constant space.