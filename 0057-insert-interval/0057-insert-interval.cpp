// @Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        
        for(auto &in : intervals){
            if(newInterval[1] < in[0]){
                result.push_back(newInterval);
                newInterval = in;
            }
            else if(in[1] < newInterval[0]){
                result.push_back(in);
            }
            else{
                newInterval[0] = min(newInterval[0], in[0]);
                newInterval[1] = max(newInterval[1], in[1]);
            }
        }
        
        result.push_back(newInterval);
        
        return result;
    }
};

// Time Complexity: O(N), since it's one pass along the input array
// Space Complexity: O(N), to keep the output