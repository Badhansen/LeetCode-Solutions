// @Author: KING-SEN
// 1 last try

class Solution {
private:
    unordered_map<string, int> wcount;
public:
    int longestPalindrome(vector<string>& words) {
        for(auto &w : words) // O(wLen)
            ++wcount[w];
        int res = 0, center = 0, sz = 2;
        for (auto &[w, cnt] : wcount) { // O(size of wcount)
            auto reversed = string(rbegin(w), rend(w));
            if (w == reversed) {
                res += 2 * (cnt / 2);
                center |= cnt % 2;
            }
            else {
                auto it = wcount.find(reversed);
                if (it != end(wcount))
                    res += min(cnt, it->second);
            }
        }
        return sz * res + (center ? sz : 0);
    }
};

// Time: O(wLen), wLen = word length
// Space: O(wLen)