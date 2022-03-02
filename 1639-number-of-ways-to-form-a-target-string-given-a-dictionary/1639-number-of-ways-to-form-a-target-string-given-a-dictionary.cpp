class Solution {
private:
    const int MOD = 1e9 + 7;
    
    vector<vector<int>> dp, freq;
    int totalW, wLen, tLen;
    string target;
public:
    int solve(int w, int t){
        if(t >= tLen){
            return 1;
        }
        if(w >= wLen){
            return 0;
        }
        int &ret = dp[w][t];
        if(ret > -1){
            return ret;
        }
        int curr = target[t] - 'a';
        return ret = (solve(w + 1, t) % MOD + (1ll * freq[w][curr] * solve(w + 1, t + 1)) % MOD) % MOD;
    }
    int numWays(vector<string>& words, string target) {
        this->target = target;
        totalW = words.size(), wLen = words[0].size(), tLen = target.size();
        dp.resize(wLen + 1, vector<int>(tLen + 1, -1));
        freq.resize(wLen + 1, vector<int> (26, 0));
        for(int i = 0; i < totalW; i++){
            for(int j = 0; j < wLen; j++){
                freq[j][words[i][j] - 'a']++;
            }
        }
        return solve(0, 0);
    }
};