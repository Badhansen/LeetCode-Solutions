class Solution {
public:
    vector<int> input,result;
    Solution(vector<int>& nums) {
        input = nums;
        result = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        result = input;
        return result;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int sz = result.size();
        for(int i=0;i<result.size();i++){
            int pos = rand() % sz;
            swap(result[i],result[pos]);
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */