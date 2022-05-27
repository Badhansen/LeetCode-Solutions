// @Author: KING-SEN
// 1 last try

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int st = 0, ed = n - 1, ans = 0;
        while(st <= ed){
            int mid = (st + ed) / 2;
            if(citations[mid] >= n - mid){
                ans = n - mid;
                ed = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return ans;
    }
};

// Time: O(N log N + log N) ~ O(N log N), N = number of elements
// Space: O(1)