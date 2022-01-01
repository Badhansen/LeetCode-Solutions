class Solution {
private:
    vector<vector<int>> dp;
public:
    int rec(vector<int> &numbers, int left, int right){
        if(left + 1 == right)
            return 0;
        if(dp[left][right] > 0)
            return dp[left][right];
        int ans = 0; 
        for(int i = left + 1; i < right; i++){
            ans = max(ans, numbers[left] * numbers[i] * numbers[right] + 
                      rec(numbers, left, i) + rec(numbers, i, right));
        }
        return dp[left][right] = ans;
    }
    int maxCoins(vector<int>& nums) {
        int size = nums.size() + 2;
        
        vector<int> numbers;
        
        numbers.push_back(1);
        numbers.insert(numbers.end(), nums.begin(), nums.end());
        numbers.push_back(1);
        
        dp.resize(size, vector<int>(size, 0));
        
        int answer = rec(numbers, 0, size - 1);
        
        return answer;
    }
};