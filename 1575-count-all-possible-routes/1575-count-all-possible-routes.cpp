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