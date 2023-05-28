// @Author: KING-SEN

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts -1) return 1.0;
        vector<double> dp(n + maxPts + 1);
        double prob=(double)1/(double)maxPts;
        double sum=0.0;
        int j=k-1+maxPts;
        for(int i=n;i>=0;i--) {
            if(i>=k) {
                dp[i]=1.0;
            }
            else {
                dp[i]+=prob*sum;
                if(j-i==maxPts) {
                    sum-=dp[j--];
                }
            }
            sum+=dp[i];
        }
        return dp[0];
    }
};