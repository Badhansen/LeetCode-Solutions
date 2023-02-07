class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, n = fruits.size();
        unordered_map<int, int> seen;
        int ans = 0;
        for (int right = 0; right < n; right++) {
            seen[fruits[right]]++;
            while (seen.size() > 2) {
                while (seen[fruits[left]] > 0 && left < right) {
                    seen[fruits[left]]--;
                    if (seen[fruits[left]] == 0) {
                        seen.erase(fruits[left++]);
                        break;
                    }
                    left++;
                }
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};