// @Author: KING-SEN
// 1 last try

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int nums1Len = nums1.size(), nums2Len = nums2.size();
        vector<int> stack, ans(nums1Len);
        unordered_map<int, int> seen;
        for(int i = 0; i < nums2Len;  i++){
            while(!stack.empty() && nums2[i] > stack.back()){
                seen[stack.back()] = nums2[i];
                stack.pop_back();
            }
            stack.push_back(nums2[i]);
        }
        while(!stack.empty()){
            seen[stack.back()] = -1;
            stack.pop_back();
        }
        for(int i = 0; i < nums1Len; i++){
            ans[i] = seen[nums1[i]];
        }
        return ans;
    }
};

// Time: O(N), N = Length of nums2 array
// Space: O(N), as Map will store n key-value pairs and stack will contains at most N elements