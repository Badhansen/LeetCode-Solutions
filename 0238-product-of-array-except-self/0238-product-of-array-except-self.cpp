class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        int prefix = 1, postfix = 1;
        for(int i = 0; i < n; i++){
            result[i] = prefix;
            prefix *= nums[i];
        }
        for(int i = n - 1; i >= 0; i--){
            result[i] *= postfix;
            postfix *= nums[i];
        }
        return result;
    }
};

// [1, 2, 3, 4]
// [1, 1, 2, 6]
// [24, 12, 8,  6]

// Time: O(N)
// Spce: O(1)
/*
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n + 1), right(n + 1), ans(n);
        left[0] = 1;
        for(int i = 0; i < n; i++){
            left[i + 1] = left[i] * nums[i];
        }
        right[n - 1] = 1;
        for(int i = n - 1; i > 0; i--){
            right[i - 1] = right[i] * nums[i];
        }
        for(int i = 0; i < n; i++){
            ans[i] = left[i] * right[i];
        }
        return ans;
    }
};
*/