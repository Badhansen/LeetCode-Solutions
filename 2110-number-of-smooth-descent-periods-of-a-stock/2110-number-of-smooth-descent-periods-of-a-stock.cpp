class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long answer = 0, count = 1, prev = prices[0];
        for(int i = 1; i < prices.size(); i++){
            if(prev - prices[i] == 1){
                count++;
            }
            else{
                answer += (count * (count - 1) / 2);
                count = 1;
            }
            prev = prices[i];
        }
        answer += (count * (count - 1) / 2);
        return answer + prices.size();
    }
};