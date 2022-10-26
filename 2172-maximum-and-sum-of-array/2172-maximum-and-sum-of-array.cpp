// @Author: KING-SEN

const int kMax = 10;

class Solution {
private:
    int slot;
    map<vector<int>, int> cache;
public:
    int solve(int pos, vector<int>& count, vector<int>& nums) {
        if (pos >= nums.size()) {
            return 0;
        }
        if (cache.count(count)) {
            return cache[count];
        }
        int result = 0, max_result = 0;
        for (int i = 0; i < slot; i++) {
            if (count[i] < 2) {
                count[i]++;
                result = ((i + 1) & nums[pos]) + solve(pos + 1, count, nums);
                max_result = max(max_result, result);
                count[i]--;
            }
        }
        return cache[count] = max_result;
    }
    int maximumANDSum(vector<int>& nums, int numSlots) {
        vector<int> count(kMax, 0);
        slot = numSlots;
        int result = solve(0, count, nums);
        return result;
    }
};

/*
Time Complexity: 
Here dp state is (index in nums, array of slots). possible values of index[0,n) and no of possible values of the array of slots are 3^numSlots(since the possible value of an element in slot is 0,1,2). so the total number of states would be N*(3^numSlots).
And for each state, we are also iterating over numSlots.
Overall complexity would be N*(3^numSlots)*numSlots
*/