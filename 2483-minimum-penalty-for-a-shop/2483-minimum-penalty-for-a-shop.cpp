class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> open(n + 1, 0);
        vector<int> close(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            if (customers[i] == 'Y') {
                open[i + 1] = 1;
            } else {
                close[i + 1] = 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            open[i] += open[i - 1];
            close[i] += close[i - 1];
        }
        int loss = open[n], ans = 0;
        for (int i = 0; i <= n; i++) {
            int curr_loss = open[n] - open[i] + close[i];
            //cout << i << " " << curr_loss << endl;
            if (loss > curr_loss) {
                loss = curr_loss;
                ans = i;
            }
        }
        return ans;
    }
};
/*
- Closing the shop at the 0th hour incurs in 1+1+0+1 = 3 penalty.
- Closing the shop at the 1st hour incurs in 0+1+0+1 = 2 penalty.
- Closing the shop at the 2nd hour incurs in 0+0+0+1 = 1 penalty.
- Closing the shop at the 3rd hour incurs in 0+0+1+1 = 2 penalty.
- Closing the shop at the 4th hour incurs in 0+0+1+0 = 1 penalty.
Closing the shop at 2nd or 4th hour gives a minimum penalty. Since 2 is earlier, the optimal closing time is 2.
*/