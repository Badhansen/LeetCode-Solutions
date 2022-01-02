class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() < 10)
            return {};
        unordered_map<string, int> count;
        vector<string> ans;
        string res;
        for(int i = 0; i <= s.size() - 10; i++){
            res = s.substr(i, 10);
            count[res]++;
        }
        for(auto &[key, val] : count){
            if(val > 1)
                ans.push_back(key);
        }
        return ans;
    }
};