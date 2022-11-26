//@Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    int solve(int pos, int length, unordered_map<int, int>& dp, vector<vector<int>>& jobs, vector<int>& startTime){
        if(pos >= length) 
            return 0;
        
        if(dp.find(pos) != dp.end()) 
            return dp[pos];
        int newPos = lower_bound(startTime.begin(), startTime.end(), jobs[pos][1]) - startTime.begin();
        return dp[pos] = max(solve(pos + 1, length, dp, jobs, startTime), 
                             jobs[pos][2] + solve(newPos, length, dp, jobs, startTime));
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        
        for(int i = 0; i < startTime.size(); i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        sort(startTime.begin(), startTime.end());
        
        unordered_map<int, int> dp;
        
        return solve(0, jobs.size(), dp, jobs, startTime);
    }
};

/*
    Time Complexity: O(N log N) for sorting the job list
    Time Complexity: O(N log N) for binary search for each job
    
    So over all 
    
    Time Complexity: O(N Log N)
    Space Complexity: O(N) for storing the the answer
*/