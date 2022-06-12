class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> seen(ideas.begin(), ideas.end());
        long long res = 0;
        long long count[26][26] = {0};
        for(auto idea : ideas){
            string st = idea;
            for(char i = 'a'; i <= 'z'; i++){
                idea[0] = i;
                count[st[0] - 'a'][i - 'a'] += seen.count(idea) == 0;
            }
        }
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                res += count[i][j] * count[j][i];
            }
        }
        return res;
    }
};

// Time: O(N * 26)
// Space: O(N)