class Solution {
public:
    bool IsPossible(vector<int>& candies, long long candy, long long k) {
        if (candy == 0) {
            return true;
        }
        long long piles = 0;
        for (auto &c : candies) {
            piles += (c / candy);
        }
        return piles >= k; 
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long start = 0, end = 1e18, mid, answer = 0;
        while (start <= end) {
            mid = (end - start) / 2 + start;
            if (IsPossible(candies, mid, k)) {
                answer = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return answer;
    }
};