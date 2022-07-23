// @Author: KING-SEN
// 1 last try

class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        int unique_candies = 0;
        unordered_map<int, int> freq;
        int max_unique = 0;
        for (auto c : candies) {
            freq[c]++;
            if (freq[c] == 1) unique_candies++;
        }
        
        if (k == 0) return unique_candies;
        
        for (int i = 0; i < candies.size(); i++) {
            freq[candies[i]]--;
            if (freq[candies[i]] == 0) {
                unique_candies--;
                freq.erase(candies[i]);
            }
            if (i >= k - 1) {
                max_unique = max(max_unique, unique_candies);
                freq[candies[i - k + 1]]++;
                if (freq[candies[i - k + 1]] == 1) {
                    unique_candies++; 
                }
            }
        }
        return max_unique;
    }
};