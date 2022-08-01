class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> freq(205, 0);
        int max_freq = 0;
        for (auto n : nums) {
            freq[n + 100]++;
            max_freq = max(max_freq, freq[n + 100]);
        }
        vector<int> ans;
        for (int f = 1; f <= max_freq; f++) {
            for (int i = 100; i >= -100; i--) {
                if (freq[i + 100] == f) {
                    for (int j = 0; j < f; j++) {
                        ans.push_back(i);
                    }
                }
            }
        }
        return ans;
    }
};