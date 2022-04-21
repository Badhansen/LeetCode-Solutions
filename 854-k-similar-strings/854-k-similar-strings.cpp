class Solution {
private:
    unordered_map<string, int> cache;
public:
    int solve(int pos, string& word1, string& word2){
        if(pos >= word1.size()){
            return 0;
        }
        if(cache.find(word1) != cache.end()){
            return cache[word1];
        }
        int result = INT_MAX - 1;
        if(word1[pos] == word2[pos]){
            return cache[word1] = solve(pos + 1, word1, word2);
        }
        for(int i = pos + 1; i < word1.size(); i++){
            if(word1[i] == word2[pos]){
                swap(word1[i], word1[pos]);
                result = min(result, 1 + solve(pos + 1, word1, word2));
                swap(word1[i], word1[pos]);
            }
        }
        return cache[word1] = result;
    }
    int kSimilarity(string s1, string s2) {
        int answer = solve(0, s1, s2);
        return answer;
    }
};