// @Author: KING-SEN
// 1 last try

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<pair<int, int>> next[26];
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            next[words[i][0] - 'a'].push_back({i, 0});
        }
        for (auto c : s) {
            vector<pair<int, int>> curr = next[c - 'a'];
            next[c - 'a'].clear();
            for (auto [index, len] : curr) {
                if (words[index][len] == c) {
                    len++;
                    if(len == words[index].size()) {
                        ans++;
                    } else {
                        next[words[index][len] - 'a'].push_back({index, len});
                    }
                }
            }
        }
        return ans;
    }
};

// Time: O(L + SUM(words length))
// Space: O(SUM(words length))

/*
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<pair<string, int>> next[26];
        int ans = 0;
        for(auto &word : words){ // O(W)
            next[word[0] - 'a'].push_back({word, 0});
        }
        for(auto &c : s){ // O(L)
            vector<pair<string, int>> curr = next[c - 'a'];
            next[c - 'a'].clear();
            for(auto &item : curr){ // O(SUM(words lenght))
                item.second++;
                if(item.first.size() == item.second) ans++;
                else{
                    int nextPtr = item.first[item.second] - 'a';
                    next[nextPtr].push_back({item.first, item.second});
                }
            }
        }
        return ans;
    }
};

// Time: O(L + SUM(words length))
// Space: O(SUM(words length))
*/