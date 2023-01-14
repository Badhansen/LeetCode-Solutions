class Solution {
private:
    set<int> graph[26];
    vector<bool> visited;
public:
    int dfs(int src) {
        int m_src = src;
        visited[src] = true;
        for (int dest : graph[src]) {
            if (!visited[dest]) {
                m_src = min(m_src, dfs(dest));
            }
        }
        return m_src;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        for (int i = 0; i < n; i++) {
            graph[s1[i] - 'a'].insert(s2[i] - 'a');
            graph[s2[i] - 'a'].insert(s1[i] - 'a');
        }
        vector<int> ret(26);
        visited.resize(26);
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) visited[j] = false;
            ret[i] = dfs(i);
        }
        string answer;
        for (int i = 0; i < baseStr.size(); i++) {
            answer.push_back('a' + ret[baseStr[i] - 'a']);
        }
        return answer;
    }
};