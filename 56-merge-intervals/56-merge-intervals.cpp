//@Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> merged;
        
        for(auto interval : intervals){
            if(merged.empty() || merged.back()[1] < interval[0]){
                merged.push_back(interval);
            }
            else{
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        
        return merged;
    }
};

// Time Complexity: O(N log N), where N is the length of the array
// Space Complexity: O(N), we have to store the result for answer, so if every interval is unique then for the worst part it will be O(N)