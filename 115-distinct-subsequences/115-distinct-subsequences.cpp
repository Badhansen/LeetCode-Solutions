class Solution {
public:
    
    int dp[1007][1007];
    int solve(int i,int j, string &s, string &t)
    {
        if(j==t.size()) return 1;
        
        if(i==s.size())
        {
            return(j==t.size());
        }
        
        int &ret = dp[i][j];
        
        if(ret!=-1) return ret;
        
        int x = 0 , y = 0;
        if(s[i]==t[j])
            x = solve(i+1,j+1,s,t);
        y = solve(i+1,j,s,t);
        
        ret = x+y;
        return ret;
        
    }
    
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,t);
    }
};