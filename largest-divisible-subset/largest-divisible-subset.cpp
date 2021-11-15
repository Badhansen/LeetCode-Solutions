class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& A) {
        int n = A.size();
        if(n == 0)
          return {};
        sort(A.begin(), A.end());
        vector<int> dp(n, 1);
        vector<int> previous_index(n, -1);
        int max_ind = 0;
        for(int i=1; i<n; i++) {
           for(int j=0; j<i; j++) {
               if(A[i]%A[j]==0 and dp[i] < dp[j] + 1) {
                   dp[i] = dp[j]+1;
                   previous_index[i] = j;
               }
           }
           if(dp[i] > dp[max_ind]) {
               max_ind = i;
           }
        }
        vector<int> answer;
        int t = max_ind;  
        while(t >= 0) {
          answer.push_back(A[t]);
          t = previous_index[t];
        }

        return answer;  
    }
};