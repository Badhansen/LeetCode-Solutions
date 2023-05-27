class Solution {
private:
    vector<int> memo;
    int n;
public:
    int GetScore(int pos, const vector<int>& value) {
        if (pos >= n) {
            return 0;
        }
        int &result = memo[pos];
        if (result != -1) {
            return result;
        }
        result = value[pos] - GetScore(pos + 1, value);
        if (pos + 2 <= n) {
            int stones = value[pos] + value[pos + 1];
            result = max(result, stones - GetScore(pos + 2, value));
        }
        if (pos + 3 <= n) {
            int stones = value[pos] + value[pos + 1] + value[pos + 2];
            result = max(result, stones - GetScore(pos + 3, value));
        }
        return result;
        
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        memo.resize(n + 1, -1);
        int score = GetScore(0, stoneValue);
        return score == 0 ? "Tie" : score > 0 ? "Alice" : "Bob";
    }
};

// Time: O(n)
// Spcae: O(n)