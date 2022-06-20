// 1 last try

class Solution {
private:
    unordered_map<string, bool> seen;
public:
    string longestWord(vector<string>& words) {
        string answer;
        for(auto word : words){
            seen[word] = true;
        }
        for(auto word : words){
            int count = 0;
            string curr;
            for(auto c : word){
                curr += c;
                if(seen.count(curr)) count++;
                else break;
            }
            if(count == word.size()){
                if(answer.size() == word.size()) answer = min(answer, word);
                if(answer.size() < word.size()) answer = word;
            }
        }
        return answer;
    }
};
// Time: O(N * L), N = length of the array, L = maximum string length
// Space: O(N)