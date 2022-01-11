
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);

// @Author: KING-SEN
// Programming Language Used: C++


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length = nums.size();
        int position = nums[0];
        for(int i = 1; i < length; i++){
            if(position < i) return false;
            position = max(position, nums[i] + i);
        }
        return position >= length - 1;
    }
};


// Time Complexity: O(N), where N is the array size
// Space Complexity: O(1) we are using constant space