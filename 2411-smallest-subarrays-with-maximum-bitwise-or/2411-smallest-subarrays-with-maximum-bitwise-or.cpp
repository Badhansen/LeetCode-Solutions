#define bitscount 32

class Solution {
private:
    vector<vector<int>> bits; 
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        bits.resize(bitscount);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < bitscount; j++) {
                if ((nums[i] >> j) & 1) {
                    bits[j].push_back(i);
                }
            }
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int dist = 1;
            for (int j = 0; j < bitscount; j++) {
                auto it = lower_bound(bits[j].begin(), bits[j].end(), i);
                if (it == bits[j].end()) {
                    continue;
                }
                dist = max(*it - i + 1, dist);                
            }
            ans[i] = dist;
        }
        return ans;
    }
};