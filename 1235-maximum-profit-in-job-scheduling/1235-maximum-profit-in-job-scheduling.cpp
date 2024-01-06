//@Author: KING-SEN
// Programming Language Used: C++

class Solution {
private:
    vector<int> dp;
public:
    int solve(int pos, vector<vector<int>>& jobs, vector<int>& startTime){
        if(pos >= startTime.size()) {
            return 0;
        }
        if(dp[pos] != -1) {
            return dp[pos];
        }
        int notTaken = solve(pos + 1, jobs, startTime);
        int newPos = lower_bound(startTime.begin(), startTime.end(), jobs[pos][1]) - startTime.begin();
        int taken = jobs[pos][2] + solve(newPos, jobs, startTime);
        return dp[pos] = max(notTaken, taken);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        dp.clear();
        dp.resize(startTime.size() + 1, -1);
        for(int i = 0; i < startTime.size(); i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        sort(startTime.begin(), startTime.end());
        
        return solve(0, jobs, startTime);
    }
};

/*
    Time Complexity: O(N log N) for sorting the job list
    Time Complexity: O(N log N) for binary search for each job
    
    So over all 
    
    Time Complexity: O(N Log N)
    Space Complexity: O(N) for storing the the answer
*/