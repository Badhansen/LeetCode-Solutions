class Solution {
public:
    vector<int> GetKey(string& src) {
        vector<int> count(26, 0);
        for (auto c : src) {
            count[c - 'a']++;
        }
        return count;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        map<vector<int>, vector<string>> seen;
        int count = 0;
        for(auto &str : strs){
            seen[GetKey(str)].push_back(str);
        }
        for (auto [key, value] : seen) {
            answer.push_back(value);
        }
        return answer;
    }
};