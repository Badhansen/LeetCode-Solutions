class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        sort(expected.begin(), expected.end());
        int count = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (expected[i] != heights[i]) {
                count++;
            }
        }
        return count;
    }
};