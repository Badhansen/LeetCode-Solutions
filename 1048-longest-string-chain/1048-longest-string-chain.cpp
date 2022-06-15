class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<string> wlen[17];
        unordered_map<string, int> dist;
        for(auto &word : words){
            wlen[word.size()].push_back(word);
            dist[word] = 1;
        }
        int ans = 1;
        for(int i = 16; i > 0; i--){
            for(auto &word : wlen[i]){
                for(int l = 0; l < word.size(); l++){
                    string nword = word.substr(0, l) + word.substr(l + 1);
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

// Time: O(16 * total word length)
// Space: O(total word length)