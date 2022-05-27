// @Author: KING-SEN
// 1 last try

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> papers(n + 1, 0);
        for(auto &c : citations){
            papers[min(n, c)]++;
        }
        int ans = n;
        for(int sum = papers[n]; ans > sum; sum += papers[ans]){
            ans--;
        }
        return ans;
    }
};

// Time: O(N), N = number of elements
// Space: O(1)