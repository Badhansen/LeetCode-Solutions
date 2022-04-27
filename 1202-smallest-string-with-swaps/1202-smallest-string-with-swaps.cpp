class Solution {
private:
    vector<vector<int>> edges;
    vector<bool> visit;
public:
    void dfs(int u, string& s, vector<char>& alph, vector<int>& index){
        alph.push_back(s[u]);
        index.push_back(u);
        visit[u] = true;
        for(auto v : edges[u]){
            if(!visit[v]){
                dfs(v, s, alph, index);
            }
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int len = s.size();
        edges.resize(len);
        visit.resize(len, false);
        for(auto pair : pairs){
            int u = pair[0], v = pair[1];
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        for(int i = 0; i < len; i++){
            if(!visit[i]){
                vector<char> alph;
                vector<int> index;
                dfs(i, s, alph, index);
                sort(alph.begin(), alph.end());
                sort(index.begin(), index.end());
                for(int id = 0; id < index.size(); id++){
                    s[index[id]] = alph[id];
                }
            }
        }
        return s;
    }
};