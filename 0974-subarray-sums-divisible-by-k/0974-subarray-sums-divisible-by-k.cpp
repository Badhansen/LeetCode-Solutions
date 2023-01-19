class Solution {
private:
    unordered_map<int, int> count;
public:
    Solution(){
        count[0] = 1;
    }
    int subarraysDivByK(vector<int>& nums, int k) {
        int result = 0, prefsum = 0;
        for(auto n : nums){
            prefsum = (prefsum + n) % k;
            if(prefsum < 0) prefsum += k;
            result += count[prefsum];
            count[prefsum]++;
        }
        return result;
    }
    ~Solution(){
        count.clear();
    }
};