const int MOD = 1e9 + 7;

class Solution {
private:
    vector<vector<int>> dp;
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        /*
        // dp[s][f] is the number of ways to get FROM START to city s with available fuel f 
        // Note: f means exactly f, not less than f, so the number of ways to get to s with cost f - 1 is not included

        //basecase
            dp[start][0]=1 // with cost = 0, i'm already at the start, so there s only 1 way
        */
        int n = locations.size();
        dp.resize(n + 1, vector<int>(fuel + 1, 0));
        dp[start][0] = 1;
        
        for(int f = 0; f <= fuel; f++){
            for(int s = 0; s < n; s++){
                for(int e = 0; e < n; e++){
                    if(s == e) continue;
                    int diff = abs(locations[e] - locations[s]);
                    if(f >= diff) dp[s][f] = (dp[s][f] + dp[e][f - diff]) % MOD;
                }
            }
        }
        int ans = 0;
        for(int f = 0; f <= fuel; f++){
            ans = (ans + dp[finish][f]) % MOD;
        }
        return ans;
    }
};

// Time: O(N^2 * F)
// Space: O(NF)

/*
// Start from the start index, and visit all cities except start.
// Continue this process recursively.
// If you reach end index, do:
// Now, we have atleast 1 way of reaching end so add this 1 possible way to the answer.
// Continue recursion, since there might be more ways to get back from end to end using other cities.
// If fuel < 0, there is no further way left.
// If you look at this recursion, we can see that there are overlapping subproblems. If you reach a city c with fuel f multiple times from different paths, don't recompute, just use memoised result.

#define MAX_N 101
#define MAX_F 201

const int MOD = 1e9 + 7;

class Solution {
private:
    int dp[MAX_N][MAX_F];
    int finish;
public:
    int ways(int pos, int fuel, vector<int>& locations){
        if(pos >= locations.size() || fuel < 0){
            return 0;
        }
        int &ret = dp[pos][fuel];
        if(ret != -1) return ret;        
        ret = pos == finish ? 1 : 0;
        for(int i = 0; i < locations.size(); i++){
            if(i != pos) ret = (ret + ways(i, fuel - abs(locations[i] - locations[pos]), locations)) % MOD;
        }
        return ret;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp, -1, sizeof dp);
        this->finish = finish;
        int ans = ways(start, fuel, locations);
        return ans;
    }
};

// Time: O(N^2 * F)
// Space: O(NF)
*/