class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if(a[0] == b[0]){
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        
        int count = 0, prevEnd = 0;
        
        for(auto &i : intervals){
            int end = i[1];
            if(prevEnd < end){
                count++;
                prevEnd = end;
            }
        }
        
        return count;
    }
};