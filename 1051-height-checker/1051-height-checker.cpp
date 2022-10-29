const int kMax = 105;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // vector<int> expected = heights;
        // sort(expected.begin(), expected.end());
        // int count = 0;
        // for (int i = 0; i < heights.size(); i++) {
        //     if (expected[i] != heights[i]) {
        //         count++;
        //     }
        // }
        // return count;
        
        int mismatch = 0; 
        vector<int> count(kMax, 0);
        for (int i = 0; i < heights.size(); i++) {
            count[heights[i]]++;
        }

        int i = 1, j = 0; 
        while(i < 101) {
            if (count[i] == 0) {
                i++;
            }
            else {
                if (i != heights[j]) {
                    mismatch++;
                }
                j++; count[i]--;
            }
        }
        return mismatch;
    }
};