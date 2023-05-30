class Solution {
private:
    vector<int> a, b;
    int n;
public:
    Solution(vector<int>& nums) {
        n = nums.size();
        a = nums;
        b = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        a = b;
        return a;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i = n - 1; i > 0; i--){
            int j = rand() % (i + 1);
            swap(a[i], a[j]);
        }
        return a;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */