class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left = 0, right = cardPoints.size() - 1;
        int score = 0, best = 0;
        while(left < k) score += cardPoints[left++];
        left--;
        best = score;
        while(left >= 0){
            score += cardPoints[right--] - cardPoints[left--];
            best = max(best, score);
        }
        return best;
    }
};

// Time: O(N), N = Length of the array
// Space: O(1)