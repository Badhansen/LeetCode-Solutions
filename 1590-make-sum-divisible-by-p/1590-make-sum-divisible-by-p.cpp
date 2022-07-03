class Solution {
private:
    unordered_map<int, int> last;
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size(), res = n, need = 0, curr = 0;
        last[0] = -1;
        for(auto n : nums) need = (need + n) % p;
        for(int i = 0; i < n; i++){
            curr = (curr + nums[i]) % p;
            last[curr] = i;
            int want = (curr - need + p) % p;
            if(last.count(want)) res = min(res, i - last[want]);
        }
        return res < n ? res : -1;
    }
    ~Solution(){
        last.clear();
    }
};