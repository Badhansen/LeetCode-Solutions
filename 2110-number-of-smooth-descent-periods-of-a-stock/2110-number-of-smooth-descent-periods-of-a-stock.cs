public class Solution {
    public long GetDescentPeriods(int[] prices) {
        long answer = prices.Length, count = 1, prev = prices[0];
        for(int i = 1; i < prices.Length; i++)
        {
            if(prev - prices[i] == 1)
            {
                count++;
            }
            else
            {
                answer += (count * (count - 1) / 2); 
                count = 1;
            }
            prev = prices[i];
        }
        answer += (count * (count - 1) / 2);
        return answer;
    }
}