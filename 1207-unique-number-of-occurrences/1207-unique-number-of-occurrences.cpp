class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> mp, cnt;
        for(auto x : arr)
        {
            mp[x]++;
        }
        for(auto x : mp)
        {
            cnt[x.second]++;
        }
        for(auto x : cnt)
        {
            if(x.second > 1) return 0;
        }
        return 1;
    }
};