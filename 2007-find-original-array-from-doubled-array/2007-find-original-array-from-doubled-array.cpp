// Programming Language Used: C++

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2) return {};
        unordered_map<int, int> freq;
        vector<int> original;
        for (auto &num : changed) {
            freq[num]++;
        }
        sort(changed.begin(), changed.end());
        for (auto &num : changed) {
            if (freq[num]) {
                freq[num]--;
                int twice_num = num * 2;
                if (freq[twice_num] > 0) {
                    freq[twice_num]--;
                    original.push_back(num);
                } else {
                    return {};
                }
            }
        }
        return original;
    }
};

// Time Complexity: O(N log N), Here N = Length of the array
// Space Complexity: O(N), Here we use answer and seen for return results and count the occurances of the array elements
