/*
    Given array of strings, group anagrams together (same letters diff order)
    Ex. strs = ["eat","tea","tan","ate","nat","bat"] -> [["bat"],["nat","tan"],["ate","eat","tea"]]

    Count chars, for each string use total char counts (naturally sorted) as key

    Time: O(n x l) -> n = length of strs, l = max length of a string in strs
    Space: O(n x l)
*/

class Solution {
public:
    string GetKey(string src) {
        vector<int> count(26, 0);
        for (int i = 0; i < src.size(); i++) {
            count[src[i] - 'a']++;
        }
        string key = "";
        for (int i = 0; i < 26; i++) {
            key.append(to_string(count[i] + 'a' + i));
        }
        return key;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            string key = GetKey(strs[i]);
            m[key].push_back(strs[i]);
        }
        
        vector<vector<string>> result;
        for (auto it = m.begin(); it != m.end(); it++) {
            result.push_back(it->second);
        }
        return result;
    }
};

/*
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
*/