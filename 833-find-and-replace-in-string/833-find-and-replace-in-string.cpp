class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        map<int, int> index;
        int n = s.size(), k = indices.size(), prev = 0;
        string result;
        
        for(int i = 0; i < k; i++){
            index[indices[i]] = i;
        }
        
        for(int i = 0; i < n; ++i){
            if(index.count(i) && s.substr(i, sources[index[i]].size()) == sources[index[i]]){
                result.append(targets[index[i]]);
                i += sources[index[i]].size() - 1;
            }
            else{
                result.push_back(s[i]);
            }
        }
        
        return result;
    }
};