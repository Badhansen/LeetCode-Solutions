// @Author: KING-SEN

class Solution {
public:
    bool IsPossible(vector<int>& piles, int k, int h) {
        int len = piles.size();
        long long hours = 0;
        for (int i = 0; i < len; i++) {
            hours += (piles[i] / k) + (piles[i] % k != 0 ? 1 : 0);
        }
        return hours <= (1ll * h); 
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1, end = 1e9, answer = 0;
        while (start <= end) {
            int mid = (end - start) / 2 + start;
            if (IsPossible(piles, mid, h)) {
                answer = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return answer;
    }
};