// Programming Language Used: C++

static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i < n; i++){
            nums[i] = nums[i] + nums[i - 1];
        }
        return nums;
    }
};

// Time Complexity: O(N), here N = length of the array
// Space Complexity: O(N)