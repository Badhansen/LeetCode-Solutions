class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> results;
        int answer = 0;
        for (auto& s : arr) {
            bitset<26> mask;
            for (auto& c : s) {
                mask.set(c - 'a');
            }
            int count = mask.count();
            if (count != s.size()) continue;
            for (int i = results.size() - 1; i >= 0; i--) {
                auto& bits = results[i];
                if ((bits & mask).any()) continue;
                int total = count + bits.count();
                answer = max(answer, total);
                results.push_back(bits | mask);
            }
            results.push_back(mask);
            answer = max(answer, count);
        }
        return answer;
    }
};

/*
class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        int result = 0;
        for (int i = 0; i < (1 << n); i++) {
            int mask = 0, size = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    size += arr[j].size();
                    for (int index = 0; index < arr[j].size(); index++) {
                        mask |= (1 << (arr[j][index] - 'a'));
                    }
                }
            }
            if (__builtin_popcount(mask) == size) {
                result = max(result, size);
            }
        }
        return result;
    }
};
*/