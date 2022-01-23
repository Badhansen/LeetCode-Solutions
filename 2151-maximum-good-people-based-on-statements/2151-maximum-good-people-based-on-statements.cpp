class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int len = statements.size();
        int total = 1 << len, ans = 0;
        for(int t = 0; t < total; t++){
            bool flag = true;
            for(int i = 0; i < len && flag; i++){
                if(t >> i & 1){
                    for(int j = 0; j < len; j++){
                        if(statements[i][j] != 2 && statements[i][j] != (t >> j & 1)){
                            flag = false;
                            break;
                        }
                    }
                }
            }
            if(flag) ans = max(ans, __builtin_popcount(t));
        }
        return ans;
    }
};
