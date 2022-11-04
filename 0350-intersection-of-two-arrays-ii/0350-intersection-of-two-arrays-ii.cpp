class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count; 
        vector<int> answer;
        for(auto n : nums1) {
            count[n]++;
        }
        for(auto n : nums2)
        {
            if(count[n])
            {
                count[n]--;
                answer.emplace_back(n);
            }
        }
        return answer;
    }
};