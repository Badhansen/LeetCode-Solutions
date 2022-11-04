class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count1, count2;
        for (auto n : nums1) {
            count1[n]++;
        }
        for (auto n : nums2) {
            count2[n]++;
        }
        vector<int> answer1, answer2;
        for (auto n : nums1) {
            if (!count2.count(n)) {
                answer1.push_back(n);
            }
        }
        for (auto n : nums2) {
            if (!count1.count(n)) {
                answer2.push_back(n);
            }
        }
        sort(answer1.begin(), answer1.end());
        sort(answer2.begin(), answer2.end());
        auto it1 = unique(answer1.begin(), answer1.end());
        answer1.resize(distance(answer1.begin(), it1));
        auto it2 = unique(answer2.begin(), answer2.end());
        answer2.resize(distance(answer2.begin(), it2));
        return {answer1, answer2};
    }
};