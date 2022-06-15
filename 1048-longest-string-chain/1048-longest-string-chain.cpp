class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<string> wlen[17];
        unordered_map<string, int> dist;
        for(auto &word : words){ // O(N)
            wlen[word.size()].push_back(word);
            dist[word] = 1;
        }
        int ans = 1;
        for(int i = 16; i > 0; i--){ // O(16)
            for(auto &word : wlen[i]){ // O(N)
                for(int l = 0; l < word.size(); l++){ // O(L)
                    string nword = word.substr(0, l) + word.substr(l + 1); // O(L)
                    if(dist.count(nword)){
                        dist[nword] = max(dist[nword], dist[word] + 1);
                        ans = max(ans, dist[nword]);
                    }
                }
            }
        }
        return ans;
    }
};

// Time: O(N * L ^ 2)
// Space: O(N)