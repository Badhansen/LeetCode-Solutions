class Solution {
public:
    int minDeletions(string s) {
        int count[26] = {0}, ans = 0;
        set<int> seen;
        for(auto c : s){
            count[c - 'a']++;
        }
        for(int c = 0; c < 26; c++){
            int freq = count[c];
            while(freq > 0 && !seen.insert(freq).second){
                freq--;
                ans++;
            }
        }
        return ans;
    }
};

// Time: O(L), L = Word length
// Space: O(1)