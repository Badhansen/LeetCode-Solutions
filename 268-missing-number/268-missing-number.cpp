class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int mask = 0;
        for(int i = 0; i < nums.size(); i++){
            mask ^= nums[i];
            mask ^= (i + 1);
        }
        return mask;
    }
};

//Here N = Here N is the number of elements
// Time Complexity: O(N);
// Space Compexity: O(1)