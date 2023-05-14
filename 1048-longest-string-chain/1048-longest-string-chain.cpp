class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [&](const string& a, const string& b){
            return a.size() < b.size();
        });
        unordered_map<string, int> dp;
        int res = 0;
        for (string w : words) {
            for (int i = 0; i < w.length(); i++) {
                string pre = w.substr(0, i) + w.substr(i + 1);
                dp[w] = max(dp[w], dp.find(pre) == dp.end() ? 1 : dp[pre] + 1);
            }
            res = max(res, dp[w]);
        }
        return res;
    }
};
/*
/*
Let N be the number of words in the list and LL be the maximum possible length of a word.

    Time complexity: O(N⋅(log⁡N+L^2))

    Sorting a list of size NN takes O(Nlog⁡N) time. Next, we use two for loops in which the outer loop runs for O(N) iterations and the inner loop runs for O(L^2) iterations in the worst case scenario. The first LL is for the inner loop and the second LL is for creating each predecessor. Thus the overall time complexity is O(NlogN+(N⋅L^2)) which equals O(N⋅(log⁡N+L^2)).

    Space complexity: O(N).

    We use a map to store the length of the longest sequence formed with each of the N words as the end word.
*/

// Time O(NlogN) for sorting,
// Time O(NSS) for the for loop, where the second S refers to the string generation and S <= 16.
// Space O(NS)

/*
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
*/