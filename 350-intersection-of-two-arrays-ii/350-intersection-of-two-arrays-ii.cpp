class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m; 
        vector<int> v;
        for(auto x : nums1) m[x]++;
        for(auto x : nums2)
        {
            if(m[x])
            {
                m[x]--;
                v.emplace_back(x);
            }
        }
        return v;
    }
};