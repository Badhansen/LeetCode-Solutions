typedef long long LL;

class Solution {
public:
    int minimumLines(vector<vector<int>>& sp) {
        int n = sp.size();
        if(n == 1) return 0;
        sort(sp.begin(), sp.end());
        int ans = 1;
        LL dx, dy, dxx, dyy;
        dx = sp[0][0] - sp[1][0];
        dy = sp[0][1] - sp[1][1];
        for(int i = 2; i < n; i++){
            dxx = sp[i - 1][0] - sp[i][0];
            dyy = sp[i - 1][1] - sp[i][1];
            LL l = 1ll * dx * dyy, r = 1ll * dxx * dy;
            if(l != r){
                dx = dxx;
                dy = dyy;
                ans++;
            }
        }
        return ans;
    }
};