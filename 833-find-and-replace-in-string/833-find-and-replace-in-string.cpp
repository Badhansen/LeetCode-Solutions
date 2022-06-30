class Solution {
private:
    map<int, int> index;
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
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
    ~Solution(){
        index.clear();
    }
};
/*
string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
    vector<pair<int, int>> sorted;
    for (int i = 0 ; i < indexes.size(); i++)
        sorted.push_back({indexes[i], i});
    sort(sorted.rbegin(), sorted.rend());
    for (auto ind : sorted) {
        int i = ind.first;
        string s = sources[ind.second], t = targets[ind.second];
        if (S.substr(i, s.length()) == s)
            S = S.substr(0, i) + t + S.substr(i + s.length());
    }
    return S;
}
*/