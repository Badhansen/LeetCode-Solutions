class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        for(auto &n : nums){
            seen[n]++;
        }
        int count = 0;
        for(auto &[key, val] : seen){
            if(k == 0){
                if(val > 1) count++;
            }
            else{
                if(seen.count(key + k)){
                    count++;
                }
            }
        }
        return count;
    }
};